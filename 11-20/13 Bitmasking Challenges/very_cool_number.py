n,k=map(int,input().split())
cool =0

for i in range(1,n+1):
    s=bin(i).lstrip("0b")
    count=0
    while True:
        try:
            idx=s.index('101')
            count+=1
            s=s[idx+2:]
        except:
            break
    if(count >=k):
        cool+=1
print(cool)