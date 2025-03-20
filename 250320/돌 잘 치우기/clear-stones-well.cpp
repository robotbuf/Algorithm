#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
int grid[100][100];  // 원본 격자
int r[10], c[10];    // 시작점 위치 (최대 8개)

// 돌의 위치를 저장하는 벡터
vector<pair<int, int>> rock;
vector<int> rs;  // 제거할 돌의 인덱스 저장

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 좌표가 격자 내부에 있는지 확인
bool isIn(int x, int y) {
    return (0 <= x && 0 <= y && x < n && y < n);
}

// ✅ BFS 최적화 (격자 복사 없이 직접 돌을 제거 & 복구)
int bfs() {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    int cnt = 0;

    // 모든 시작점을 큐에 추가하고 방문 체크
    for (int i = 0; i < k; i++) {
        q.emplace(r[i], c[i]);
        visited[r[i]][c[i]] = true;
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        cnt++; // 방문한 칸 수 증가

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isIn(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 0) {
                q.emplace(nx, ny);
                visited[nx][ny] = true;
            }
        }
    }

    return cnt; // 방문 가능한 칸 개수 반환
}

// ✅ 백트래킹 최적화 (돌을 직접 제거 & 복구)
int ans = 0;
void backtrack(int start) {
    if (rs.size() == m) { // M개의 돌을 제거했을 경우
        ans = max(ans, bfs()); // BFS 실행 후 최대 방문 가능한 칸 수 갱신
        return;
    }

    for (int i = start; i < rock.size(); i++) {
        // 1. 돌을 없앰
        int x = rock[i].first;
        int y = rock[i].second;
        grid[x][y] = 0;

        // 2. 백트래킹 수행
        rs.push_back(i);
        backtrack(i + 1);
        rs.pop_back();

        // 3. 원상복구
        grid[x][y] = 1;
    }
}

int main() {
    cin >> n >> k >> m;

    // 격자 입력 받기
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    // 시작점 좌표 입력 받기
    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--; // 1-based index -> 0-based index
        c[i]--;
    }
    
    // 돌(1) 위치 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                rock.push_back({i, j});
            }
        }
    }

    // 백트래킹 실행
    backtrack(0);

    // 최대 방문 가능한 칸 출력
    cout << ans << endl;

    return 0;
}
