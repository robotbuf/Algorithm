#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int arr1[100000];
int arr2[100000];

priority_queue<tuple<int,int,int>> q;

vector<int> rs;


void find() {
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int x = arr1[i];
            int y = arr2[j];
            
            q.push({-(x+y),-x,-y});
        }
    }
}



int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    
    find();
    
    for(int i=0; i<k-1; i++) {
        q.pop();
    }
    
    auto [sum,x,y] = q.top();
    cout<<-(sum);
    

    return 0;
}
