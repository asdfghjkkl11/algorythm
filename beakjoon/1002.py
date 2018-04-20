import math
time=input()
for i in range (0,int(time),1):

    str=input();
    num=str.split(" ")
    l=float(math.sqrt(pow(float(num[3])-float(num[0]),2)+pow(float(num[4])-float(num[1]),2)))
    if(float(num[2])>float(num[5])):
        big=float(num[2])
        small= float(num[5])
    else:
        big = float(num[5])
        small = float(num[2])
    if(big>l):
        if (l == 0 and big==small):
            print(-1)
        elif(l+small==big):
            print(1)
        elif(l+small<big):
            print(0)
        else:
            print(2)
    else:
        if(l==big+small):
            print(1)
        elif(l>big+small):
            print(0)
        else:
            print(2)
