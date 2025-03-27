#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

bool canPress(int num, const vector<bool>& broken) {
    // 숫자 버튼으로 num을 만들 수 있는가?
    if (num == 0) return !broken[0];
    while (num > 0) {
        if (broken[num % 10]) return false;
        num /= 10;
    }
    return true;
}

int getLength(int num) {
    if (num == 0) return 1;
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> broken(10, false);
    for (int i = 0; i < M; ++i) {
        int b;
        cin >> b;
        broken[b] = true;
    }

    int minPress = abs(N - 100);
    for (int i = 0; i <= 999999; ++i) {
        if (canPress(i, broken)) {
            int press = getLength(i) + abs(i - N);
            minPress = min(minPress, press);
        }
    }

    cout << minPress << endl;
    return 0;
}
