#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];
bool visited[25][25] = {false};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

vector<int> res; // 각 섬의 크기 저장

bool isIn(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int dfs(int x, int y) {
    visited[x][y] = true;
    int size = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isIn(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
            size += dfs(nx, ny);
        }
    }
    return size;
}

int main() {
    int islandCount = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                int size = dfs(i, j);
                res.push_back(size);
                islandCount++;
            }
        }
    }

   
    cout << islandCount << "\n";
    sort(res.begin(), res.end());
    for (int size : res) {
        cout << size << "\n";
    }

    return 0;
}
