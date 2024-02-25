#include <stdio.h>

#define MAX 1000
int team[MAX+5] = {0},opponent[MAX+5] = {0};
int main (void) {

    int n,m,num1,num2,sum = 0;
    char tmp;
    scanf("%d %d",&n,&m);

    for (int i = 1; i <= 2*n; ++i) {
        team[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        while (getchar() != '\n');
        scanf("%c %d %d",&tmp,&num1,&num2);
        if (tmp == 'E') {
            team[find(num1+n)] = find(num2);
            team[find(num2+n)] = find(num1);
        } else team[find(num1)] = find(num2);
    }


    for (int i = 1; i <= n; ++i) {
            if (team[i] == i) sum++;
    }

    printf("%d\n",sum);
    return 0;
}
int find(int num) {
    if (team[num] != num) team[num] = find(team[num]);
    return team[num];
}