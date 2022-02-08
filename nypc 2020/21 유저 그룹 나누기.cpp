#include <iostream>
using namespace std;

int main() {
    int N, K, X;
    cin >> N >> K >> X;
    int U[N], point[K], sect[400] = {0,};
    for (int i = 0; i < K-1; i++) point[i] = (i+1)*N/(K-1);
    for (auto& a: U) cin >> a;
    int tmp = 1;
    point[0] = 0;
    for (int i = 0; i < N; i++) {
        if (i <= point[tmp] && point[tmp] < i+1) tmp++;
        sect[tmp] += U[i];
    }
    for (int i = 0; i < K-2; i++) {
        if (sect[i] > sect[i+1])
            while (sect[i] <= sect[i+1]) {
                point[i]--;
                sect[i] -= U[point[i]];
                sect[i+1] += U[point[i]];
            }
        else
            while (sect[i] > sect[i+1]) {
                point[i]++;
                sect[i] += U[point[i]];
                sect[i+1] -= U[point[i]];
            }
    }
    for (int i = K-2; i > 0; i--) {
        if (sect[i] > sect[i+1])
            while (sect[i] <= sect[i+1]) {
                point[i]--;
                sect[i] -= U[point[i]];
                sect[i+1] += U[point[i]];
            }
        else
            while (sect[i] > sect[i+1]) {
                point[i]++;
                sect[i] += U[point[i]];
                sect[i+1] -= U[point[i]];
            }
    }
    for (int i = 0; i < K; i++)
        cout << sect[i] << ' ';
    return 0;
}
