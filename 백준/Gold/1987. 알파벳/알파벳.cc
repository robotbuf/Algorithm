#include <iostream>
using namespace std;

int R, C;
char arr[21][21];
bool visited[26]; // A-Z까지 알파벳 방문 여부
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int maxDepth = 0;

bool isIn(int x, int y) {
    return (0 <= x && x < R && 0 <= y && y < C);
}

void dfs(int x, int y, int depth) {
    maxDepth = max(maxDepth, depth);
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isIn(nx, ny)) {
            int idx = arr[nx][ny] - 'A';
            if (!visited[idx]) {
                visited[idx] = true;
                dfs(nx, ny, depth + 1);
                visited[idx] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    visited[arr[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << maxDepth << '\n';
    return 0;
}
