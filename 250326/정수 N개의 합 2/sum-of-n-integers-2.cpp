#include <iostream>
using namespace std;

int n, k;
int arr[100001];
int prefix_sum[100001];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }

    int max_sum = prefix_sum[k] - prefix_sum[0];

    for (int i = 1; i <= n - k; i++) {
        int sum_k = prefix_sum[i + k] - prefix_sum[i];
        if (sum_k > max_sum) {
            max_sum = sum_k;
        }
    }

    cout << max_sum << endl;

    return 0;
}