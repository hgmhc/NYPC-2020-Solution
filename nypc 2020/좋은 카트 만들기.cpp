#include <iostream>
#include <vector>
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long double ld;
using namespace std;

int A[300000], B[300000];
vector<int> C(300000), D(300000); // <= 10e9
vector<ld> engine(300000);
vector<pair<int, ld>> handle(300000);

bool cmp(const pair<int, ld>& v1, const pair<int, ld>& v2) { //v1이 앞, v2가 뒤
    if (v1.second != v2.second)
        return v1.second > v2.second; //이게 참이면 내름차순
    else return v1.first < v2.first; //이게 참이면 분자에 대해서 오름차순
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // <= 3e5
    loop (i, N) {
        scanf("%d %d", &A[i], &B[i]);
        engine[i] = ld(A[i]/B[i]);
    }
    loop (j, M) {
        scanf("%d %d", &C[j], &D[j]);
        handle[j] = {C[j], ld(C[j]/D[j])};
    }
    sort(handle.begin(), handle.end(), cmp);
    loop (i, N) {
        ld mx = -1;
        int tmp;
        if (engine[i] >= handle[0].second) {
            tmp = 1;
        }
        else {
            loop (j, M) {
                if (mx < ld(A[i]+C[j])/ld(B[i]+D[j])) {
                    mx = ld(A[i]+C[j])/ld(B[i]+D[j]);
                    tmp = j+1;
                }
            }
        }
        printf("%d\n", tmp);
    }
    return 0;
}
