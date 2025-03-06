#include <iostream>
#include <vector>

using namespace std;
int K, N;
vector<int> rs;

bool check(vector<int> arr) {
    
    if(arr.empty()) return true;
    
    int cnt = 1;
    int first = arr[0];
    
    for(int i=1; i<arr.size(); i++) {
        
        if(first == arr[i]) {
            cnt++;
            if(cnt == 3) return false;
        } else {
            first = arr[i];
            cnt = 1;
        }
        
    }
    return true;
}

void backtrack(int n) {
    if(!check(rs)) return;
    if(rs.size() == N) {
        for(int i=0; i<rs.size(); i++) {
            cout<<rs[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=1; i<=K; i++) {
        rs.push_back(i);
        backtrack(i+1);
        rs.pop_back();
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    backtrack(0);

    return 0;
}
