int* findErrorNums(int* nums, int numsSize, int* returnSize){

    *returnSize = 2;
    int *ris = malloc(sizeof(int) * (*returnSize));
    int *hash = (int*)malloc(sizeof(int) * (numsSize+1));
    
    for(int i=0; i<=numsSize; i++)
    {
        hash[i] = 0;
    }
    
    for (int i=0; i<numsSize; i++)
    {
        hash[nums[i]]++;
    }
    
    for(int i=1; i<=numsSize; i++)
    {
        if( hash[i]>1 )
            ris[0] = i;
        
        if(hash[i] == 0)
            ris[1] = i;
    }
    return ris;
}