#!/usr/bin/python
def select( arr) :
	c = int(0) 
	prev = int(0)
	for st , en in arr :
		if (prev <= st ) :
			 c = c + 1 
			 prev = en
	return c ;
s = input() 
start = [int(i) for i in s.split(' ') if i.isdigit()] 
s = input() 
finish = [int(i) for i in s.split(' ') if i.isdigit()] 

arr = zip(  start , finish);
arr = sorted(arr, key=lambda arr:arr[1])
for num in arr :
	print(num)
print(select(arr) )
