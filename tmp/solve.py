def miller_rabin(p):
	if p==2: return True
	if p%2==0: return False
	else:
		d=p-1
		s=0
		while d%2==0:
			d//=2
			s+=1
		for a in [2,3,5,7,11,13,17,19,23,29,31,37,41]:
			temp=[]
			for r in range(s):
				 temp.append(pow(a,d,p)!=1 and pow(a,2**r*d,p)!=(p-1))
		return not(all(temp))
		
for i in range(2, 10000):
	if miller_rabin(i): print(i)
