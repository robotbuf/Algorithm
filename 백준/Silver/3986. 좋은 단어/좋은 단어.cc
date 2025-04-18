#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

bool check(string s) {
    stack<char> st;
    for(int i=0; i<s.size(); i++) {
        if(st.empty()) {
            st.push(s[i]);
        } else {
            if(st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }
    if(st.empty()) {
        return true;
    } else {
        return false;
    }
}


int main() {
    
    int n;
    stack<int> s;
    int ans = 0;
    
    cin>>n;
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        if(check(s)) ans++;
    }
    
    cout<<ans;
    
}
