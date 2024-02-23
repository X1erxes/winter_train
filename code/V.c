#include <stdio.h>

#define MAXCOUNT 100000
#define MAXSEARCH 10000


void inputData(int[], int);
int searchData(int, int[], int, int);
void sortWithOrder(int[], int[], int);


int main(void) {
    int m, n;
    int numList[MAXCOUNT], searchList[MAXSEARCH];
    int searchOrder[MAXSEARCH], resultList[MAXSEARCH];

    scanf("%d %d", &n, &m);

    inputData(numList, n);
    inputData(searchList, m);

    for (int i = 0; i < m; i++) {
        searchOrder[i] = i;
    }
    sortWithOrder(searchList, searchOrder, m);

    

    int maxRight = n - 1;
    for (int i = 0; i < m; i++) {
        int position;
        position = searchData(searchList[i], numList, 0, maxRight);
        if (position != -1) {
            maxRight = position;
        }
        resultList[searchOrder[i]] = position;
    }

    for (int i = 0; i < m; i++) {
        if (resultList[i] == -1) {
            printf("-1 ");
        }
        else
        {
            printf("%d ", resultList[i] + 1);

        }
    }
    return 0;
}


void inputData(int l[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", l + i);
    }
}

int searchData(int num, int l[], int left, int right) {

    while (left <= right) {

        if (num < l[left] || num > l[right]) {
            return -1;
        }

        if (num == l[left]) {
            return left;
        }
        int mid = (left + right) / 2;
        if (l[mid] == num){
            if (searchData(num, l, left, mid - 1) == -1) {
                return mid;
            }
            else {
                return searchData(num, l, left, mid - 1);
            }

        }
        else if (l[mid] < num) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
    return -1;


}


void sortWithOrder(int l[], int ord[], int n) {

    for (int i = 0; i < n; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (l[max_index] <= l[j]) {
                max_index = j;
            }
        }
        if (i != max_index) {
            int tmp;
            tmp = l[i];
            l[i] = l[max_index];
            l[max_index] = tmp;

            ord[i] = max_index;
            ord[max_index] = i;
        }
    }
}