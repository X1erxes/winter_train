#include <stdio.h>
#include <string.h>

#define MAX 1000
int main() {

    int M,N,ret = 0,tmp,index = 0,origin = 0;
    int word[105] = {0},cnt[MAX+5] = {0};
    //memset(word,-1,sizeof(word));
    scanf("%d %d",&M,&N);

    for (int i = 0; i < N; ++i) {
        scanf("%d",&tmp);
        if (cnt[tmp] == 0) {
            if (index < M) {
                ret++;
                word[index] = tmp;
                index++;
                cnt[tmp]++;
            } else {
                cnt[word[origin]]--;
                ret++;
                word[origin] = tmp;
                cnt[tmp]++;
                if (origin < M - 1) origin++;
                else origin = 0;
            }
        }

    }
    printf("%d\n",ret);
    return 0;
}