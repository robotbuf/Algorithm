#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int arr[9];
int ans = 0;

vector<int> rs;
bool visited[9] = {false};

int cal(vector<int> rs) {
    int num = 0;
    for(int i=0; i<rs.size()-1; i++) {
        num += (abs(rs[i]-rs[i+1]));
    }
    
    return num;
}


void back() {
    
    if(rs.size() == n) {
        ans = max(ans, cal(rs));
        return;
    }
    
    for(int i=0; i<n; i++) {
        if(visited[i]) continue;
        
        visited[i] = true;
        rs.push_back(arr[i]);
        back();
        rs.pop_back();
        visited[i] = false;
    }
}






int main() {
    
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    back();
    
    cout<<ans;
    
}
