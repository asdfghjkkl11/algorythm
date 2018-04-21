import math
def inR(x,y,a,b,r):
    D=pow(float(x)-float(a),2)+pow(float(y)-float(b),2)
    if(D<pow(float(r),2)):
        return True
    return False
time=input()
for i in range (0,int(time),1):
    str1=input()
    num1=str1.split(" ")
    str2=input()
    num2=[]
    N=0
    for i in range(0, int(str2), 1):
        str3=input()
        num2.append(str3.split(" "))
        A = inR(num1[0], num1[1], num2[i][0], num2[i][1], num2[i][2])
        B = inR(num1[2], num1[3], num2[i][0], num2[i][1], num2[i][2])
        if(A^B):
            N+=1
    print(N)
