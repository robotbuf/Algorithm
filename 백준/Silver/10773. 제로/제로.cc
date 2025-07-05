#include <iostream>
#include <stack>

using namespace std;


int main() {
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        if(num == 0) {
            if(!st.empty()) {
                st.pop();
            }
        } else {
            st.push(num);
        }
    }
    
    int ans = 0;
    
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    
    cout<<ans;
    
}
