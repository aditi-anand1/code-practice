import random
import time

dyn_lst=[]
dyn_ans=[]
sim_ans=[]

def find_max(lst):
    maximum=0
    for i in lst:
        if i > maximum:
            maximum=i
    return maximum
def dyn_fact(maximum):
    final_lst=[]
    final_lst.append(1)
    for i in range(1,maximum+1):
        print(i)
        y=final_lst[i-1]*i
        final_lst.append(y)
    return final_lst

def execute(lst):
    ex_time = time.time()
    maxi = find_max(lst)
    final_list = dyn_fact(maxi)

    for i in lst:
        dyn_ans.append(final_list[i])
    
    ex_end = time.time()
    print('DYNAMIC FACTORIAL TOOK: ', ex_end - ex_time)


def simple_fact(lst):
    sf_time = time.time()
    pro=1
    for i in lst:
        for j in range(1,i+1):
            pro=pro*j
            sim_ans.append(pro)
        pro=1
    sf_end = time.time()
    print('SIMPLE FACTORIAL TOOK: ', sf_end - sf_time)

n=int(input("how many test case you want "))
lst=[]
for i in range(n):
    x=random.randrange(1,n,1)
    lst.append(x)
execute(lst)
simple_fact(lst)




