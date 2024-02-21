#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    long long C,a[200000],upper_index,lower_index,ret = 0;
    scanf("%d %lld",&N,&C);
    for (int i = 0; i < N; ++i) {
        scanf("%lld",&a[i]);
    }
    sort(a,a+N);

    for (int i = 0; i < N; ++i) {
        upper_index = upper_bound(a,a+N,a[i]+C)-a;
        lower_index = lower_bound(a,a+N,a[i]+C)-a;
        ret += upper_index - lower_index;
    }
    printf("%lld\n",ret);
    return 0;
}