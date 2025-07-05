#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    double scores[1000];
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

   
    double maxScore = scores[0];
    for (int i = 1; i < N; i++) {
        if (scores[i] > maxScore)
            maxScore = scores[i];
    }


    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += (scores[i] / maxScore) * 100.0;
    }

  
    double average = sum / N;

   
    printf("%.6f\n", average);
    return 0;
}
