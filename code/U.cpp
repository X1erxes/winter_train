#include<bits/stdc++.h>
using namespace std;

#define MAX 3000000
int arr[MAX+5] = {0},ans[MAX+5] = {0};
int main(){

    int n;
    stack<int> s;
    scanf("%d",&n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d",&arr[i]);
    }

    for (int i = n; i >= 1; --i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        if (!s.empty()) ans[i] = s.top();
        s.push(i);
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ",ans[i]);
    }
    return 0;
}