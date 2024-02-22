#include<bits/stdc++.h>
using namespace std;

#define MAX 400


int dx[8]={-2,-2,2,2,1,-1,1,-1};
int dy[8]={-1,1,-1,1,2,-2,-2,2};
int n,m;
int map_[MAX+5][MAX+5];

queue<pair<int,int> > q;

void bfs(int x,int y);
int main(){

    int x,y;
    scanf("%d %d %d %d",&n,&m,&x,&y);

    q.push(make_pair(x,y));
    memset(map_,-1,sizeof(map_));
    map_[x][y] = 0;

    bfs(x,y);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%-5d ",map_[i][j]);
        }
        printf("\n");
    }
	return 0;
}

void bfs(int x,int y){
    while (!q.empty()) {
        for (int i = 0; i < 8; ++i) {
            int tmp_x = q.front().first + dx[i];
            int tmp_y = q.front().second + dy[i];
            if (tmp_x > 0 && tmp_x <= n && tmp_y > 0 && tmp_y <= m && map_[tmp_x][tmp_y] == -1){
                q.push(make_pair(tmp_x,tmp_y));
                map_[tmp_x][tmp_y] = map_[q.front().first][q.front().second]+1;
            }
        }
        q.pop();
    }
}