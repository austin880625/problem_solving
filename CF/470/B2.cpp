#include<bits/stdc++.h>

using namespace std;

int n, MEMO, ans, MMEMO;
bool flag, NOTPRIME[1000010];

int fact(int idx) {
    int tmp = idx;
    if(!NOTPRIME[tmp])
        return n;
    while(tmp % 2 == 0) {
        tmp /= 2;
        MMEMO = 2;
    }
    for(int i = 3 ; i <= n ; i += 2) {
        if(tmp == 1)
            break;
        if(NOTPRIME[i])
            continue;
        while(tmp % i == 0) {
            tmp /= i;
            MMEMO = i;
        }
        if(!NOTPRIME[tmp]) {
            MMEMO = tmp;
            break;
        }
    }
    return idx - MMEMO + 1;
}

void ffact(int idx) {
    int tmp = idx;
    while(tmp % 2 == 0) {
        tmp /= 2;
        MEMO = 2;
    }
    for(int i = 3 ; i <= n ; i += 2) {
        if(tmp == 1)
            break;
        if(NOTPRIME[i])
            continue;
        while(tmp % i == 0) {
            tmp /= i;
            MEMO = i;
        }
        if(!NOTPRIME[tmp]) {
            MEMO = tmp;
            break;
        }
    }
}

int main() {
    scanf("%d",&n);
    ans = n;
    NOTPRIME[1] = 1;
    for(int i = 4 ; i <= n ; i+=2)
        NOTPRIME[i] = 1;
    for(int i = 3 ; i * i <= n ; i += 2) {
        if(NOTPRIME[i])
            continue;
        for(int j = i * i ; j <= n ; j += i)
            NOTPRIME[j] = 1;
    }
    ffact(n);
    for(int i = n ; i > n - MEMO; i--)
        ans = min(ans , fact(i));
    printf("%d\n",ans);
    return 0;
}
