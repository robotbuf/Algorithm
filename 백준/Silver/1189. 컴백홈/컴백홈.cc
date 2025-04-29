#include <iostream>
using namespace std;

char map[6][6];
bool visited[6][6];
int r, c, k;
int ans = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt) {
    if (cnt == k) {
        if (x == 0 && y == c-1) {
            ans++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if (!visited[nx][ny] && map[nx][ny] != 'T') {
                visited[nx][ny] = true;
                dfs(nx, ny, cnt + 1);
                visited[nx][ny] = false;
            }
        }
    }
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    visited[r-1][0] = true;
    dfs(r-1, 0, 1);

    cout << ans;
}

    
