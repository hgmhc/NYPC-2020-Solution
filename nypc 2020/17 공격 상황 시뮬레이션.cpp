#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int N;
    long double A, B, x, y;
    vector<pair<long double, long double>> striker;
    scanf("%d %Lf %Lf", &N, &A, &B);
    for (int i = 0; i < N; i++) {
        scanf("%Lf %Lf", &x, &y);
        striker.push_back({(A-x)/y, (x-B)/y});
    }
    sort(striker.begin(), striker.end());
    for (int frontPoint = 0; frontPoint < N-1; frontPoint++) {
        for (int backPoint = frontPoint+1; backPoint < N; backPoint++) {
            if (striker[frontPoint].second < striker[backPoint].second) {
                striker.erase(striker.begin()+backPoint);
                backPoint--; N--;
            }
        }
    }
    cout << striker.size();
    return 0;
}
