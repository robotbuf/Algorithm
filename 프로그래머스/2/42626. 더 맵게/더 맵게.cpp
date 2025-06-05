#include <string>
#include <vector>
#include <queue>
#include <functional>  

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int s : scoville) {
        pq.push(s);
    }

    while (!pq.empty() && pq.top() < K) {
        if (pq.size() < 2) {
            return -1;
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int newScoville = first + second * 2;
        pq.push(newScoville);
        answer++;
    }

    return answer;
}
