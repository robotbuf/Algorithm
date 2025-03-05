#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

string expr;
vector<char> variables;
unordered_map<char, int> assignedValues;
int maxResult = INT_MIN;

int evaluateExpression() {
    vector<int> nums;
    vector<char> ops;

    for (char c : expr) {
        if (isalpha(c)) {
            nums.push_back(assignedValues[c]);
        } else {
            ops.push_back(c);
        }
    }

    int result = nums[0];
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == '+') {
            result += nums[i + 1];
        } else if (ops[i] == '-') {
            result -= nums[i + 1];
        } else if (ops[i] == '*') {
            result *= nums[i + 1];
        }
    }
    return result;
}

// 백트래킹: 변수에 10~40 범위 숫자를 할당하여 최대 결과 찾기
void backtrack(int index) {
    if (index == variables.size()) {
        // 모든 변수를 할당했으면 연산 실행 후 최댓값 갱신
        int result = evaluateExpression();
        maxResult = max(maxResult, result);
        return;
    }

    char var = variables[index];

    // 10~40 사이의 숫자 중에서 선택 (중복 허용)
    for (int num = 1; num <= 4; num++) {
        assignedValues[var] = num;
        backtrack(index + 1);
    }
}

int main() {
    cin >> expr;

    // 등장한 알파벳 찾기
    for (char c : expr) {
        if (isalpha(c) && find(variables.begin(), variables.end(), c) == variables.end()) {
            variables.push_back(c);
        }
    }

    // 백트래킹 시작
    backtrack(0);

    // 결과 출력
    cout << maxResult << endl;
    return 0;
}
