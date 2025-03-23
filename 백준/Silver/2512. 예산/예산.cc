//
#include <iostream>
#include <algorithm>

using namespace std;


long long n;
long long m;
int arr[10001];

long long ans = 0;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cin>>m;
    
    sort(arr,arr+n);
    
    long left = 0;
    long right = arr[n-1];
    
    while(left <= right) {
        long long  mid = (left + right) / 2;
        
        long long budget = 0;
        
        for(int i=0; i<n; i++) {
            if(arr[i] <= mid) {
                budget += arr[i];
            } else {
                budget += mid;
            }
        }
        
        
        if(budget <= m) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout<<ans;
    
    
}