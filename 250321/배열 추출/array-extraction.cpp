#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int x[200000];

priority_queue<int> q;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for(int i=0; i<n; i++) {
        if(x[i] == 0) {
            if(q.empty()) {
                cout<<0<<"\n";
            } else {
                cout<<q.top()<<"\n";
                q.pop();
            }
        } else {
            q.push(x[i]);
        }
    }

    return 0;
}
