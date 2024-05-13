int matrixScore(int** grid, int gridSize, int* gridColSize){
    if(!grid)
        return 0;
    
    int leng = gridColSize[0];
    int i, j;
    for(i=0;i<gridSize;i++){
        if(grid[i][0]==0){
            for(j=0;j<leng;j++){
                grid[i][j] ^= 1;
            }
        }
    }
    for(i=0;i<leng;i++){
        int zero = 0;
        int one = 0;
        for(j=0;j<gridSize;j++){
            if(grid[j][i] == 0)
                zero++;
            else
                one++;
        }

        if(zero>one){
            for(j=0;j<gridSize;j++){
                grid[j][i] ^= 1;
            }
        }
    }

    int ret = 0;
    for(i=0;i<gridSize;i++){
        int temp = 0;
        for(j=0;j<leng;j++){
            temp *= 2;
            temp += grid[i][j];
        }
        ret += temp;
    }
    return ret;
}


// 1- if first bit is 0 then xor ever column bit.
// if more bits is 0 then xor every row bit.