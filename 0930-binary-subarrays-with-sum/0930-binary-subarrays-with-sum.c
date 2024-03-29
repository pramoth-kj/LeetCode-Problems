int numSubarraysWithSum(int* nums, int numsSize, int goal){
    int n = numsSize;
    int N = n + 1;
    int** hashMap = calloc(N, sizeof(int*));
    int sum = 0;
    int rm, d;
    hashMap[0] = malloc(2 * sizeof(int));
    hashMap[0][0] = 0;
    hashMap[0][1] = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        rm = sum - goal;
        d = rm;
        while(1 && rm >= 0){
            if(hashMap[d % N] == NULL)
                break;
            else if(hashMap[d % N][0] == rm){
                ans += hashMap[d % N][1];
                break;
            }
            else
                d++;
        }
        d = sum;
        while(1){
            if(hashMap[d % N] == NULL){
                hashMap[d % N] = malloc(2 * sizeof(int));
                hashMap[d % N][0] = sum;
                hashMap[d % N][1] = 1;
                break;
            }
            else if(hashMap[d % N][0] == sum){
                hashMap[d % N][1]++;
                break;
            }
            else
                d++;
        } 
    }
    return ans;
}