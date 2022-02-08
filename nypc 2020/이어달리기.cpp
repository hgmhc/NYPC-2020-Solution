#include <iostream>
#include <vector>
using namespace std;

unsigned int scanTime() {
    unsigned int a, b, c;
    scanf("%d:%d:%d", &a, &b, &c);
    return a*6000+b*100+c;
}

int main() {
    int N;
    unsigned int array[600000], sum = 0, best = -1;
    cin >> N;
    vector<unsigned int> time(N);
    for (auto& s: time) s = scanTime();
    for (int i = 0; i < 590000; i++) {
        sum = max(a, sum+a);
        best = max(best, sum);
    }
    return 0;
}
