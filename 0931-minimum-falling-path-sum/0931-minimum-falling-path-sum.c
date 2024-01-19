#define MIN(a, b) ((a) < (b)? (a): (b))
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
    int dr[] = {1, 1, 1};  
    int dc[] = {-1, 0, 1};
    int sum[matrixSize][*matrixColSize]; 
    for(int r = matrixSize-1, c = 0; c < *matrixColSize; c++) sum[r][c] = matrix[r][c]; 
    for(int r = matrixSize-2; r >= 0; r--){
        for (int c = 0; c < *matrixColSize; c++){
            sum[r][c] = INT_MAX;
            for(int d = 0; d < 3; d++){
                if (r+dr[d] < 0 || r+dr[d] >= matrixSize) continue;
                if (c+dc[d] < 0 || c+dc[d] >= *matrixColSize) continue;
                sum[r][c] = MIN(sum[r][c], matrix[r][c] + sum[r+dr[d]][c+dc[d]]);
            }
        }
    }
    int ans = INT_MAX;
    for(int r = 0, c = 0; c < *matrixColSize; c++){
        ans = MIN(ans, sum[r][c]);
    }
    return ans;
}