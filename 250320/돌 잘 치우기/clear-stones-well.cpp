#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];

vector<pair<int, int>> rock;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isIn(int x, int y) {
    return (0<=x && 0<=y && x<n && y<n);
}


int bfs(vector<int> li, int x, int y) {
    queue<pair<int,int>> q;
    bool visited[100][100] = {false};
    
    int copyed[100][100];
    memcpy(copyed,grid,sizeof(grid));
    
    int cnt = 0;
    
//    for(int i=0; i<li.size(); i++) {
//        cout<<li[i]<< " ";
//    }
//    cout<<"\n";
    
    //사전작업
    for(int i=0; i<li.size(); i++) {
        int x = rock[li[i]].first;
        int y = rock[li[i]].second;
        
        copyed[x][y] = 0;
    }
    
    q.push({x,y});
    visited[x][y] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        cnt++;
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isIn(nx,ny) && !visited[nx][ny]) {
                if(copyed[nx][ny] == 0) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
            
        }
        
        
    }
    
    return cnt;
}


vector<int> rs;


int ans = 0;
//bool check[100] = {false};
void backtrack(int u) {
    if(rs.size() == m) {
        for(int i=0; i<k; i++) {
            ans = max(ans,bfs(rs, r[i], c[i]));
        }
        return;
    }
    
    for(int i=u; i<rock.size(); i++) {
        
        
        rs.push_back(i);
        backtrack(i+1);
        rs.pop_back();
        
    }
}


int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }
    
    //돌 위치 찾자
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 1) {
                rock.push_back({i,j});
            }
        }
    }

    // Please write your code here.
    
    backtrack(0);
    
    cout<<ans;

    return 0;
}
