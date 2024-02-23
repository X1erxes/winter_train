#include <stdio.h>

int main (void) {

    int T,M;
    int time[105],value[105],dp[105][1005] = {0};
    scanf("%d %d",&T,&M);

    for (int i = 1; i <= M; ++i) {
        scanf("%d %d",&time[i],&value[i]);
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (j >= time[i]) {
                dp[i][j] = max(dp[i - 1][j - time[i]] + value[i], dp[i - 1][j]);
            } else dp[i][j] = dp[i - 1][j];
        }
    }

    printf("%d\n",dp[M][T]);
    return 0;
}

int max(int a,int b){
    return a>b?a:b;
}
