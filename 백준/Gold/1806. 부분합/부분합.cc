#include <iostream>
using namespace std;

int arr[100001];

int main() {
    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0, sum = 0;
    int min_len = n + 1;

    while (true) {
        if (sum >= s) {
            min_len = min(min_len, end - start);
            sum -= arr[start++];
        } else if (end == n) {
            break;
        } else {
            sum += arr[end++];
        }
    }

    if (min_len == n + 1)
        cout << 0 << '\n';
    else
        cout << min_len << '\n';

    return 0;
}
