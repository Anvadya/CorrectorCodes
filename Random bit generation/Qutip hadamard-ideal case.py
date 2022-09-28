from qutip.measurement import measure, measurement_statistics
from qutip import *
import math as mt


spin_z=sigmaz()
up=basis(2,0)
down=basis(2,1)
upd=up*up.dag()
downd=down*down.dag()
updb=upd
downdb=downd

Had_gate=[[ 1/mt.sqrt(2), 1/mt.sqrt(2)],[1/mt.sqrt(2),-1/mt.sqrt(2)]]
#Had_gate=[[ 1, 1],[1,-1]]
Had_gateQ=Qobj(Had_gate)
#Had_gateQ=Had_gateQ.unit()
file1 = open("ideal case_qutipup.txt","a")#append mode
bit=""
for kJ_1 in range(0,2*10**2):
    
    
    a1=Had_gateQ*up
    a2=measurement_statistics(a1,spin_z)
    
    am=measure(a1, spin_z)

    up=am[1]
    #print(up)
    upd=up*up.dag()
    #print(down)
    if(upd==updb):
        bitd=0
        bit += str(bitd)
    elif(upd==downdb):
        bitd=1
        bit += str(bitd)
    
file1.write(str(bit))
file1.close()