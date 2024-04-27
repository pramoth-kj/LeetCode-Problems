#define min(a, b) (a < b ? a : b)

int arr[101][101];

int d(char* r, char* k, int rd, int kd, int rx, int kx);

int findRotateSteps(char* ring, char* key) {
    int r = strlen(ring);
    int k = strlen(key);
    memset(arr, -1, sizeof(arr));
    return d(ring, key, r, k, 0, 0);
}

int d(char* r, char* k, int rd, int kd, int rx, int kx){
    if(kx == kd){
        return 0;
    }
    if(arr[kx][rx] != -1){
        return arr[kx][rx];
    }
    int s = 1e9;
    for(int i = 0; i < rd; i++){
        if(r[i] == k[kx]){
            int w = (rx + rd - i) % rd;
            int cw = (i + rd - rx) % rd;
            int sp = min(w, cw) + 1 + d(r, k, rd, kd, i, kx + 1);
            s = min(s, sp);
        }
    }
    arr[kx][rx] = s;
    return s;
}