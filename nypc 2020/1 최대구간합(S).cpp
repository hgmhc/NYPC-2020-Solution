#include <iostream>
using namespace std;

int main() {
    int N;
    long long int best = -1000000000, sum = 0;
    cin >> N;
    long long int array[N];
//    배열 입력받기
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
//    최대구간합 구하기
    for (auto a: array) {
        sum = max(a, sum+a);
        best = max(best, sum);
    }
    
    cout << best << '\n';
    return 0;
}
