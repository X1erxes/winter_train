#include <stdio.h>

#define MAX 1000

int max(int a,int b);
int l[MAX + 5][MAX + 5];
int main (void) {

    int r;
    scanf("%d",&r);

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d",&l[i][j]);
        }
    }

    for (int i = r; i >= 2; --i) {
        for (int j = 1; j <= i-1; ++j) {
            l[i-1][j] += max(l[i][j],l[i][j+1]);
        }
    }

    printf("%d\n",l[1][1]);
    return 0;
}

int max(int a,int b){
    return a>b?a:b;
}
