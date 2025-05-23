
#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    int current = 1;
    int index = 0;

    while (index < S.size()) {
        string num = to_string(current);
        for (char c : num) {
            if (c == S[index]) {
                index++;
                if (index == S.size()) break;
            }
        }
        current++;
    }

    cout << current - 1 << '\n';
    return 0;
}
