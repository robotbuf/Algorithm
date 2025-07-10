#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


int main() {
    int n;
    cin>>n;
    
    int arr[1001];
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    
    int ans = 0;
    
    int tmp = 0;
    
    
    for(int i=0; i<n; i++) {
        tmp += arr[i];
        ans += tmp;
    }
    
    
    cout<<ans;
    
    
    
    
    
    
}
