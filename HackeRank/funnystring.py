for _ in range(int(input())):
	s = input()
	a = [ord(x) for x in s]
	l = len(a)
	for i in range(l // 2):
		if abs(a[i] - a[i + 1]) != abs(a[-i-1] - a[-i-2]):
			print('Not Funny')
			break
	else:
		print('Funny')      



