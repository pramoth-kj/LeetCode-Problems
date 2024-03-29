long long countSubarrays(int* nums, int numsSize, int k) {
    long long result=0;

    for(int i=0, skip=0, max=nums[0], count=0; i<numsSize; i++) {
        if(nums[i]>max){ max=nums[i]; count=1; result=0; skip=0; }
        else if(nums[i]==max){ count++; } else { continue; }
        
        for(; count==k; count-=(nums[skip++]==max))
        { result+=(numsSize-i); }
    }

    return result;
}