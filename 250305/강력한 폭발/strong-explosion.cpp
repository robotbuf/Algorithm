#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<int>> temp_grid;

// 폭탄이 영향을 미치는 패턴
vector<vector<pair<int, int>>> bomb_patterns = {
    {{0, 0}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}}, // 세로형
    {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}}, // 십자형
    {{0, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}} // 대각선형
};

int max_destroyed_area = 0;

// 특정 위치에서 폭탄을 터뜨렸을 때 영향을 받는 영역 계산
int apply_bomb(int x, int y, vector<pair<int, int>> pattern) {
    int count = 0;
    for (int i = 0; i < pattern.size(); i++) {
        int nx = x + pattern[i].first, ny = y + pattern[i].second;
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && temp_grid[nx][ny] == 0) {
            temp_grid[nx][ny] = 1; // 초토화 표시
            count++;
        }
    }
    return count;
}

// 백트래킹으로 최적의 폭탄 배치 찾기
void find_best_bombing(int index, int destroyed) {
    if (index >= N * N) {
        if (destroyed > max_destroyed_area) {
            max_destroyed_area = destroyed;
        }
        return;
    }
    
    int x = index / N, y = index % N;
    
    if (grid[x][y] == 1) { // 폭탄을 놓을 수 있는 위치라면
        for (int i = 0; i < bomb_patterns.size(); i++) {
            vector<vector<int>> backup = temp_grid; // 원래 상태 저장
            int affected = apply_bomb(x, y, bomb_patterns[i]);
            find_best_bombing(index + 1, destroyed + affected);
            temp_grid = backup; // 원래 상태로 복구
        }
    } else {
        find_best_bombing(index + 1, destroyed);
    }
}

int main() {
    cin >> N;
    grid = vector<vector<int>>(N, vector<int>(N));
    temp_grid = vector<vector<int>>(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    find_best_bombing(0, 0);
    cout << max_destroyed_area << endl;
    return 0;
}
