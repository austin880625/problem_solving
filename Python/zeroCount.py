t=0
for i in range(1,1001):
    s=str(i);
    for c in s:
        if c=='0':
            t+=1
print(t)