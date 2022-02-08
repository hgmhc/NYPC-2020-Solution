#include <iostream>
using namespace std;

int main() {
    int i, j, k, y, x;
    cin >> i >> j >> k;
    //n이 자연수라고 하자. m은 2n 이상의 자연수라고 하자.
    //A 케이스: (1,1,3), B 케이스: (n,m-n,m), C 케이스: (0,n-1,n), D 케이스: (0,0,1)
    while (k != 0) {
        //New 케이스
        if (i >= 5 || j >= 5 || k >= 5) {
            i = j = k = 5;
            cout << 3 << ' ' << 6 << endl;
        }
        //C 케이스
        else if (i == 0 && j != k-1) {
            if (j == k) cout << 2 << ' ' << j-- << endl;
            else {
                k = j+1;
                cout << 3 << ' ' << k+1 << endl;
            }
        } //C 케이스 수행하기-1(feat.D 케이스; 일부 포함)
        else if (j == k-1) {
            i = 0;
            cout << 1 << ' ' << 1 << endl;
        } //C 케이스 수행하기-2
        //A 케이스, D 케이스
        else if (i == 1) {
            if (j >= 2) {
                j = k = 2;
                cout << 3 << ' ' << 3 << endl;
            } //A 케이스 수행하기-1
            else if (k == 1) {
                i = j = 0;
                cout << 2 << ' ' << 1 << endl;
            } //D 케이스 수행하기
        }
        else if (i == j && j == k && k == 2) {
            cout << 1 << ' ' << i-- << endl;
        } //A 케이스 수행하기-2
        
        //B 케이스
        else if (i >= 2) {
            if (i+j > k) { //Bi)케이스
                if (j == k) {
                    i = j = k/2;
                    cout << 2 << ' ' << j+1 << endl;
                }
                else {
                    i = k-j;
                    cout << 1 << ' ' << i+1 << endl;
                }
            }
            else { //Bii)케이스
                k = i+j;
                cout << 3 << ' ' << k+1 << endl;
            }
        }
        
        cin >> y >> x;
        switch (y) {
            case 3: k = x-1;
            case 2: j = min(x-1, j);
            case 1: i = min(x-1, i);
        }
    }
    return 0;
}
