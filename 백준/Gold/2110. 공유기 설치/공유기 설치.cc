#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
long long arr[200001];

bool canInstall(long long dist) {
    int count = 1;
    long long last = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last >= dist) {
            count++;
            last = arr[i];
        }
    }

    return count >= c;
}

int main() {
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    long long left = 1;
    long long right = arr[n - 1] - arr[0];
    long long result = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canInstall(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result;
    return 0;
}
