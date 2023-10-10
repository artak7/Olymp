z_func(string s)
	n = len(s)
	vector <int> z(n)
	for i = 1..n-1
		l = 0, r = 0
		if i <= r:
			z[i] = min(z[i-l], r - i + 1)
		while i+z[i] < n and s[z[i]] == s[i+z[i]]:
			z[i] += 1
		if i + z[i] - 1 > r
			l = i,
			r = i + z[i] - 1
	return z

строка t
подстрока p
найти вхождения строки t в строку p

s = p+'#'+t


префикс функция
prefix_func(string s)
	n = len(s)
	vector <int> pi(n)
	for i = 1..n-1
		for k = 0..i
			if s[0..k] == s[i-k+1..k]:
			#s.substr(0,k) == s.substr(i-k+1, k)
				pi[i] = k

	return pi

O(n*n)



prefix_func(string s)
	n = len(s)
	vector <int> pi(n)
	for i = 1..n-1
		j = pi[i - 1]
		while j > 0 and s[i] != s[j]
			j = pi[j - 1]
		if s[i] == s[j]
			j += 1
		pi[i] = j
		
	return pi
