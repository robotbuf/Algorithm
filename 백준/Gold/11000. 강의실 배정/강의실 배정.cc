#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> room;
int n;

vector<pair<int,int>> arr;

int main() {
    cin>>n;
    
    for(int i=0; i<n; i++) {
        int s,t;
        cin>>s>>t;
        
        arr.push_back({s,t});
    }
    sort(arr.begin(),arr.end());
    
    for(int i=0; i<n; i++) {
        pair<int,int> info = arr[i];
        if(room.size() == 0) {
            room.push(-info.second);
        } else {
            if(-room.top() > info.first) {
                room.push(-info.second);
            }else {
                room.pop();
                room.push(-info.second);
            }
        }
    }
    
    cout<<room.size();
}
