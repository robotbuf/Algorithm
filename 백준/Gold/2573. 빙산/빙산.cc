#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int arr[301][301];
bool visited[301][301] = {false};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int ans = 0;

bool isIn(int x, int y) {
    return (0<=x && x<n && 0<=y && y<m);
}


void melting() {
    
    queue<tuple<int,int,int>> q;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] > 0) {
                int cnt = 0;
                for(int d=0; d<4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    
                    if(isIn(nx,ny) && arr[nx][ny] == 0) {
                        cnt++;
                    }
                }
                q.push({i,j,cnt});
            }
        }
    }
    
    while(!q.empty()) {
        auto [x,y,ice] = q.front();
        q.pop();
        
        arr[x][y] -= ice;
        if(arr[x][y] < 0) arr[x][y] = 0;
    }
}

void bfs(int r, int c) {
    
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = true;
    
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isIn(nx, ny)) {
                if(arr[nx][ny] > 0 && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
     
    
}





int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    while(true) {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!visited[i][j] && arr[i][j] > 0) {
                    bfs(i,j);
                    cnt++;
                }
        if(cnt == 0) {
            ans = 0;
            break;
        }
        if(cnt >= 2) break;
        melting();
        ans++;
    }
    cout << ans << '\n';
}
