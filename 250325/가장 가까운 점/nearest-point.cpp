#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100000

using namespace std;

// 변수 선언
pair<int, int> points[MAX_N];
priority_queue<tuple<int, int, int> > pq;
int n, m;

int main() {
    // 입력:
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    // priority queue에
    // x + y, x, y 순으로
    // 우선순위가 되도록 합니다.
    // 최소인 점이 먼저 뽑혀야 하므로
    // 전부 -를 붙여서 넣어줘야 함에 유의합니다.
    for(int i = 0; i < n; i++) {
        int x, y;
        tie(x, y) = points[i];
        pq.push(make_tuple(-(x + y), -x, -y));
    }

    // m번에 걸쳐
    // 가장 가까운 점을 잡아
    // 2씩 더해주는 작업을 합니다.
    while(m--) {
        int x, y;
        tie(ignore, x, y) = pq.top();
        x = -x; y = -y;
        pq.pop();

        // 그 다음 위치를 추가합니다.
        x += 2; y += 2;
        pq.push(make_tuple(-(x + y), -x, -y));
    }

    int last_x, last_y;
    tie(ignore, last_x, last_y) = pq.top();
    cout << -last_x << " " << -last_y;
    return 0;
}
