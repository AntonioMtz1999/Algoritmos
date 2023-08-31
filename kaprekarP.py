# -*- coding: utf-8 -*-
"""
Created on Sat Aug 26 02:37:24 2023

@author: Jose Antonio Martinez
"""
print("Escribe un numero de 4 digitos diferentes:")
sNum = input()
num = int(sNum)
numR = 0
for k in range(99):
    sNum = "{:04d}".format(num)
    sNumG="".join(sorted(sNum,reverse=True))
    sNumP="".join(sorted(sNum))
    num=int(sNumG)-int(sNumP)
    print(sNumG,sNumP,num,"({:02d})".format(k+1))
    if num == numR:
        break
    numR=num
print("---------------------")
print("Iteraciones",k+1)
