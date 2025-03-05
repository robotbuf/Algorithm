#include <iostream>
#include <vector>

using namespace std;

int n;
int x1[15], x2[15];  // 선분의 좌표를 저장하는 배열
int rs = 0;  // 최대 선택 가능한 선분 개수

bool check(const vector<int>& selected, int index) {
    // 현재 선택된 선분들과 겹치는지 확인
    for (int i : selected) {
        if (!(x2[i] <= x1[index] || x2[index] <= x1[i])) {
            return false; // 겹치는 경우 선택 불가능
        }
    }
    return true;
}

void choose(int idx, vector<int>& selected) {
    if (idx == n) {
        rs = max(rs, (int)selected.size());
        return;
    }

    // 현재 선분을 선택하는 경우
    if (check(selected, idx)) {
        selected.push_back(idx);
        choose(idx + 1, selected);
        selected.pop_back(); // 상태 복원
    }

    // 현재 선분을 선택하지 않는 경우
    choose(idx + 1, selected);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    vector<int> selected;
    choose(0, selected);

    cout << rs << endl;
    return 0;
}
