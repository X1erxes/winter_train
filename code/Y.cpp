#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

vector<int> pasture[MAX+5];
int cow[105],ret[MAX+5],state[MAX+5];

void dfs(int a);
int main (void) {

    int K,N,M,sum = 0;
    scanf("%d %d %d",&K,&N,&M);

    for (int i = 1; i <= K; ++i) {
        scanf("%d",&cow[i]);
    }

    for (int i = 0; i < M; ++i) {
        int tmp1,tmp2;
        scanf("%d %d",&tmp1,&tmp2);
        pasture[tmp1].push_back(tmp2);
    }

    for (int i = 1; i <= K; ++i) {
        dfs(cow[i]);
        memset(state,0,sizeof(state));
    }

    for (int i = 1; i <= N; ++i) {
        if (ret[i] == K) sum++;
    }

    printf("%d\n",sum);
    return 0;
}
void dfs(int a){
    state[a] = 1;
    ret[a]++;
    for (int i = 0;i < pasture[a].size(); ++i) {
        int p = pasture[a][i];
        if (!state[p]) dfs(p);
    }
}