# -*- coding: utf-8 -*-
"""
Created on Sat Aug 26 01:31:29 2023

@author: Jose Antonio Martinez
"""
mul1=0;mul2=0; res=0;

print("Escribe el primer numero de la multiplicacion")
mul1 = int(input())
print("Escribe el segundo numero de la multiplicacion")
mul2 = int(input())

print("Mitad\t | \tDoble")
print("---------------------")
while True:
    if mul1 % 2 == 1:
        res = res + mul2
    print(mul1,"\t | \t", mul2)
    mul1 = int(mul1 / 2)
    mul2 = mul2 * 2
    if mul1 < 1:
        break
print("---------------------")
print("El resultado es:", res)
