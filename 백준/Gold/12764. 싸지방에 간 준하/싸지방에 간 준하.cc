#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> books(N);
    for (int i = 0; i < N; i++) {
        cin >> books[i].first >> books[i].second;
    }
    sort(books.begin(), books.end(),
         [](auto &a, auto &b){ return a.first < b.first; });

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > inUse;

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > available;

    vector<int> useCount;
    int nextSeat = 0;

    
    for (auto &[start, end] : books) {
        
        while (!inUse.empty() && inUse.top().first <= start) {
            available.push(inUse.top().second);
            inUse.pop();
        }

        int seat;
        if (available.empty()) {
            
            seat = nextSeat++;
            useCount.push_back(0);
        } else {
            seat = available.top();
            available.pop();
        }

       
        inUse.push({end, seat});
        useCount[seat]++;
    }


    cout << nextSeat << "\n";
    for (int i = 0; i < nextSeat; i++) {
        cout << useCount[i] << (i+1<nextSeat ? ' ' : '\n');
    }
    return 0;
}
