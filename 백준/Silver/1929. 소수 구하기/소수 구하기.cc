#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    bool check[1000001] = { false };

    for (int i = 2; i * i <= n; i++) {
        if (!check[i]) {
            for (int k = i * i; k <= n; k += i) {
                check[k] = true;
            }
        }
    }

   
    for (int i = max(m, 2); i <= n; i++) {
        if (!check[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}
