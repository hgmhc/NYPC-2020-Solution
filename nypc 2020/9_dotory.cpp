#include <iostream>
#include <vector>
#define loop(x, y) for(int x = 1; x <= y; x++)
const int INF = 3000;
using namespace std;
int N;
vector<vector<int>> value(52, vector<int>(52, -INF));
vector<vector<int>> rootCheck(52, vector<int>(52, -1));
vector<char> ans;

void init() {
    int i, cnt; char a;
    loop (y, N) {
        loop (x, N) {
            cin >> a;
            switch (a) {
                case 'U':
                    value[y][x] = -INF;
                    rootCheck[y][x] = -1;
                    break;
                case 'D':
                    value[y][x] = 1;
                    rootCheck[y][x] = 0;
                    break;
                case '.':
                    value[y][x] = 0;
                    rootCheck[y][x] = 0;
                    break;
            }
        }
    } //유저한테는 -INF, 빈 공간은 0, 도토리는 1을 대입한다. 또, rootCheck는 전부 0으로 초기화한다.(테두리와 장애물은 -1)
    loop (x, N) if (!(value[1][x]+INF)) for (; x <= N; x++) value[1][x] = -INF; //첫째줄은 위에서 내려올 수 없으므로 막힌 곳을 전부 INF로 설정한다.
    for (int y = 2; y <= N; y++) {
        loop (x, N) {
            i = x; cnt = 0;
            while (value[y][x]+INF) cnt += value[y][x++];
            for (int j = i; j < x; j++) value[y][j] = cnt;
        }
    } //'가로묶음'에 있는 공간들은 전부 그 안의 도토리 개수로 바꿔준다.
    return;
}

void record(int y, int x) {
    int i = x;
    rootCheck[y][x] = 2;
    for (i = x; i <= N; i++) {
        rootCheck[y][i] = 2;
        if (!(rootCheck[y][i+1]+1)) {
            break;
        }
        ans.push_back('L');
    }
    for (; i >= 1; i--) {
        rootCheck[y][i] = 2;
        if (!(rootCheck[y][i-1]+1)) {
            break;
        }
        ans.push_back('R');
    }
    loop (j, N)
        if (rootCheck[y-1][j] == 1 && rootCheck[y][j] == 2) {
            if (j == i) {
                ans.push_back('D');
                record(y-1, i);
            }
            else if (j > i) {
                for (; i < j; i++) ans.push_back('L');
                ans.push_back('D');
                record(y-1, i);
            }
            else {
                for (; i > j; i--) ans.push_back('R');
                ans.push_back('D');
                record(y-1, i);
            }
            break;
        }
}

int main() {
    int best, tmp;
    cin >> N;
    
    init();
    for (int y = 2; y <= N; y++) {
        loop (x, N) {
            if (!(value[y][x]+INF)) continue;
            if (y == 1 && x == 1) continue;
            tmp = x;
            best = -INF+1;
            while (value[y][x]+INF) best = max(best, value[y-1][x++]);
            for (int j = tmp; j < x; j++) {
                if (value[y-1][j] == best) rootCheck[y-1][j] = 1;
                value[y][j] += best;
            }
        }
    } //격자에 누적 합과 경로 각색하기
    loop (y, N) {
        loop (x, N)
            // cout << value[y][x] << "                  ";
        cout << '\n';
    } //value 출력
    loop (y, N) {
        loop (x, N)
            // cout << rootCheck[y][x] << "    ";
        cout << '\n';
    } //rootCheck 출력
    record(N, N);
    
    int size = ans.size();
    for (int i = 1; i <= ans.size(); i++) cout << ans[size-i];
    cout << '\n';
    return 0;
}


