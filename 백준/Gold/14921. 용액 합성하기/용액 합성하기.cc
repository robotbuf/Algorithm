#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;


int n;
long long arr[100001];
long long res = LONG_LONG_MAX;
long long ans;


int main() {
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    
    long long left = 0;
    long long right = n - 1;
    
    
    
    while(left < right) {
        long long value = arr[left] + arr[right];

        if(abs(value) < res) {
            res = abs(value);
            ans = value;
        }

        if(value < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout<<ans;
    
    
}
