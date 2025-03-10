#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int L,C;
char arr[18];

vector<char> rs;

bool check(vector<char> arr) {
    int cnt1 = 0;
    int cnt2 = 0;
    
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            cnt1++;
        } else {
            cnt2++;
        }
    }
    
    return cnt1>=1 && cnt2>=2 ? true : false;
}



void back(int n) {
    if(rs.size() == L && check(rs)) {
        for(int i=0; i<L; i++) {
            cout<<rs[i];
        }
        cout<<"\n";
        return;
    }
    
    for(int i=n; i<C; i++) {
        rs.push_back(arr[i]);
        back(i+1);
        rs.pop_back();
    }
}

int main() {
    cin>>L>>C;
    
    for(int i=0; i<C; i++) {
        cin>>arr[i];
    }
    
    sort(arr,arr+C);
    
    back(0);
    
}
