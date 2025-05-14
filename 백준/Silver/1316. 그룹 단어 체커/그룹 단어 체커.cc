#include <iostream>
#include <string>

using namespace std;

int n;
string arr[101];

bool check(string s) {
    bool visited[26] = {false};
    char prev = 0;

    for (char ch : s) {
        if (ch != prev) {
            if (visited[ch - 'a']) return false;
            visited[ch - 'a'] = true;
        }
        prev = ch;
    }
    return true;
}




int main() {
    int n;
    int ans = 0;
    
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    for(int i=0; i<n; i++) {
        bool tmp = check(arr[i]);
        if(tmp) ans++;
    }
    
    
    
    cout<<ans;
    
}
