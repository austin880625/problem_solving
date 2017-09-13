f=[]
f.append(0)
f.append(1)
for i in range(2,5005):
    f.append(f[i-1]+f[i-2])
while 1:
    try:
        n=int(input())
    except EOFError:
        quit()
    if n==None:
        break
    print ('The Fibonacci number for {} is {}'.format(n,f[n]))
