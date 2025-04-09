#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[100001];


int main() {
    cin.tie(NULL);
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    int prefix_sum[n+1];
    prefix_sum[0] = 0;
    
    for(int i=1; i<=n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
    }
    
    int m;
    cin>>m;
    
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        cout<<prefix_sum[y] - prefix_sum[x-1]<<"\n";
    }
}
