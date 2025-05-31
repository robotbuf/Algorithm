#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long arr[1000001];
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long max_price = 0;
        long long profit = 0;

        // 뒤에서부터 순회
        for (long long i = n - 1; i >= 0; i--) {
            if (arr[i] > max_price) {
                max_price = arr[i];
            } else {
                profit += max_price - arr[i];
            }
        }

        cout << profit << '\n';
    }
}

