#include <stdio.h>


int main() {

    int n,m;
    int location[1001][1001] = {0};
    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; ++i) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for (int j = x1; j <= x2; ++j) {
            for (int k = y1; k <= y2; ++k) {
                location[j][k]++;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ",location[i][j]);
        }
        printf("\n");
    }
    return 0;
}