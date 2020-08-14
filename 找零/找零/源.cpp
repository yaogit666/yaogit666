int GetCoinCount(int N) {
	int n = 1024 - N;
	int count = 0;

	count += n / 64;
	n = n % 64;
	count += n / 16;
	n = n % 16;
	count += n / 4;
	n = n % 4;
	count += n;

	return count;
}
