#include <stdio.h>

#define MAX 10000
long long max(long long a,long long b);
long long dp[10000005] = {0};
int main (void) {

    int t,m,time[MAX+5],value[MAX+5];
    scanf("%d %d",&t,&m);

    for (int i = 1; i <= m; ++i) {
        scanf("%d %d",&time[i],&value[i]);
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = time[i]; j <= t; ++j) {
            dp[j] = max(dp[j],dp[j-time[i]]+value[i]);
        }
    }

    printf("%lld\n",dp[t]);
    return 0;
}

long long max(long long a,long long b){
    return a>b?a:b;
}
