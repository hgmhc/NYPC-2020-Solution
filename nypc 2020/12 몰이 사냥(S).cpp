#include <iostream>
#include <vector>
#include <set>
#define loop(N) for(int i = 0; i < N; i++)
using namespace std;
long long X, R, N, Cmax, Cmin; //X: 사거리, R: 효과 범위, 1<=N<=100000: 몬스터의 수
vector<pair<long long, long long>> monster(100000); //di+t*si와 si가 각각 monster의 요소
long long minmaxNum(long long t) {
    Cmax = -4e18; Cmin = 4e18;
    for (int i = 0; i < N; i++) {
        Cmin = min(Cmin, monster[i].first+t*monster[i].second);
        Cmax = max(Cmax, monster[i].first+t*monster[i].second);
    }
    return Cmax-Cmin;
}
int main() {
    long long len1, len2;
    scanf("%lld %lld", &X, &R);
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) scanf("%lld %lld", &monster[i].first, &monster[i].second);
    
    long long a = 0, b = 3000000000; //삼진탐색은 이진탐색과 마찬가지로 범위에 3배를 해줘야 한다.
    while (a <= b) { //볼록한 그래프에서는 이진탐색이 제대로 먹히지 않는다. 삼진탐색을 이용해야 한다.
        long long t1 = (2*a+b)/3, t2 = (a+2*b)/3; //t1과 t2는 칸막이 역할을 해준다.
        len1 = minmaxNum(t1);
        if (len1 <= R && Cmin >= 0 && Cmax <= X+R) {
            printf("T");
            return 0;
        }
        len2 = minmaxNum(t2);
        if (len2 <= R && Cmin >= 0 && Cmax <= X+R) {
            printf("T");
            return 0;
        }
        if (len1 > len2) a = t1+1;
        else b = t2-1;
    }
    printf("F");
    return 0;
}


