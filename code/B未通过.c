#include <stdio.h>
#include <math.h>

int main() {

    int L,N,M;
    int left_edge,right_edge;
    int D[50000],d[50001];

    scanf("%d %d %d",&L,&N,&M);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&D[i]);
    }

    d[0] = D[0];
    for (int i = 1; i < N; ++i) {
        d[i] = D[i] - D[i-1];
    }
    d[N] = L - D[N-1];

    left_edge = 0;
    right_edge = L;
    while (left_edge < right_edge) {
        double mid = (int)ceil( 1.0 * (left_edge + right_edge) / 2);
        int count = 0,temp = d[0];
        for (int i = 0; i < N; ++i) {
            if (mid > temp) {
                count++;
                temp = d[i+1] + d[i];
            } else temp = d[i+1];
        }
        if (mid > temp) count++;

        if (count < M) {
            left_edge = mid + 1;
            continue;
        }
        if (count > M) {
            right_edge = mid - 1;
            continue;
        }
        if (count == M) {
            left_edge = mid;
            continue;
        }
    }
    printf("%d\n",left_edge);
    return 0;
}