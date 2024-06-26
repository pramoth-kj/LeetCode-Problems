bool isNStraightHand(int* hand, int handSize, int groupSize) {
    
}int
compar(const void* a, const void* b)
{

	return *(int *)a == *(int *)b ? 0 : *(int *)a < *(int *)b ? -1 : 1;
}

void
gnome(int *const arr, const int arrSize)
{
	int i, tmp;

	for (i = 1; i < arrSize;)
		if (i == 0 || arr[i - 1] <= arr[i]) {
			++i;
		} else {
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[--i] = tmp;
		}
}

bool
isNStraightHand(int *const hand, int handSize, const int W)
{
	int key, i, *p;

	if (handSize == 1 || W == 1)
		return true;
	if (handSize % W != 0)
		return false;
	qsort(hand, handSize, sizeof(int), compar);
	while (handSize != 0) {
		key = hand[0];
		for (i = 0; i < W; ++i) {
			p = bsearch(&key, hand, handSize, sizeof(int), compar);
			if (p == NULL)
				return false;
			*p = hand[--handSize];
			gnome(hand, handSize);
			++key;
		}
	}

	return true;
}