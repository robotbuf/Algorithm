#include <iostream>
#include <set>
#include <string>

using namespace std;


struct Compare {
    bool operator()(const string& a, const string& b) const {
        if (a.length() == b.length())
            return a < b;
        return a.length() < b.length();
    }
};

int main() {
    int n;
    cin >> n;

    set<string, Compare> s;

    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        s.insert(str);
    }

    for (const auto& word : s) {
        cout << word << '\n';
    }

    return 0;
}
