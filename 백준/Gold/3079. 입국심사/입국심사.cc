#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long m;

long long arr[100001];

int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    long long left = 1;
    long long right = arr[n-1] * m;
    long long answer = right;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += mid / arr[i];
            if (cnt >= m) break;
        }

        if (cnt >= m) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer;
}

    