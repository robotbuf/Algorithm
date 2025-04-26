#include <iostream>
#include <algorithm>

using namespace std;

int k, n;
int arr[10001];
long long ans = -1;

int main() {
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + k);

    long long left = 1;
    long long right = arr[k-1];

    while (left <= right) {
        long long  mid = (left + right) / 2;
        int cnt = 0;
        
        for (int i = 0; i < k; i++) {
            cnt += (arr[i] / mid);
        }
        
        if (cnt >= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans;
}
    