#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

bool checkRow(int x) {
    if (n == 0) return false;

    int cnt = 1;
    int now = grid[x][0];

    for (int i = 1; i < n; i++) {
        if (now == grid[x][i]) {
            cnt++;
        } else {
            cnt = 1;
            now = grid[x][i];
        }

        if (cnt >= m) {
            return true;
        }
    }
    return false;
}

bool checkCol(int y) {
    if (n == 0) return false;

    int cnt = 1;
    int now = grid[0][y];

    for (int i = 1; i < n; i++) {
        if (now == grid[i][y]) {
            cnt++;
        } else {
            cnt = 1;
            now = grid[i][y];
        }
        if (cnt >= m) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
        if (checkRow(i))
            ans++;

    for (int j = 0; j < n; j++)
        if (checkCol(j))
            ans++;

    cout << ans;

    return 0;
}
