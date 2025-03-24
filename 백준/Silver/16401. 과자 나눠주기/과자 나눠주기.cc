#include <iostream>
#include <algorithm>

using namespace std;


int n,m;

long long arr[1000001];

int distribute(long long target) {
    int cnt = 0;
    
    for(int i=0; i<n; i++) {
        
        cnt += arr[i] / target;
    }
    
    return cnt;
    
}

int main() {
    cin>>m>>n;
    long long ans = 0;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    long long left = 1;
    long long right = arr[n-1];
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        int res = distribute(mid);
        
        if(res >= m) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    
    
    cout<<ans;
    
    
    
    
}
