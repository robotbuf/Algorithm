#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Person {
    long long arrive;
    long long duration;
    int id; // 번호표 (작을수록 우선)

    bool operator<(const Person& other) const {
        return id > other.id; // 우선순위 큐에서 번호 작은 순
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<tuple<long long, long long, int>> people;

    for (int i = 0; i < N; ++i) {
        long long a, t;
        cin >> a >> t;
        people.emplace_back(a, t, i + 1); // (도착시간, 체류시간, 번호)
    }

    // 도착시간 기준 정렬
    sort(people.begin(), people.end());

    long long time = 0;
    int idx = 0;
    long long max_wait = 0;

    priority_queue<Person> pq;

    while (idx < N || !pq.empty()) {
        // 현재 시간에 도착한 사람들 큐에 넣기
        while (idx < N && get<0>(people[idx]) <= time) {
            pq.push(Person{get<0>(people[idx]), get<1>(people[idx]), get<2>(people[idx])});
            idx++;
        }

        if (!pq.empty()) {
            Person cur = pq.top(); pq.pop();
            long long wait = time - cur.arrive;
            max_wait = max(max_wait, wait);
            time += cur.duration;
        } else {
            // 다음 사람이 올 때까지 시간 스킵
            time = get<0>(people[idx]);
        }
    }

    cout << max_wait << "\n";

    return 0;
}
