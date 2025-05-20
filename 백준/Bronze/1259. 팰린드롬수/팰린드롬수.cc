
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main() {
    
    while(true) {
        string s;
        cin>>s;
        
        if(s == "0") break;
        
        int idx = s.length() - 1;
        
        bool check = true;
        
        for(int i=0; i<s.size(); i++) {
            if(s[idx] != s[i]) {
                check = false;
                break;
            }
            idx--;
        }
        
        if(check) {
            cout<<"yes"<<"\n";
        } else {
            cout<<"no"<<"\n";
        }
        
        
        
    }
}
