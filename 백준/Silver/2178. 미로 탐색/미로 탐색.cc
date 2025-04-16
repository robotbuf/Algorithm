#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101] = {false};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isIn(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int bfs(int x, int y) {
    queue<tuple<int, int, int>> q;
    q.push({x, y, 1});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isIn(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny, cnt + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            arr[i][j] = ch - '0';
        }
    }

    int ans = bfs(0, 0);
    cout << ans;

    return 0;
}
