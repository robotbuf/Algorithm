#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

int main() {
    
    cin>>n>>m;
    
    set<string> a;
    set<string> b;
    
    vector<string> result;
    
    
    for(int i=0; i<n; i++) {
        string name;
        cin>>name;
        a.insert(name);
    }
    for(int i=0; i<m; i++) {
        string name;
        cin>>name;
        b.insert(name);
    }
    
    set_intersection(
        a.begin(), a.end(),
        b.begin(), b.end(),
        back_inserter(result)
                     );
    
    cout<<result.size()<<"\n";
    
    for(string x: result) {
        cout<<x<<"\n";
    }
    
    
    
   
}
