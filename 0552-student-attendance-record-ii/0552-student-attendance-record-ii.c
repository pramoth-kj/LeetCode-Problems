int checkRecord(int n) {
    int MOD = 1000000000 + 7;
    int oldDP[2][3] = {{1, 1, 1}, {1, 1, 1}};

    for(int i = 1;i <= n;i++)
    {
        int newDP[2][3] = {{0, 0, 0}, {0, 0, 0}};
        for(int a = 0; a < 2;a++)
        {
            for(int l = 0;l < 3;l++)
            {
                newDP[a][l] += oldDP[a][2];
                newDP[a][l] %= MOD;

                if(a > 0)
                {
                    newDP[a][l] += oldDP[a - 1][2];
                    newDP[a][l] %= MOD;
                }
                if(l > 0)
                {
                    newDP[a][l] += oldDP[a][l -1];
                    newDP[a][l] %= MOD;
                }
            }
        }
        for(int x = 0;x < 2;x++)
            for(int y = 0;y < 3;y++)
                oldDP[x][y] = newDP[x][y];

    }    
    return oldDP[1][2];
}