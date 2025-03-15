#include <iostream>
#include <vector>


using namespace std;

int N, M;
vector<int> rs;

bool visited[11] = { false };

void back(int n) {

    if(rs.size() == M) {
        for(int i=0; i<M; i++) {
            cout<<rs[i]<< " ";
        }
        cout<<"\n";
        return;
    }

    for(int i=n; i<=N; i++) {
        
        if(!visited[i]) {
             visited[i] = true;
             rs.push_back(i);
             back(i);
             rs.pop_back();
             visited[i] = false;
        }
    }
}
int main() {
    cin >> N >> M;

    // Please write your code here.
    back(1);
    return 0;
}



