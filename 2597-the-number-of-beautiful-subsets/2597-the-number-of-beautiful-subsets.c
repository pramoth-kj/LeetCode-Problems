#define ABS(a) (a < 0 ? -a : a)

int beautifulSubsets(int* nums, int numsSize, int k) {
    int size = 1 << numsSize, count = 0;

    for(int i = 1, flag; i < size; i++){
        int *store = (int*)malloc(numsSize * sizeof(int));
        flag = 1;

        for(int j = 0, l = 0; j < numsSize && flag; j++)
            if(i & (1 << j)){
                for(int m = 0; m < l && flag; m++)
                    if(ABS((store[m] - nums[j])) == k)
                        flag = 0;

                store[l++] = nums[j];
            }
        
        if(flag)
            count++;

        free(store); 
    }
    
    return count;
}