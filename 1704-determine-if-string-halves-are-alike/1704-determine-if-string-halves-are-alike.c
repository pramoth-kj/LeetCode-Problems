bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool halvesAreAlike(char* s) {
    int half_len = strlen(s) / 2;
    int a_vowels = 0;
    int b_vowels = 0;
    for(int i = 0; i < half_len; i++) {
        if(isVowel(*(s + i)) || isVowel(*(s + i) + 32)) {
            a_vowels++;
        }

        if(isVowel(*(s + i + half_len)) || isVowel(*(s + i + half_len) + 32)) {
            b_vowels++;
        }
    }

    return (a_vowels == b_vowels);
}