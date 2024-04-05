void removeCharAtIndex(char *str, int index) {
    int len = strlen(str);
    if (index < 0 || index >= len) {
        return;
    }
    for (int i = index; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = '\0';
}

char* makeGood(const char* s) {
    int len = strlen(s);
    char *result = (char *)malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, s);
    for(int i = 0; i < strlen(result) - 1 && strlen(result)!=0; i++) {
        if(islower(result[i])) {
            if(isupper(result[i+1])) {
                if(tolower(result[i]) == tolower(result[i+1])) {
                    removeCharAtIndex(result, i);
                    removeCharAtIndex(result, i);
                    i = -1;
                }
            }
        } else if(isupper(result[i])) {
            if(islower(result[i+1])) {
                if(tolower(result[i]) == tolower(result[i+1])) {
                    removeCharAtIndex(result, i);
                    removeCharAtIndex(result, i);
                    i = -1;
                }
            }
        }
    }
    return result;
}