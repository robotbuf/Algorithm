#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <map>

using namespace std;




int main() {
    int n,m;
    cin>>n>>m;
    map<string,string> map;
    
    
    for(int i=0; i<n; i++) {
        string add,pwd;
        
        cin>>add>>pwd;
        
        map[add] = pwd;
    }
    
    for(int i=0; i<m; i++) {
        string target;
        cin>>target;
        
        cout<<map[target]<<"\n";
    }
}
