#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<ll> lessons(N);
    ll low = 0, high = 0;

    // 1) 이분 탐색 범위 설정
    for (int i = 0; i < N; i++) {
        cin >> lessons[i];
        low = max(low, lessons[i]);
        high += lessons[i];
    }

    ll answer = high;
    while (low <= high) {
        ll mid = (low + high) / 2;

        int required = 1;
        ll sum = 0;
        for (ll len : lessons) {
            if (sum + len <= mid) {
                sum += len;
            } else {
                required++;
                sum = len;
            }
        }

        
        if (required <= M) {
            
            answer = mid;
            high = mid - 1;
        } else {
            
            low = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
