#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> rs;

// 연속된 숫자가 3개 이상인지 확인하는 함수
bool check(const vector<int>& arr) {
    if (arr.empty()) return true; // 빈 배열이면 true

    int cnt = 1;
    int first = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == first) {
            cnt++;
            if (cnt == 3) return false; // 연속 3개 이상이면 false
        } else {
            first = arr[i];
            cnt = 1; // 새로운 숫자가 나오면 초기화
        }
    }
    return true;
}

// 백트래킹 함수
void backtrack() {
    if (!check(rs)) return; // 백트래킹을 실행하기 전에 검사

    if (rs.size() == N) {
        for (int num : rs) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= K; i++) {
        rs.push_back(i);
        backtrack();
        rs.pop_back();
    }
}

int main() {
    cin >> K >> N;
    backtrack();
    return 0;
}
