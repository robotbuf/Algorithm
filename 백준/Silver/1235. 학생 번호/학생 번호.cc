#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int len = arr[0].size();
    for (int k = 1; k <= len; k++) {
        set<string> seen;
        for (int i = 0; i < n; i++) {
            string suffix = arr[i].substr(len - k);
            seen.insert(suffix);
        }
        if (seen.size() == n) {
            cout << k << '\n';
            return 0;
        }
    }
}
