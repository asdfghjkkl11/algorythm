fibo=[[1,0],[0,1]]
def fibonacci(n):
    if(n<len(fibo)):
        return fibo[n]
    else:
        f1=fibonacci(n-1)
        f2=fibonacci(n-2)
        f3=[]
        f3.append(f1[0] + f2[0])
        f3.append(f1[1] + f2[1])
        fibo.append(f3)
        return fibo[n]
import math
time=input()
for i in range (0,int(time),1):

    str1=input()
    num=int(str1)
    F=fibonacci(num)
    print(str(F[0])+" "+str(F[1]))
