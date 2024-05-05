//Iterate the array twice. Once for prefix product and once for postfix product
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    
    int* ret = (int*) malloc (numsSize*sizeof(int));
    memset (ret, 0, numsSize*sizeof(int));
    *returnSize = numsSize;
    int postfix = 1;
    ret[0]   = 1;
    for (int i =1; i < numsSize; i++) {
        ret[i] = nums[i-1]*ret[i-1];
    }
    
    for (int i = numsSize -2; i >= 0; i--) {
        postfix *= nums[i+1];
        ret[i] *= postfix;
    }
    
    return ret;
}