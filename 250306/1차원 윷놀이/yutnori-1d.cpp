#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int nums[12];
int ans = 0;

vector<int> rs;

int letsgo(vector<int> arr) {
    if(arr.empty() ) return 0;
    
    int sum = 0;
    
    vector<int> board(n+1,0);
    
    for(int i=0; i<n; i++) {
        board[arr[i]] += nums[i];
    }
    for(int i=0; i<n; i++) {
        if(board[i] >= m-1) {
            sum += 1;
        }
    }
    return sum;
}


void backtrack() {
    
    if(rs.size() == n) {
        int sum = letsgo(rs);
        ans = max(ans, sum);
        return;
    }
    
    for(int i=1; i<=k; i++) {
        rs.push_back(i);
        backtrack();
        rs.pop_back();
    }
    
}
int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    backtrack();
    cout<<ans;

   

    return 0;
}
