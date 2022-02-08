#include <iostream>
using namespace std;

unsigned int scanTime() {
    unsigned int a, b, c;
    scanf("%d:%d:%d", &a, &b, &c);
    return a*6000+b*100+c;
}

int main() {
    unsigned int N, T1, T2, T3;
    T1 = scanTime();
    T2 = scanTime();
    T3 = scanTime();
    cin >> N;
    int starNumber[N];
    
    for (int& n: starNumber) {
        int spentTime = scanTime();
        if (spentTime <= T3) n = 3;
        else if ((spentTime <= T2)&&(spentTime > T3)) n = 2;
        else if ((spentTime <= T1)&&(spentTime > T2)) n = 1;
        else n = 0;
    }
    
    for (int& n: starNumber)
        switch (n) {
            case 3:
                cout << "***\n";
                break;
                
            case 2:
                cout << "**\n";
                break;
                
            case 1:
                cout << "*\n";
                break;
                
            case 0:
                cout << ":(\n";
                break;
        }
    return 0;
}
