# -*- coding: utf-8 -*-
"""
Created on Sat Aug 26 01:03:17 2023

@author: Jose Antonio Martinez
"""
mul1=0; mul2=0; res=0; cons=1

print("Escribe el primer numero de la multiplicacion")
mul1 = int(input())
print("Escribe el segundo numero de la multiplicacion")
mul2 = int(input())

print("Doble\t | \tDoble")
print("---------------------")

while True:
    print(mul1,"\t | \t", cons)
    mul1 = int(mul1 * 2)
    cons = int(cons * 2)
    if cons > mul2:
       break
   
mul1 = int(mul1 /2)
cons = int(cons /2)
acum = 0
while cons > 0:
    if (acum+cons) <= mul2:
        res = res + mul1
        acum = acum + cons
    mul1 = int(mul1/2)
    cons = int(cons / 2)
    
print("---------------------")
print("El resultado es:", res)

"""Para el caso de utilizarlo en la consola descomentar el input"""
"""input()"""