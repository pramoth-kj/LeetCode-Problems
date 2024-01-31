/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* results = malloc((*returnSize=temperaturesSize) * sizeof(int));
    int stackV[temperaturesSize], stackI[temperaturesSize], stackSize=0;

    for(int i=0; i<temperaturesSize; i++){
        results[i] = 0;
        while(stackSize>0 && stackV[stackSize-1]<temperatures[i]) {
            results[stackI[stackSize-1]] = i-stackI[stackSize-1];
            stackSize--;
        }
        stackV[stackSize] = temperatures[i];
        stackI[stackSize] = i;
        stackSize++;
    }

    return results;
}