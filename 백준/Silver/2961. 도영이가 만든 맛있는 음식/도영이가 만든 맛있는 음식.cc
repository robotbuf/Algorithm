#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int s[11],b[11];

int ans = INT_MAX;

vector<int> rs;

int cal(vector<int> rs) {
    int S = 1;
    int B = 0;
    
    for(int i=0; i<rs.size(); i++) {
        S *= s[rs[i]];
        B += b[rs[i]];
    }
    
    return abs(S-B);
}

void back(int k) {
    if(rs.size() > 0) {
        ans = min(ans,cal(rs));
    }
    for(int i=k; i<n; i++) {
        rs.push_back(i);
        back(i+1);
        rs.pop_back();
    }
}



int main() {
    
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>s[i]>>b[i];
    }
    
    back(0);
    
    cout<<ans;
    
    
}
