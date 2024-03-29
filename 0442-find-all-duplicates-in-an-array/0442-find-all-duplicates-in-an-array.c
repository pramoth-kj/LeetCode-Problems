/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    if (numsSize < 2 || nums == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int i, *ans = malloc(sizeof(int) * (numsSize / 2));
    *returnSize = 0;

    for (i = 0; i < numsSize; i++) {
        int number = abs(nums[i]);

        if (nums[number - 1] > 0)
            nums[number - 1] = -nums[number - 1];
        else
            ans[(*returnSize)++] = number;
    }

    return ans;
}