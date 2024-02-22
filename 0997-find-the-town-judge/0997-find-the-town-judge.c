int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    char trustee[n]; memset(trustee, 0, n*sizeof(char));
    short trusted[n]; memset(trusted, 0, n*sizeof(short));
    for(int i=0; i<trustSize; i++)
    { trustee[trust[i][0]-1]=1; trusted[trust[i][1]-1]++; }

    for(int i=0; i<n; i++)
    { if(!trustee[i] && trusted[i]==n-1){ return i+1; } }

    return -1;
}