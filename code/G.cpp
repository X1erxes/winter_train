#include <bits/stdc++.h>
using namespace std;

int tmp[1000000] = {0};
map<int,int> bag;
int main() {

    int T,n,cnt = 0,ret = 0,l = 0;
    scanf("%d",&T);

    for (int i = 0; i < T; ++i) {
        scanf("%d",&n);
        for (int j = 0; j < n; ++j) {
            scanf("%d",&tmp[j]);
            if (bag[tmp[j]] == 0) {
                cnt++;
                bag[tmp[j]]++;
            } else {
                while (bag[tmp[j]] != 0) {
                    bag[tmp[l]]--;
                    cnt--;
                    l++;
                }
                bag[tmp[j]]++;
                cnt++;
            }
            ret = max(ret,cnt);
        }
        printf("%d\n",ret);
        l = 0;
        ret = 0;
        cnt = 0;
        bag.clear();
        memset(tmp,0,sizeof(tmp));
    }
    return 0;
}