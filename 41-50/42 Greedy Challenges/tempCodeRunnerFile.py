s = input()
c=list(map(int,input().split()))
cost = 0
s=list(s)
i=0
while(i<len(s)-1):
    if s[i]==s[i+1]:
        s.pop(i)
        cost+=c[i]
        c.pop(i)
    i+=1
print(cost)