#include <stdio.h>

int max (int a,int b);
int main() {

    int n,ans = -1e9,dp,tmp;
    int matrix[121][121] = {0};
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d",&matrix[i][j]);
            matrix[i][j] += matrix[i-1][j];
        }
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 1; k <= n; ++k) {
                tmp = matrix[i][k]-matrix[j][k];
                if (k == 1) dp = tmp;
                else dp = max(tmp, dp + tmp);
                ans = max(ans, dp);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
int max (int a,int b){
    if (a > b) return a;
    else return b;
}