#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char arr[100001];
    cin >> arr;
    unsigned int len = strlen(arr), n = 0;
    
    for (int i = 0; i < len; i++) {
        if (arr[i] == 'S') n++;
        else n += (4-(n % 4));
    }
    
    cout << n << '\n';
    return 0;
}
