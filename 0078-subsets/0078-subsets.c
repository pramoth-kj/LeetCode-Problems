/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(!nums)
        return NULL;
    int total = 1<< numsSize;
    int** ret = malloc(sizeof (int*) * total);
    *returnSize = total;
    *returnColumnSizes = malloc(sizeof(int) * total);
    ret[0] = NULL;
    (*returnColumnSizes)[0] = 0;
    for(int i=1;i<total;i++){
        int temp = i;
        int count = 0;
        while(temp){
            count += temp%2;
            temp /= 2;
        }
        (*returnColumnSizes)[i] = count;

        ret[i] = malloc(sizeof(int)*count);
        temp = i;
        int ch = 0;
        for(int j=0;j<count;j++){
            while(temp%2!=1){
                temp/=2;
                ch++;
            }
            ret[i][j] = nums[ch];
            ch++;
            temp/=2;
        }
    }

    return ret;
}