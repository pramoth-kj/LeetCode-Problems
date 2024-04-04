

int maxDepth(char * s){
    int maximumDepth = 0;
    int i = 0;
    int num = 0;
    while(s[i] !='\0')
    {
        if(s[i] == '(')
        {
            num++;
        }
        else if(s[i] == ')')
        {
            num--;
        }
        maximumDepth = fmax(maximumDepth,num);
        i++;
    }

    return maximumDepth;
}