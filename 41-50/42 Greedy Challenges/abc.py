n = int(input())
m = int(input())
p = int(input())
ben = 0
while(n > 0 and m > 0 and p > 0):
    n -= 1
    m -= 1
    p -= 1
    ben += 1


while(n > 0 and m > 0):
    if(n > m):
        n -= 2
        m -= 1
        ben += 1
    else:
        n -= 1
        m -= 2
        ben += 1
if(n >= 0 and m >= 0):
    print(ben)
else:
    print(ben-1)
