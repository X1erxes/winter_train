#include <stdio.h>
#include <string.h>

#define MAX 200000
int main() {

    int i = 0;
    char tmp,t1 = '\0',t2 = '\0',ret[MAX+5];
    tmp = getchar();
    while (tmp != '\n') {
        if (tmp == 'C' && t2 == 'A' && t1 == 'B') {
            ret[--i] = '\0';
            ret[--i] = '\0';
            t2 = ret[i-2];
            t1 = ret[i-1];
            tmp = getchar();
            continue;
        }
        t2 = t1;
        t1 = tmp;
        ret[i] = tmp;
        i++;
        tmp = getchar();
    }
    printf("%s\n",ret);
    return 0;
}