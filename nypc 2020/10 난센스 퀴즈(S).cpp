#include <iostream>
#include <vector>
#define loop(i,n,m) for(int i = n; i < m; i++)
using namespace std;

char sign(int x) {
    switch (x) {
        case 0: return '.'; case 2: return '*'; case 3: return '/'; case 5: return '+'; case 6: return '-';
    }
    return 'f';
}

double calculate(double x, double y, int signNum) {
    switch (signNum) {
        case 0: return x+y/10; case 2: return x*y; case 3: return x/y; case 5: return x+y; case 6: return x-y;
    }
    return -17;
}

int main() {
    int T; double ans;
    cin >> T;
    vector<vector<double>> testCase(T, vector<double>(6));
    
    for (auto& v: testCase) {
        cin >> v[0] >> v[2] >> v[4] >> v[5];
        loop (i, 0, 7) {
            if (i == 1 || i == 4) continue;
            loop (j, 0, 7) {
                ans = 0.001;
                if (j == 1 || j == 4) continue;
                if (i == j) continue;
                if (i-j >= 2) ans = calculate(v[0], calculate(v[2], v[4], j), i);
                else ans = calculate(calculate(v[0], v[2], i), v[4], j);
                if (ans == v[5]) {
                    v[1] = i;
                    v[3] = j;
                    i = j = 7;
                }
            }
        }
    }
    for (auto v: testCase)
        cout << v[0] << sign(v[1]) << v[2] << sign(v[3]) << v[4] << '=' << v[5] << '\n';
    return 0;
}
