typedef struct {
    long long first;
    long long second;
} pair;

long long maximumValueSum(int* nums, int n, int k, int** edges, int edgesSize, int* edgesColSize) {
    pair *dp = calloc(n + 1, sizeof(pair));
    dp[n].first = 0;
    dp[n].second = INT_MIN;
    for(int i = n - 1; i >= 0; i--) {
        dp[i].first = fmax(
            dp[i + 1].second + (nums[i] ^ k),
            dp[i + 1].first + nums[i]
            );
        dp[i].second = fmax(
            dp[i + 1].first + (nums[i] ^ k),
            dp[i + 1].second + nums[i]
        );
    }
    return dp[0].first;
}