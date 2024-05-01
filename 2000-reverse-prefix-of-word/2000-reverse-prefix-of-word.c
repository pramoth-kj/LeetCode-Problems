char* reversePrefix(char* word, char ch) {
    int flag=0,temp,rm=0;
    char *string=word;
    int len=strlen(word);
    int l=0;
    for(int i=0;i<len;i++){
        if(word[i]==ch){
            flag=1; rm=i;
            break;
        }
    }
    if(flag<=0){
        return string;
    }
    int r=rm;
    while(l<r){
        temp=word[r];
        word[r]=word[l];
        word[l]=temp;
        l++; r--; 
    }
    return word;
}