#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;


int n,m;
int arr[501][501];
int picture = 0;
int wide = 0;
bool visited[501][501] = {false};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool isIn(int x, int y) {
    return (0<=x && x<n && 0<=y && y<m);
}


int bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = true;
    int cnt = 1;
    
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!visited[nx][ny] && isIn(nx,ny) && arr[nx][ny] == 1) {
                q.push({nx,ny});
                visited[nx][ny] = true;
                cnt += 1;
            }
            
        }
        
        
    }
    return cnt;
    
}


int main() {
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j] == false && arr[i][j] == 1) {
                int res = bfs(i,j);
                wide = max(wide,res);
                picture += 1;
            }
        }
    }
    
    cout<<picture<<"\n";
    cout<<wide<<"\n";
    
    
    
    
    
    
}
