#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int n;
int digits[3] = {1, 2, 3};
vector<int> rs;
long long ans = LLONG_MAX;
bool found = false;

bool isGood(const vector<int>& seq) {
    long long len = seq.size();
    for (int i = 1; i <= len / 2; ++i) {
        bool bad = true;
        for (int j = 0; j < i; ++j) {
            if (seq[len - 1 - j] != seq[len - 1 - i - j]) {
                bad = false;
                break;
            }
        }
        if (bad) return false; 
    }
    return true;
}

void backtrack() {
    if (found) return;

    if (!isGood(rs)) return;

    if (rs.size() == n) {
        string s;
        for (int num : rs) {
            s += to_string(num);
        }
        cout << s << endl;
        found = true;
        return;
    }

    for (int i = 0; i < 3; ++i) {
        rs.push_back(digits[i]);
        backtrack();
        rs.pop_back();
    }
}

int main() {
    cin >> n;
    backtrack();
    return 0;
}
