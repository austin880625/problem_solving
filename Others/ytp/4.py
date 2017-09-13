import math;
def dis(a,b):
    ax=a/10;
    ay=a%10;
    bx=b/10;
    by=b%10;
    return sqrt((ax-bx)**2+(ay-by)**2);
def split(str):
    l=1;
    a=[];
    for r in range(len(str)):
        if(str[r]==','):
            a.append(int(str[l:r]));
            l=r;
    a.append(int(str[l:]));
    return a;

s=input();
type(s);
a=map(split(str(s)),int);
tar=a[0];
sor=a[1:];
ans=0;
for x in sor:
    if(dis(x,tar)<=5):
        ans+=5-dis(x,tar);
if a<10:
    print "0"+a;
else:
    print a;
