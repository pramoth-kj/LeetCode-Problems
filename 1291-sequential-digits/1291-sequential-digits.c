#define RESULT_MEM_SIZE 36

inline int getDigit(int n){ int digit=1; for(;n>9;n/=10){digit++;} return digit; }
inline int genSeqNum(int digit, int start){
    int base=start+1, result=start, max=1; for(int i=1; i<digit; i++){ max*=10; }
    while(result<=max){ if(base>9){ return INT_MAX; } result = (result*10)+base; base++; }
    return result;
}


int* sequentialDigits(int low, int high, int* returnSize) {
    int seqDigit=getDigit(low), hiDigit=getDigit(high), seqNum, seqStart=1;
    int* result=malloc(RESULT_MEM_SIZE*sizeof(int)); *returnSize=0;

    for(; seqStart<=(10-seqDigit); seqStart++) {
        seqNum=genSeqNum(seqDigit, seqStart);
        if(seqNum>=low && seqNum<=high){ result[(*returnSize)++]=seqNum; }
        if(seqStart>=(10-seqDigit) && seqDigit<hiDigit){ seqStart=0; seqDigit++; }
    }

    return result;
}