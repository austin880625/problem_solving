import math
prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61]
length = len(prime)
dp = []
for i in range(20):
    dp.append([])
    for j in range(length):
        dp[i].append(0)
def calc(i,n,p):
    if(n==0):
        return 1
    if(n<=2 and p==0):
        return 2
    if(dp[i][p]!=0):
        return dp[i][p]
    l = 1+int(math.floor(n**(1./prime[p])))
    if(l**prime[p]<=n):
        l+=1
    if((l-1)**prime[p]>n):
        l-=1
    tmp=l
    #print(tmp)
    for j in range(p):
        d=calc(i+1, tmp-1, j)
        l-=d-1
    dp[i][p] = l
    return l;
    
q = int(input())
for i in range(q):
    l,r = map(int,input().split())
    ans = 0
    for p in range(length):
        #print(calc(r,p), calc(l-1,p))
        for j in range(7):
            for k in range(length):
                dp[j][k]=0
        d = calc(0, r, p) 
        for j in range(7):
            for k in range(length):
                dp[j][k]=0

        d -= calc(0, l-1, p)
        ans +=d
        if(d == 0):
            break
    print(ans)
