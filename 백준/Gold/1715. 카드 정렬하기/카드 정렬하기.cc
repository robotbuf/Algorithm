#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> pq;
int n;

int main() {
    cin>>n;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int card;
        cin>>card;
        pq.push(-card);
    }
    
    for(int i = 0; i<n-1; i++) {
        int card1 = -pq.top();
        pq.pop();
        int card2 = -pq.top();
        pq.pop();
        int tmp = card1 + card2;
        ans += tmp;
        pq.push(-tmp);
    }
    
    cout<<ans;
}
