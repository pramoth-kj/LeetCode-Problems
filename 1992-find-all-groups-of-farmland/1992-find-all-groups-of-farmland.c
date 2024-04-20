/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes) {
    int memSize=(landSize*landColSize[0])/2+1; *returnSize=0;
    *returnColumnSizes=malloc(memSize*sizeof(int));
    int** result=malloc(memSize*sizeof(int*));

    for(int i=0, j, x, y; i<landSize; i++) {
        for(j=0; j<landColSize[i]; j++) {
            /* skip the zeroes */
            if(land[i][j]==0){ continue; }

            /* clear the ones */
            for(x=i; x<landSize&&land[x][j]==1; x++)
            { for(y=j; y<landColSize[x]&&land[x][y]==1; y++){ land[x][y]=0; }}

            /* append to result */
            result[*returnSize]=malloc(4*sizeof(int));
            result[*returnSize][0]=i; result[*returnSize][1]=j;
            result[*returnSize][2]=x-1; result[*returnSize][3]=y-1;
            (*returnColumnSizes)[(*returnSize)++]=4;
        }
    }

    return result;
}