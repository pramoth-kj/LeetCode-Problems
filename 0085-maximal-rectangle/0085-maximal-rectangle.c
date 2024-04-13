int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int* mergeheight = calloc(*matrixColSize, sizeof(int));
    int* stack = malloc((*matrixColSize + 1) * sizeof(int));
    int ret = 0, i = 0, j = 0, idx = -1;

    for(i = 0; i < matrixSize; i++) {
        for(j = 0; j < *matrixColSize; j++) {
            mergeheight[j] = (matrix[i][j] == '0')? 0 : mergeheight[j] + 1;
        }
        for(j = 0; j <= *matrixColSize; j++) {
            while(idx >= 0 && (j == *matrixColSize || mergeheight[stack[idx]] > mergeheight[j])) {
                int height = mergeheight[stack[idx--]];
                int width = (idx < 0)? j : j - stack[idx] - 1;
                ret = (ret > height * width)? ret : height * width;
            }
            stack[++idx] = j;
        }
        idx = -1;
    }

    return ret;
}