#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m, k;
int arr1[100000];
int arr2[100000];

typedef tuple<int, int, int> T;

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    // 최소 힙 사용 (합, i, j)
    priority_queue<T, vector<T>, greater<T>> pq;
    set<pair<int, int>> visited;

    pq.push({arr1[0] + arr2[0], 0, 0});
    visited.insert({0, 0});

    T res;

    for (int cnt = 0; cnt < k; cnt++) {
        res = pq.top();
        pq.pop();

        int sum, i, j;
        tie(sum, i, j) = res;

        // 오른쪽 이동 (arr2)
        if (j + 1 < m && visited.find({i, j + 1}) == visited.end()) {
            pq.push({arr1[i] + arr2[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }

        // 아래 이동 (arr1)
        if (i + 1 < n && j == 0 && visited.find({i + 1, j}) == visited.end()) {
            pq.push({arr1[i + 1] + arr2[j], i + 1, j});
            visited.insert({i + 1, j});
        }
    }

    cout << get<0>(res) << "\n";
    return 0;
}
