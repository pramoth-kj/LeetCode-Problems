/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumOfDistancesInTree(int N, int** edges, int edgesRowSize, int *edgesColSizes, int* returnSize) {
    int* res = malloc(sizeof(int) * (*returnSize = N));
    int parent[N], count[N];  
    memset(parent, 255, sizeof(parent));
    memset(res, 255, sizeof(count));
    memset(count, 0, sizeof(count));
    for (int i=0;i<edgesRowSize;i++) {
        if (parent[edges[i][1]] == -1)
            parent[edges[i][1]] = edges[i][0];
        else if (parent[edges[i][0]] == -1)
            parent[edges[i][0]] = edges[i][1];
        else {
            _change_root(parent, edges[i][0]);
            parent[edges[i][0]] = edges[i][1];
        }
    }
    int sum=0,root;
    for (int i=0;i<N;i++) {
        if (parent[i] == -1) {
            root = i;
        } else {
            int j = i;
            while (parent[j] != -1) {
                count[j]++;
                sum++;
                j = parent[j];
            }
        }
    }
    count[root] = N;
    res[root] = sum;
    for (int i=0;i<N;i++) {
        if (res[i] != -1)
            continue;
        _help(res, count, parent, i, N);
    }
    return res;
}

void _help(int* res, int* count, int* parent, int i, int N) {
    if (res[parent[i]] == -1)
        _help(res, count, parent, parent[i], N);
    res[i] = res[parent[i]] + N - 2 * count[i];
}

void _change_root(int* parent, int root) {
    if (parent[root] == -1)
        return;
    _change_root(parent, parent[root]);
    parent[parent[root]] = root;
    parent[root] = -1;
}