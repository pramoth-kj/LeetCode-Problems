int numSubarrayProductLessThanK(int* A, int n, int k){
    int mul = 1;
    int count = 0;
    int i,j;
    for(i = j = 0 ; i < n ; i++){
        mul *= A[i];
        count += i-j;
        while(j<=i && mul>=k){
            mul /= A[j++];
        }
    }
    return count + i - j;
}