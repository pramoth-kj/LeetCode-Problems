int openLock(char ** deadends, int deadendsSize, char * target){
    int newTarget = atoi(target);
    int* deads = calloc(10000, sizeof(int));
    for(int i = 0; i < deadendsSize; i++) {
        int index = atoi(deadends[i]);
        deads[index] = 1;
    }

    int* visited = calloc(10000, sizeof(int));
    int* vd_0 = calloc(10000, sizeof(int));
    int* vd_1 = calloc(10000, sizeof(int));

    int idx = 0;
    int cur_idx = 0;
    if(!deads[0]) {
        vd_0[0] = 0;
        vd_1[0] = 0;
        idx++;
    }
    int firstRound[] = {1, 10, 100, 1000};

    while(cur_idx < idx) {
        if(vd_0[cur_idx] == newTarget) {
            free(deads);
            free(visited);
            free(vd_0);
            
            int res = vd_1[cur_idx];
            free(vd_1);
            return res;
        }

        for(int i = 0; i < 4; i++) {
            int trace = (vd_0[cur_idx] / firstRound[i]) % 10;
            int newStep1 = (vd_0[cur_idx] - firstRound[i] * trace) + firstRound[i] * ((trace + 1) % 10);
            int newStep2 = (vd_0[cur_idx] - firstRound[i] * trace) + firstRound[i] * ((trace + 9) % 10);
            int newElements[] = {newStep1, newStep2};
            
            for(int j = 0; j < 2; j++) {
                if((!deads[newElements[j]]) && (!visited[newElements[j]])) {
                    visited[newElements[j]] = 1;

                    vd_0[idx] = newElements[j];
                    vd_1[idx] = vd_1[cur_idx] + 1;

                    idx++;
                }
            }
        }

        cur_idx++;
    }

    return -1;
}