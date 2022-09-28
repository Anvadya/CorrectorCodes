# -*- coding: utf-8 -*-
"""
Created on Sat Apr 30 11:10:49 2022

@author: yesh
"""
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 26 13:31:21 2022

@author: yesh
"""

from qutip.measurement import measure, measurement_statistics
from qutip import *
import math as mt
import time

# @profile
def funct():
    spin_z=sigmaz()
    up=basis(2,0)
    down=basis(2,1)
    upd=up*up.dag()
    intial=[[ 0.46836986, 0.15677846-0.41414394j],[0.15677846+0.41414394j, 0.53163014]]  #down->up
    #intial=[[  0.53215179, -0.1569457 +0.414586j],[-0.1569457 -0.414586j, 0.46784821]]##up
    #intial=[[ 0.46836986, 0.15677846-0.41414394j],[0.15677846+0.41414394j, 0.53163014]]##down
    intialf=Qobj(intial)
    downd=down*down.dag()
    updb=upd
    downdb=downd



    file1 = open("Shortcut_QD_intialup_Noise_4mT_0.04mT .txt","a")#append mode
    bit=""
    for kJ_1 in range(0,120*10**6):
        
        
        am=measure(intialf,spin_z)

        up=am[1]
        #print(up)
        upm=up*up.dag()
        #print(down)
        if(upm==updb):
            #intial=[[ 0.49965381,-0.17681514+0.46705464j],[-0.17681514-0.46705464j,0.50034619]]#1T no noise
            #intial=[[ 0.46415088, 0.43199994-0.05413426j],[0.43199994+0.05413426j, 0.53584912]]#4T noise
            intialf=[[  0.53215179, -0.1569457 +0.414586j],[-0.1569457 -0.414586j, 0.46784821]]#4mT noise
            intialf=Qobj(intial)
            bitd=0
            # bit.append(bitd)
            bit += str(bitd)
        elif(upm==downdb):
            #intial=[[ 0.50034619, 0.17681514-0.46705464j],[0.17681514+0.46705464j, 0.49965381]]#1T no noise
            #intial=[[ 0.47771485, -0.48934979+0.06133554j],[-0.48934979-0.06133554j, 0.52228515]]#4T noise
            intialf=[[ 0.46836986, 0.15677846-0.41414394j],[0.15677846+0.41414394j, 0.53163014]]#4mT noise
            intialf=Qobj(intial)
            bitd=1
            # bit.append(bitd)
            bit += str(bitd)
        
    file1.write(bit)
    file1.close()

start = time.perf_counter()
funct()
end = time.perf_counter()
ms = (end-start) 
print(f"Elapsed {ms:.03f} secs.")