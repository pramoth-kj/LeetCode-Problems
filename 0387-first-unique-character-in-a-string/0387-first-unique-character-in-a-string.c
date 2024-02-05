int firstUniqChar(char* s) {
    int charCounter[256] = {0};

	for (int i = 0; s[i] != 0; i++) {
		charCounter[(unsigned char) s[i]]++;
	}
	for (int i = 0; s[i] != 0; i++) {
		if (charCounter[(unsigned char) s[i]] == 1) {
			return i;
		}
	}
	return -1;
}