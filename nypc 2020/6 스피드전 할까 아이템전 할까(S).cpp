#include <iostream>
using namespace std;

int main() {
    int T, ability[8];
    bool winningCase[1000][2] = {0, };
    cin >> T;
    
    for (int i = 0; i < T; i++) {
//        여기 0으로 초기화 시키는 것이 상당히 중요함. 매번 덧씌워지기 때문. 항상 유의하길 바람.
        int mySum = 0, urSum = 0, myMax = 0, urMax = 0;
        
        for (int j = 0; j < 4; j++) {
            cin >> ability[j];
            mySum += ability[j];
            myMax = max(myMax, ability[j]);
        }
        
        for (int j = 4; j < 8; j++) {
            cin >> ability[j];
            urSum += ability[j];
            urMax = max(urMax, ability[j]);
        }
        
        if (mySum > urSum) winningCase[i][0] = 1;
        if (myMax > urMax) winningCase[i][1] = 1;
    }
//    i가 아니라 T를 넣었는데 이런 븅신같은 짓은 안하지 바람.
    for (int i = 0; i < T; i++) {
        if (!(winningCase[i][0] ^ winningCase[i][1])) cout << "R\n";
        else if (winningCase[i][0]) cout << "S\n";
        else cout << "I\n";
    }
    
    return 0;
}
