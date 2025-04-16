#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;


int n,k;
int ans;
int main() {
    
    cin>>n>>k;
    queue<pair<int,int>> q;
    int visited[100001] = {0};
    
    q.push({n,0});
    visited[n] = 1;
    
    while(!q.empty()) {
        auto [coor,cnt] = q.front();
        q.pop();
        
        if(coor == k) {
            ans = cnt;
            break;
        }
        
        for(int i=0; i<3; i++) {
            int nc;
            if(i == 0) {
                nc = coor + 1;
            } else if(i==1) {
                nc = coor - 1;
            } else {
                nc = coor * 2;
                
            }
            if(nc >= 0 && nc <= 100000 && visited[nc] == 0) {
                q.push({nc,cnt+1});
                visited[nc] = 1;
            }
        }
        
    }
    
    
    cout<<ans;
    
    
    
}
