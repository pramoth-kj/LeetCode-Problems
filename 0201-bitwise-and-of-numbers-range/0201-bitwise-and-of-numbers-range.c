int rangeBitwiseAnd(int m, int n)
{
	if (0 == m)
		return 0;
	int k = (m & n);
	int bit[32] = { 0 }; 
	int i = 31, ret = 0;
	int dif = n - m;
	int bitdif = 0;
	for (; i >= 0; --i) //transfer (m & n) into 32 bit array.
	{
		if (k & 1)
			bit[i] = 1;
		k = k >> 1;
		if (!k)
			break;
	}

	for (; dif; dif = dif >> 1, ++bitdif); //calculate the binary 'length' of 'm-n'

	for (i = 31; i > (31 - bitdif); --i)  //let all digits (started from tail) in the 'length' = 0
		bit[i] = 0;

	for (i; i >= 0; --i)
	{
		if (bit[i])
			ret += 1 << (31 - i);
	}
	return ret;
}