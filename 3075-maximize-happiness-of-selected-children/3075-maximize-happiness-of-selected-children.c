int cmp(const void *a,const void*b){
    return *(int*)b-*(int*)a;
}
long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    long long ans=0,sub=0;;
    qsort(happiness,happinessSize,sizeof(int),cmp);
    for(int i=0;i<happinessSize &k>0;i++,k--){
        ans+=(happiness[i]-sub)<0?0:happiness[i]-sub;
        sub++;
    }
    return ans;
}