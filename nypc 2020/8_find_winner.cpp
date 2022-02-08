#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, K, lastSpot[1003] = {0,}, tmp;
    cin >> N >> K;
    int picture[K+1];
    set<int> ans; //  N: 유저의 수, K: 사진의 수, picture: 유저의 번호들이 써있는 사진들 1<=N<=1000 1<=K<=10000 1<=picture<=N
    for (int i = 1; i <= K; i++) {
        cin >> picture[i];
        if (lastSpot[picture[i]]) {
            tmp = lastSpot[picture[i]];
            for (int j = 1; j < tmp; j++) {
                if (lastSpot[picture[j]] < tmp)
                    lastSpot[picture[j]] = 0;
            }
            ans.insert(picture[i]);
        }
        lastSpot[picture[i]] = i;
    }
    
    ans.insert(picture[1]);
    cout << ans.size() << '\n';
    for (auto v: ans) cout << v << ' ';
    return 0;
}
