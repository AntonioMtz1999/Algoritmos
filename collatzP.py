# -*- coding: utf-8 -*-
"""
Created on Sat Aug 26 00:10:59 2023

@author: Jose Antonio Martinez
"""
print ("Escribe un numero para la conjetura de collatz: ")
num = int(input())
conteo = int(1)
while num != 2:
    print (conteo, ".-", num)
    
    if num % 2 == 0:
        num = int(num / 2)
    else:
        num = int((3 * num) + 1)
        
    conteo  = int(conteo + 1)
    pass
    

