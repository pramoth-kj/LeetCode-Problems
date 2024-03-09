int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int getCommon(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int minCommon = -1;
    int i = 0, j = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            if (minCommon == -1 || nums1[i] < minCommon) {
                minCommon = nums1[i];
            }
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return minCommon;
}
