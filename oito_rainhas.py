# --coding: utf-8 --

cont = 0
tab = [0, 0, 0, 0, 0, 0, 0, 0]

def valida(c, i):
	for j in range(c):
		if tab[j] == i:
			return 0
		if tab[j]-j == i-c:
			return 0
	return 1



def back(c):
	global cont
	print c
	if c==8:
		cont += 1
		print("{} - ".format(cont))
		for i in range(8):
			print("{} ".format(tab[i]+1))
		print("\n\n")
		return 1

	for i in range(8):
		if valida(c,i):
			tab[c]=i
			if back(c+1):
				return 1
			tab[c]=0
	return 0



back(0)

