#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
char arr[51][51];
int ans = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool isIn(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int bfs(int sx, int sy) {
    queue<tuple<int, int, int>> q;
    bool visited[51][51] = {false};
    
    q.push({sx, sy, 0});
    visited[sx][sy] = true;
    int local_max = 0;
    
    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();
        
        local_max = max(local_max, cnt);
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isIn(nx, ny) && arr[nx][ny] == 'L' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, cnt + 1});
            }
        }
    }
    
    return local_max;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'L') {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    
    cout << ans;
}