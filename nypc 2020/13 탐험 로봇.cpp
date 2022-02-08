#include <iostream>
#define loop(x, n) for(int x = 1; x <= n; x++)
using namespace std;

bool visited[1002][1002];
char M[1004][1004];

void dfs (int y, int x) {
    if (visited[y][x] || M[y][x] == 'S' || !M[y][x]) return;
    visited[y][x] = 1;
    M[y][x] = 'L';
    dfs(y+1, x); dfs(y, x+1); dfs(y, x-1); dfs(y-1, x);
}

void dfsFind (int y, int x) {
    if (!visited[y][x] || M[y][x] == 'S' || !M[y][x]) return;
    visited[y][x] = 0;
    dfsFind(y+1, x); dfsFind(y, x+1); dfsFind(y, x-1); dfsFind(y-1, x);
}

int main() {
    int R, C, cnt = 0; //1<=RxC<=1000
    cin >> R >> C;
    char S[4];
    cin >> S;
    loop (i, R)
        loop(j, C)
            M[i][j] = 0;
    loop (i, R)
        loop (j, C) cin >> M[i][j];
    
    if (S[1] == 'i' && R == 1) { //min인 경우
        loop (i, R)
            loop (j, C)
                if (M[i][j] == 'L') {
                    cnt++;
                    for (; j < C; j++) if (M[i][j] == 'S') break;
                }
    }
    else if (S[1] == 'i') {
        loop (i, R)
            loop (j, C)
                if (!visited[i][j] && M[i][j] == 'L') dfs(i, j);
        loop (i, R) {
            loop (j, C)
                if (visited[i][j] && M[i][j] == 'L') {
                    dfsFind(i, j);
                    cnt++;
                }
        }
    }
    else { //max인 경우
        loop (i, R) {
            if (M[i][1] == '?') M[i][1] = 'L';
            loop (j, C) {
                if (M[i][j] == 'L') {
                    cnt++;
                    for (; j <= C-1; j++) {
                        if (M[i][j] == 'L' && M[i][j+1] == '?') M[i][j+1] = 'S';
                        else if (M[i][j] == 'S') {
                            if (M[i][j+1] == '?') M[i][j+1] = 'L';
                            break;
                        }
                    }
                }
                if (M[i][j] == 'S' && M[i][j+1] == '?') M[i][j+1] = 'L';
            }
        }
    }
    cout << cnt;
    return 0;
}
