int appendCharacters(char* s, char* t) {
    int i,j;

    for(i=0,j=0; s[i]!='\0'; i++)
    { if(t[j]==s[i]){ j++; }}
    for(i=j; t[i]!='\0'; i++);

    return i-j;
}