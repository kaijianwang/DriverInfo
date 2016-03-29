import os
import sys

f = open('test.txt','r').readlines()
i=0
for t in f:
    t=t.replace('\n','')
    command = t.split(' ')[0]
    help = t[t.find(command)+command.__len__():]
    print ' TKAFG1K_VAL_WFM_%s (%d)\n  \"%s\"\n'%(command.upper(),i+1004,help)
    i+=1
i=0
for t in f:
    t=t.replace('\n','')
    command = t.split(' ')[0]
    print '#define TKAFG1K_VAL_WFM_%s										(IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + %d) '%(command.upper(),i+4)
    i+=1
i=0
for t in f:
    t=t.replace('\n','')
    command = t.split(' ')[0]
    print '		{TKAFG1K_VAL_WFM_%s, 0, 0, \"%s\", 0}, '%(command.upper(),command)
    i+=1


#
# while i<=255 :
#     print ' TKAFG1K_VAL_WFM_USER%d (%d)\n  \"Configures the function generator with a user4 waveform.\"\n'%(i,i+10002)
#     i+=1
