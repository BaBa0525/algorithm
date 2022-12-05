#include <bits/stdc++.h>
using namespace std;

struct node {
    int left, right;
};

class FoodChain {
   public:
    FoodChain(int n);
    void add_population(int p);
    void add_inorder(int in);
    void add_postorder(int post);
    int construct_tree(int root);
    int calculate_strange();

   private:
    int n;
    vector<node> tree;
    vector<int> population, inorder, postorder, pos;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    FoodChain chain(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        chain.add_population(a);
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        chain.add_inorder(a);
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        chain.add_postorder(a);
    }

    chain.construct_tree(-1);
    cout << chain.calculate_strange() << '\n';

    return 0;
}

#pragma region defs

FoodChain::FoodChain(int n) {
    this->n = n;
    this->population.reserve(n + 1);
    this->population.push_back(0);
    this->inorder.reserve(n);
    this->postorder.reserve(n);
    this->tree.resize(n + 1);
}

void FoodChain::add_population(int p) { this->population.push_back(p); }

void FoodChain::add_inorder(int in) { this->inorder.push_back(in); }

void FoodChain::add_postorder(int post) { this->postorder.push_back(post); }

int FoodChain::construct_tree(int stop) {
    if (this->inorder.size() == 0 || this->inorder.back() == stop) return 0;

    int root = this->postorder.back();
    this->postorder.pop_back();

    this->tree[root].right = construct_tree(root);
    this->inorder.pop_back();
    this->tree[root].left = construct_tree(stop);

    return root;
}

int FoodChain::calculate_strange() {
    int strange_count = 0;
    for (int i = 1; i < this->n + 1; i++) {
        int left_pop = population[tree[i].left];
        int right_pop = population[tree[i].right];

        if (population[i] < left_pop) strange_count++;
        if (population[i] < right_pop) strange_count++;
    }

    return strange_count;
}

#pragma endregion