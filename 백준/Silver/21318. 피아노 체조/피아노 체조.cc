#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    long long arr[100001];
    cin>>n;
    for(long long i=0; i<n; i++) {
        cin>>arr[i];
    }
    long long prefix_sum[100001] ={0};
    for(long long i=0; i<n; i++) {
        if(arr[i] > arr[i+1]) {
            prefix_sum[i+1] = prefix_sum[i] + 1;
        } else {
            prefix_sum[i+1] = prefix_sum[i];
        }
    }
    long long q;
    cin>>q;
    
    for(long long i=0; i<q; i++) {
        long long a,b;
        cin>>a>>b;
        
        cout<<prefix_sum[b-1] - prefix_sum[a-1]<<"\n";
    }
    
    
    
    
    
}
