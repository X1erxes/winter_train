#include <stdio.h>

int a[10000000];
int b[1000000];
int main() {

    int n,m;

    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d",&b[i]);
    }

    for (int i = 0; i < m; i++) {
        int target = b[i];
        int left_edge = 0,right_edge = n-1;
        if ( target < a[left_edge] || target > a[right_edge]) {
            printf("-1 ");
            continue;
        }
        while(left_edge < right_edge) {
            int mid = (left_edge + right_edge)/2;
            if (target>a[mid]) {
                left_edge = mid+1;
            }
            else if (target<=a[mid]) {
                right_edge = mid;
            }
        }
        if (target == a[left_edge]) {
            printf("%d ",left_edge+1);
        } else {
            printf("-1 ");
        }
    }
    return 0;
}