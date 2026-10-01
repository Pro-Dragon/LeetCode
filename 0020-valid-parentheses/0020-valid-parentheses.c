bool isValid(char* s) {
    int i = 0, j = 0;
    while (s[i + 1]) {
        if ((s[i] == '(' && s[i + 1] == ')') ||
            (s[i] == '[' && s[i + 1] == ']') ||
            (s[i] == '{' && s[i + 1] == '}')) {
            j = i;
            while (s[j + 2]) {
                s[j] = s[j + 2];
                j++;
            }
            s[j] = '\0';
            if (i != 0)
                i -= 2;
            else
                continue;
        }
        i++;
    }
    if (!(strlen(s)))
        return true;
    else
        return false;
}