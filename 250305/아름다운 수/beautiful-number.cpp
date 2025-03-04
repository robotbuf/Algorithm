#include <iostream>
#include <vector>

using namespace std;

bool isBeautiful(string num) {
    int idx = 0;
    while(idx < num.size()) {
        if(num[idx] == 1) {
            idx++;
            continue;
        }
        int count = 0;
        for(int i=idx; i<idx+ num[idx]-'0'; i++) {
            if(i == num.size()) break;
            if(num[idx] == num[i]) {
                count++;
            }
        }
        if(count != num[idx]-'0') {
            return false;
        } else {
            idx += num[idx] - '0';
        }
    }
    return true;
}

int N;
int beautifulCount = 0;

void generateNumbers(string current) {
    if (current.length() == N) {
        if (isBeautiful(current)) {
            //cout << "Beautiful: " << current << endl;
            beautifulCount++;
        }
        return;
    }
    for (char digit = '1'; digit <= '4'; digit++) {
        generateNumbers(current + digit);
    }
}

int main() {
    cin >> N;
    
    generateNumbers("");

    cout << beautifulCount << endl;
    
    return 0;
}
