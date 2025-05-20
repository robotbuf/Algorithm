#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;



int main() {
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        stack<char> st;
        
        bool ans = true;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            } else {
                if(st.size() == 0) {
                    ans = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        
        if(!ans) cout<<"NO"<<"\n";
        else {
            if(st.size() == 0) cout <<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
        
        
    }
    
    
}