#include <bits/stdc++.h>
using namespace std;

constexpr int GROUPS = 4;
constexpr int SUBJECTS = 4;

vector<int> rules[GROUPS];

struct audience {
    int ind;
    int scores[SUBJECTS];
};

class show {
   public:
    void add_audience(audience &audi, string &name, int group);
    void add_rule(string &s, int group);
    void sort_all();
    void print_members(int group);

   private:
    vector<audience> groups[GROUPS];
    vector<int> rules[GROUPS];
    vector<string> name_table;
    int mode;

    void max_heapify(int i);
    void build_max_heap();
};

istream &operator>>(istream &stream, audience &audi) {
    for (int i = 0; i < SUBJECTS; i++) stream >> audi.scores[i];
    return stream;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    show s;

    for (int i = 0; i < GROUPS; i++) {
        string str;
        cin >> str;
        s.add_rule(str, i);
    }

    for (int i = 0; i < n; i++) {
        audience audi;
        string name;
        cin >> name >> audi;
        int group =
            max_element(audi.scores, audi.scores + SUBJECTS) - audi.scores;
        s.add_audience(audi, name, group);
    }

    s.sort_all();

    for (int i = 0; i < GROUPS; i++) s.print_members(i);

    return 0;
}

void show::add_audience(audience &audi, string &name, int group) {
    this->groups[group].push_back(audi);
    this->name_table.push_back(name);
}

void show::max_heapify(int i) {}

void build_max_heap(int i) { build_max_heap() }

void show::print_members(int group) {
    char letter = char('A' + group);
    if (this->groups[group].size() == 0) {
        cout << "Group " << letter << ": No Audience" << '\n';
        return;
    }
    cout << "Group " << letter << ":\n";
    for (audience &audi : groups[group])
        cout << this->name_table[audi.ind] << '\n';
}

void show::add_rule(string &s, int group) {
    for (char &c : s) {
        switch (c) {
            case 'H':
                rules[group].push_back(0);
                break;
            case 'W':
                rules[group].push_back(1);
                break;
            case 'I':
                rules[group].push_back(2);
                break;
            case 'E':
                rules[group].push_back(3);
                break;

            default:
                break;
        }
    }
}