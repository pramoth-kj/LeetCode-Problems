int maxSubArray(int* nums, int numsSize){
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    for(int i = 1; i < numsSize; i++) {
        maxEndingHere = fmax(maxEndingHere + nums[i], nums[i]);
        maxSoFar = fmax(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}