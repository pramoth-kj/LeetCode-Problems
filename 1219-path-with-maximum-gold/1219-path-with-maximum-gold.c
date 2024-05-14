#define MAX(a,b) (a)>=(b)?(a):(b)

typedef struct { int** g; int row; int* cols; } Grid_t;

int traverseMaximum(Grid_t* grid, int i, int j) {
    int max=0, temp, curr=grid->g[i][j]; grid->g[i][j]=0;

    if(i-1>=0&&grid->g[i-1][j]!=0)
    { temp=traverseMaximum(grid, i-1, j); max=MAX(max, temp); }
    if(i+1<grid->row&&grid->g[i+1][j]!=0)
    { temp=traverseMaximum(grid, i+1, j); max=MAX(max, temp); }
    if(j-1>=0&&grid->g[i][j-1]!=0)
    { temp=traverseMaximum(grid, i, j-1); max=MAX(max, temp); }
    if(j+1<grid->cols[i]&&grid->g[i][j+1]!=0)
    { temp=traverseMaximum(grid, i, j+1); max=MAX(max, temp); }

    grid->g[i][j]=curr; return max+curr;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    int max=0, temp; Grid_t g=(Grid_t){grid, gridSize, gridColSize};

    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<gridColSize[i]; j++) {
            if(grid[i][j]==0){ continue; }
            temp=traverseMaximum(&g, i, j);
            max=MAX(max, temp);
        }
    }

    return max;
}