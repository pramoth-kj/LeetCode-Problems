bool checkValidString(char * s){
    int leftParen = 0, rightParen = 0;
    
    for(int i = 0; s[i]; i++) {
        leftParen += s[i] == '(' ? 1 : -1;
        rightParen += s[i] != ')' ? 1 : -1;
        if(rightParen < 0) break;
        leftParen = fmax(0, leftParen);
    }
    return leftParen == 0;
}