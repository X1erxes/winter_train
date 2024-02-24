#include <stdio.h>
#include <math.h>

#define MAX 100000
long long arr[MAX+5] = {0},diff[MAX+5] = {0};

long long max (long long a, long long b);
long long min (long long a, long long b);

int main (void) {

    int n;
    long long positive_sum = 0,negetive_sum = 0,ans1,ans2;
    scanf("%d",&n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld",&arr[i]);
        diff[i] = arr[i] - arr[i-1];
    }

    for (int i = 2; i <= n; ++i) {
        if (diff[i] > 0) positive_sum += diff[i];
        else negetive_sum -= diff[i];
    }

    ans1 = max(positive_sum,negetive_sum);
    ans2 = abs(positive_sum-negetive_sum) + 1;

    printf("%lld\n%lld",ans1,ans2);

    return 0;
}

long long max (long long a, long long b){
    return a>b?a:b;
}

long long min (long long a, long long b){
    return a<b?a:b;
}