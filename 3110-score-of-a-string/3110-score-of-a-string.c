int scoreOfString(char* s) {
    int score = 0, len = strlen(s);
    
    for(int i = 1; i < len; i++) {
        score += abs(s[i] - s[i-1]);    
    }
    return score;
}