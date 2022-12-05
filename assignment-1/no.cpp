#include <bits/stdc++.h>
using namespace std;

constexpr int GROUPS = 4;
constexpr int SUBJECTS = 4;

struct audience {
    int ind;
    int scores[SUBJECTS];
};

vector<audience> groups[GROUPS];
vector<int> rules[GROUPS];
vector<string> name_table;
int mode;

void add_audience(audience &audi, string &name, int group);
void add_rule(string &s, int group);
void sort_all();
void print_members(int group);
bool cmp(audience &a, audience &b);

istream &operator>>(istream &stream, audience &audi) {
    for (int i = 0; i < SUBJECTS; i++) stream >> audi.scores[i];
    return stream;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < GROUPS; i++) {
        string str;
        cin >> str;
        add_rule(str, i);
    }

    for (int i = 0; i < n; i++) {
        audience audi;
        string name;
        cin >> name >> audi;
        int group =
            max_element(audi.scores, audi.scores + SUBJECTS) - audi.scores;
        add_audience(audi, name, group);
    }

    sort_all();

    for (int i = 0; i < GROUPS; i++) print_members(i);

    return 0;
}

void add_audience(audience &audi, string &name, int group) {
    audi.ind = name_table.size();
    groups[group].push_back(audi);
    name_table.push_back(name);
}

void print_members(int group) {
    char letter = char('A' + group);
    if (groups[group].size() == 0) {
        cout << "Group " << letter << ": No Audience" << '\n';
        return;
    }
    cout << "Group " << letter << ":\n";
    for (audience &audi : groups[group]) {
        cout << name_table[audi.ind] << '\n';
    }
}

bool cmp(audience &a, audience &b) {
    for (int i = 0; i < SUBJECTS; i++) {
        int subj = rules[mode][i];
        if (a.scores[subj] == b.scores[subj]) continue;
        return a.scores[subj] > b.scores[subj];
    }
    return name_table[a.ind] < name_table[b.ind];
}

void sort_all() {
    for (int i = 0; i < GROUPS; i++) {
        mode = i;
        sort(groups[i].begin(), groups[i].end(), cmp);
    }
}

void add_rule(string &s, int group) {
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