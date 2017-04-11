import pandas as pd
import numpy as np
import matplotlib.pyplot as plt 

file = '1_b_output_probability.txt'

probability_list = []
with open(file) as f:
	for line in f:
		line = line.strip()
		probability_list.append(line)
act = []
file2 = '1_b_output_act.txt'
act_list = []
with open(file2) as f:
	for line in f:
		line = line.strip()
		act.append(line)

print probability_list
print act
fig1 = plt.figure()
plt.plot(range(0,len(probability_list[0])),probability_list[0],'+',range(0,len(probability_list[0])),[act[0]]*10,'b--')
axes = plt.gca()
axes.set_ylim([0,.5])
fig1.savefig('graph1.eps')
fig2 = plt.figure()
plt.plot(range(0,len(probability_list[1])),probability_list[1],'+',range(0,len(probability_list[1])),[act[1]]*10,'y--')
axes = plt.gca()
axes.set_ylim([0,.5])
fig2.savefig('graph2.eps')
fig3 = plt.figure()
plt.plot(range(0,len(probability_list[2])),probability_list[2],'+' ,range(0,len(probability_list[2])),[act[2]]*10,'r--')
axes = plt.gca()
axes.set_ylim([0,.5])
fig3.savefig('graph3.eps')
fig4  = plt.figure()
plt.plot(range(0,len(probability_list[3])),probability_list[3],'+' ,range(0,len(probability_list[3])),[act[3]]*10,'g--')
axes = plt.gca()
axes.set_ylim([0,.5])
fig4.savefig('graph4.eps')
	



