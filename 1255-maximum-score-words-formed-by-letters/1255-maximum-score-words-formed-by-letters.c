#define MAX(a,b) (a) > (b) ? (a) : (b)

struct pair {
    bool IsValid;
    int len;
    int score;
};

int process(char* str, int* hash, struct pair* pair, int idx, bool* NoAdd) {
    if ((*NoAdd) == false) {
        for (int i = 0; i < pair[idx].len; i++) {
            hash[str[i]-'a']++;
        }
    } else {
        for (int i = 0; i < pair[idx].len; i++) {
            if (hash[str[i]-'a'] == 0) {
                for (int j = 0; j < i; j++) {
                    hash[str[j]-'a']++;
                }
                return 0;
            }
            hash[str[i]-'a']--;
        }
        (*NoAdd) = false;
    }
    return pair[idx].score;
}

void dfs(char** words, int wordsSize, int* hash, struct pair* pair, int* cnt, int* ans, int idx) {
    if (idx == wordsSize) {
        (*ans) = MAX((*cnt), (*ans));
        return;
    }
    for (int i = idx; i < wordsSize; i++) {
        bool NoAdd = true;
        if (pair[i].IsValid == true) (*cnt) += process(words[i], hash, pair, i, &NoAdd);
        dfs(words, wordsSize, hash, pair, cnt, ans, i+1);
        if (NoAdd == false) (*cnt) -= process(words[i], hash, pair, i, &NoAdd);
    }
}

int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize) {
    int hash[26] = {0};
    for (int i = 0; i < lettersSize; i++) {
        hash[letters[i]-'a']++;
    }
    struct pair* pair = (struct pair*) calloc(wordsSize, sizeof(struct pair));
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]), res = 1, tmp = 0;
        pair[i].len = len;
        for (int j = 0; j < len; j++) {
            tmp += score[words[i][j]-'a'];
            if (hash[words[i][j]-'a'] == 0) {
                res = 0;
                break;
            }
        }
        pair[i].IsValid = res;
        pair[i].score = (pair[i].IsValid == false) ? 0 : tmp;
    }
    int cnt = 0, ans = 0;
    dfs(words, wordsSize, hash, pair, &cnt, &ans, 0);
    free(pair);
    return ans;
}