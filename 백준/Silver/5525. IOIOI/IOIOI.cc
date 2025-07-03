#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int ans = 0;
    int cnt = 0;

    for (int i = 1; i < m - 1; ) {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            cnt++;
            if (cnt == n) {
                ans++;
                cnt--;
            }
            i += 2;
        } else {
            cnt = 0;
            i++;
        }
    }

    cout << ans;
    return 0;
}
