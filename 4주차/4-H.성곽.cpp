#include<bits/stdc++.h>
using namespace std;
int n, m, mx, big, cnt;
int visited[51][51], a[51][51], compSize[2504];
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int dfs(int y, int x, int cnt){ 
    if(visited[y][x]) return 0; // 상남자답게 건너고 나서 체크
    visited[y][x] = cnt;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        if(!(a[y][x] & (1 << i))){
            int ny = y + dy[i];
            int nx = x + dx[i];
            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                cnt++;
                compSize[cnt] = dfs(i, j, cnt); // 벽없앨 때를 대비해 저장
                mx = max(mx, compSize[cnt]);
            }
        }
    }
    // 벽뿌수면서 더하기
    for(int i = 0; i < m; i++){ 
        for(int j = 0; j < n; j++){
            if(i + 1 < m){  // 오버플로우 체크, 방어코드
                int a = visited[i + 1][j];
                if(a != b){
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
            if(j + 1 < n){ //
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if(a != b){
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
        }
    }
    cout << cnt << '\n' << mx << '\n' << big << '\n';
    return 0;
}