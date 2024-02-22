#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

vector<int> v[MAX+5];
int ret[MAX+5] = {0};
int N,M;
void dfs(int target,int end);
int main (void) {

    scanf("%d %d",&N,&M);

    for (int i = 0; i < M; ++i) {
        int tmp1,tmp2;
        scanf("%d %d",&tmp1,&tmp2);
        v[tmp2].push_back(tmp1);
    }

    for (int i = N; i >= 1; --i) {
        dfs(i,i);
    }

    for (int i = 1; i <= N; ++i) {
        printf("%d ",ret[i]);
    }
    return 0;
}
void dfs(int target,int end){
    if (ret[target]) return;

    ret[target] = end;
    for (int i = 0; i < v[target].size(); ++i) {
        dfs(v[target][i],end);
    }
}