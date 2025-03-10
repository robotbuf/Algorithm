#include <iostream>
using namespace std;

int N, S;
int arr[21];
int ans = 0;

void back(int idx, int sum, bool picked) {
    // 배열 끝까지 탐색했을 때
    if (idx == N) {
        if (sum == S && picked) { // 공집합이 아니어야 함
            ans++;
        }
        return;
    }

    // 현재 원소를 선택하는 경우
    back(idx + 1, sum + arr[idx], true);
    
    // 현재 원소를 선택하지 않는 경우
    back(idx + 1, sum, picked);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    back(0, 0, false); // 초기 sum=0, 아무것도 선택 안한 상태(false)
    cout << ans << endl;
}
