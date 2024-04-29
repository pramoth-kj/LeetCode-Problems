int minOperations(int nums[], int size, int k) {
    int xorSum = 0;
    for (int i = 0; i < size; i++) {
        xorSum ^= nums[i];
    }

    int result = 0;
    k ^= xorSum;

    while (k > 0) {
        result += k & 1;
        k >>= 1;
    }

    return result;
}