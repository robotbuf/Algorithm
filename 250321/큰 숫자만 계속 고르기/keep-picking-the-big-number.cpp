#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[100000];

priority_queue<int> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        q.push(arr[i]);
    }
    
    
    for(int i=0; i<m; i++) {
        int n = q.top();
        n -= 1;
        q.pop();
        q.push(n);
    }
    
    cout<<q.top();

    

    return 0;
}
