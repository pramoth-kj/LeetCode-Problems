long long wonderfulSubstrings(char * word){
    int n = strlen(word) ;
    int* count = calloc(1 << 10, sizeof(int)) ;
    count[0] = 1 ;
    int state = 0 ;
    long long ret = 0 ;
    for(int i = 0; i < n; i++){
        int k = word[i] - 'a' ;
        state ^= (1 << k) ;
        ret += count[state] ;
        for(int j = 0; j < 10; j++){
            int stateJ = state ^ (1 << j) ;
            ret += count[stateJ] ;
        }
        count[state]++ ;
    }
    free(count) ;
    return ret ;
}