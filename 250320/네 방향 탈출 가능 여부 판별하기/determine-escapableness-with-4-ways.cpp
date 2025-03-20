#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int a[100][100];
bool visited[100][100];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};


bool isIn(int x, int y) {
    return (0<=x && 0<=y && x<n && y<m);
}


bool bfs() {
    queue<pair<int, int>> q;
    q.push({0,0});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        visited[x][y] = true;
        
        if(x == n-1 && y == m-1) {
            return true;
        }
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isIn(nx, ny)) {
                if(a[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        
    }
    
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    bool res = bfs();
    cout<<res;

    return 0;
}
