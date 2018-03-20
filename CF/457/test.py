ans=0
s=0
while True:
    try:
        x=list(map(int, input().split()))
        for t in x:
            ans+=2**int(t)
            s+=1
    except EOFError:
        break
print(ans)
print(s)
