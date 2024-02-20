#include <stdio.h>

int main() {

    int n,m;
    int a[100000];

    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);

    int l,r;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&l,&r);
        int sum = 0;
        for (int j = l; j <= r; ++j) {
            sum += a[j];
        }
        printf("%d\n",sum);
    }
    return 0;
}