#include <stdio.h>
#include <string.h>

#define MAX 13

void dfs(int a);
void print(void);

int n,total = 0;
int line[MAX+5],column[MAX+5],ld[MAX+5],rd[MAX+5];
int main() {

    scanf("%d",&n);

    dfs(1);
    printf("%d\n",total);
    return 0;
}
void dfs(int a){
    if (a > n) {
        print();
    } else {
        for (int i = 1; i <= n; ++i) {
            if ( !column[i] && !ld[n-a+i] && !rd[2*n+1-i-a]) {
                line[a] = i;
                column[i]++;
                ld[n-a+i]++;
                rd[2*n+1-i-a]++;
                dfs(a+1);
                column[i]--;
                ld[n-a+i]--;
                rd[2*n+1-i-a]--;
            }
        }
    }
}
void print(void){
    if (total < 3) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ",line[i]);
        }
        printf("\n");
    }
    total++;
}