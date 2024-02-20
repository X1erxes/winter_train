#include <stdio.h>
#include <math.h>

int main() {

    int L,N,M;
    int left_edge,right_edge,ret;
    int D[50000];

    scanf("%d %d %d",&L,&N,&M);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&D[i]);
    }

    left_edge = 0;
    right_edge = L;
    while (left_edge <= right_edge) {
        int position = 0,count = 0;
        int mid = (left_edge + right_edge) / 2;

        for (int i = 0; i < N; ++i) {
            if (D[i] - position < mid ) {
                count++;
            } else position = D[i];
        }
        if (L - position < mid) count++;

        if (count <= M) {
            ret = mid;
            left_edge = mid + 1;
        } else right_edge = mid - 1;
    }
    printf("%d\n",ret);
    return 0;
}