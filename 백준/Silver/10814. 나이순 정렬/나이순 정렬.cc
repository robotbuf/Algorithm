#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


struct cmp {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

int main() {
    int n;
    cin >> n;

    map<int, vector<string>, cmp> members;

    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        members[age].push_back(name);
    }

    for (auto it = members.begin(); it != members.end(); ++it) {
        int age = it->first;
        const vector<string>& names = it->second;

        for (int i = 0; i < names.size(); i++) {
            cout << age << " " << names[i] << '\n';
        }
    }

    return 0;
}
