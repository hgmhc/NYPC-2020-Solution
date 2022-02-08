#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    if (X < Y) {
        int tmp = N;
        N = M;
        M = tmp;
        tmp = X;
        X = Y;
        Y = tmp;
    }
    if (M == 0)
        cout << int(log(N)/log(2)+1)*X;
    else if (M == 1)
        cout << int(log(N+1)/log(2))*X+Y;
    else if (M == 2)
    cout << int(log(N+2)/log(2)-1)*X+2*Y;
    
    else if (N == 0 && M == 2) {
        cout << 2*Y;
    }
    else if (N == 0 && M == 3) {
        cout << 2*Y;
    }
    else if (N == 1 && M == 2) {
        cout << X+Y;
    }
    else if (N == 1 && M == 3) {
        cout << max(X, 2*Y)+Y;
    }
    else if (N == 2 && M == 2) {
        cout << X+2*Y;
    }
    else if (N == 2 && M == 3) {
        cout << X+2*Y;
    }
    else if (N == 3 && M == 2) {
        cout << X+2*Y;
    }
    else if (N == 3 && M == 3) {
        cout << X+2*Y;
    }
    return 0;
}
