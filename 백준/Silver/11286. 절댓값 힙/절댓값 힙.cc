#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

struct E {
    int value;
    bool isPlus;
};


struct AbsCmp {
    bool operator()(const E &a, const E &b) const {
        if (a.value == b.value) {
            return a.isPlus > b.isPlus;
        }
        
        return a.value > b.value;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<E, vector<E>, AbsCmp> pq;

    while (n--) {
        int e;
        cin >> e;
        if (e == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                E top = pq.top();
                pq.pop();
                
                cout << (top.isPlus ? top.value : -top.value) << '\n';
            }
        } else {
        
            pq.push({ abs(e), e > 0 });
        }
    }
    return 0;
}
