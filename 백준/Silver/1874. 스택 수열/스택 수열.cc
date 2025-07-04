#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> seq(n);
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }

    stack<int> st;
    vector<char> ops;
    int curr=1;

    for(int t:seq){
        while(curr<=t){
            st.push(curr++);
            ops.push_back('+');
        }
        if(!st.empty() && st.top()==t){
            st.pop();
            ops.push_back('-');
        } else {
            cout<<"NO\n";
            return 0;
        }
    }

    for(char c:ops){
        cout<<c<<"\n";
    }
    return 0;
}
