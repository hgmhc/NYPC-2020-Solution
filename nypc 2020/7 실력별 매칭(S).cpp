#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    if (abs(v1[1]) != abs(v2[1]))
        return abs(v1[1]) < abs(v2[1]);
    else return v1[1] < v2[1];
}

int main() {
    int N, S, K, tmp;
    cin >> N >> S >> K;
    vector<vector<int>> arr;
    
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back({i+1, tmp-S});
    }
    
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < K; i++) cout << arr[i][0] << ' ';
    return 0;
}
