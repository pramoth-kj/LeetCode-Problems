bool checkSubarraySum(int* nums, int numsSize, int k){
    if (numsSize == 1) return false;
    else if (k == 1) return true;
    
    bool *map = calloc(k, sizeof(bool)); 
    // using bool-type would save u some memory
    int sum = 0;    

    for(int i = 0; i < numsSize; i++){
        if (nums[i] % k == 0){  
            // return true if encounter at least two conterminous k's multiple
            // else we do not do any hashing
            if (i < numsSize-1 && nums[i+1] % k == 0) return true;
            else continue;
        }
        sum += nums[i]; // accumulate the array
        if (sum % k == 0) return true;
        else if (map[sum % k] > 0) return true;
        map[sum % k] = 1;
    }
    free(map);
    return false;
}