#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int arr[100001];
int prefix_sum[100001];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    prefix_sum[0] = 0;
    for(int i=1; i<=n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
    }
    
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        cout<<prefix_sum[y] - prefix_sum[x-1]<<"\n";
    }
    
}
