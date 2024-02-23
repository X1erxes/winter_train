#include <stdio.h>

#define MAX 10000

int find(int x);
void combine(int x,int y);

int state[MAX + 5] = {0};
int main (void) {

    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        state[i] = i;
    }

    for (int i = 1; i <= M; ++i) {
        int tmp1, tmp2, tmp3;
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        if (tmp1 == 1) combine(tmp2,tmp3);
        else if (tmp1 == 2 && find(tmp2) == find(tmp3)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}

int find(int x){
    if (state[x] == x) return x;
    else {
        state[x] = find(state[x]);
        return state[x];
    }
}

void combine(int x,int y){
    state[find(x)] = find(y);
}