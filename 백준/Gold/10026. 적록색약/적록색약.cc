#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;


int n;
char arr[101][101];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int normal = 0;
int blind = 0;

bool visited[101][101] = {false};

bool isIn(int x, int y) {
    return (0<=x && x<n && 0<=y && y<n);
}


void bfs(int r, int c, char target) {
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;
    
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isIn(nx, ny) && !visited[nx][ny]) {
                if(arr[nx][ny] == target) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
void blind_bfs(int r, int c, char target) {
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isIn(nx, ny) && !visited[nx][ny]) {
                
                if ((target == 'R' || target == 'G') && (arr[nx][ny] == 'R' || arr[nx][ny] == 'G')) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
                
                else if (target == 'B' && arr[nx][ny] == 'B') {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}


int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

  
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (!visited[i][j]) {
                bfs(i, j, arr[i][j]);
                normal++;
            }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            visited[i][j] = false;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (!visited[i][j]) {
                blind_bfs(i, j, arr[i][j]);
                blind++;
            }

    cout << normal << " " << blind << '\n';
}
