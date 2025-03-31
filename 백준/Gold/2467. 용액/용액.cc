#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int n;
long long arr[100001];

long long l;
long long r;

long long cmp = LLONG_MAX;

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int left = 0;
    int right = n - 1;
    
    while(left < right) {
        long long sum = arr[left] + arr[right];
        long long comp = abs(sum);

        if (cmp > comp) {
            cmp = comp;
            l = arr[left];
            r = arr[right];
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << l << " " << r;
}
