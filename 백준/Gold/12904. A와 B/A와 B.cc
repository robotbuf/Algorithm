#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string S,T;

int main() {
    cin>>S;
    cin>>T;
    
    int ans = 0;
    
    
    while(T.size() != 0) {
        
        if(T == S) {
            ans = 1;
            break;
        }
        
        if(T[T.size()-1] == 'A') {
            T.pop_back();
        } else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    
    cout<<ans;
  
}

    
    
    
    