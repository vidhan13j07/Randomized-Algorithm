import matplotlib.pyplot as plt
import pandas as pd
import random
import numpy as np
from random import randint

def Partition(array,first,last,comparisons,a,b):
    pivot=randint(first,last)
    array[pivot],array[last] = array[last],array[pivot]
    newPivotElement=first-1
    if (pivot == a and first <= b and b <= last ) or (pivot == b and first <= a and a <= last ):
            comparisons[0] += 1;
    for index in xrange(first,last):
        if array[index]<array[last]:#check if current val is less than pivot value
            newPivotElement=newPivotElement+1
            temp=array[newPivotElement]
            array[newPivotElement]=array[index]
            array[index]=temp
    temp=array[newPivotElement+1]
    array[newPivotElement+1]=array[last]
    array[last]=temp
    return newPivotElement+1


def RandomQuickSort(array,first,last,comparisons,a,b):
    if first<last:
        pivot_Element=randint(first,last)
        array[pivot_Element] ,array[last] = array[last],array[pivot_Element]
        pivot=Partition(array,first,last,comparisons,a,b)
        RandomQuickSort(array,first,pivot-1,comparisons,a,b)
        RandomQuickSort(array,pivot+1,last,comparisons,a,b)


def probability(z,a,b):
    comparisons = [0]
    for element in range(z):
        RandomQuickSort(array,0,len(array)-1,comparisons,a,b)
    return comparisons[0]*1.0/k


array = np.random.randint(100,size=(100))
array = array.tolist()

ab = []
probability_list = []
for value in range(4):
    ab.append(random.sample(xrange(1,len(array)-1), 2))
    
k = 1000
act = []
for element in ab:
    act.append(2.0/(abs(element[0]-element[1])+1))
    random.shuffle(array)
    alpha = []
    for iterations in range(10):
        alpha.append(probability(k,element[0],element[1]))
    probability_list.append(alpha)
    
print probability_list
print act
import matplotlib.pyplot as plt

theFile = open('1_b_output_probability.txt','w')
	for item in probability_list:
		theFile.write("{}\n".format(item))

theFile2 = open('1_b_output_act.txt','w')
	for item in act:
		theFile.write("{}\n".format(item))
