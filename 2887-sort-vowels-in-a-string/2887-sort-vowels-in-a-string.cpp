class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(58, 0);
        int check, j = 0;
        for(int i = 0; s[i]; i++) {
            if(s[i] >= 97) check = 32;
            if(s[i] - check == 'A' || s[i] - check == 'E' || s[i] - check == 'I' || s[i] - check == 'O' || s[i] - check == 'U') freq[(s[i] - 'A')]++;
            check = 0;
        }
        for(int i = 0; s[i]; i++) {
            if(s[i] >= 97) check = 32;
            if(s[i] - check == 'A' || s[i] - check == 'E' || s[i] - check == 'I' || s[i] - check == 'O' || s[i] - check == 'U') {
                while(!freq[j] && j < 58) j++;
                if(j < 58) {
                    s[i] = j + 'A';
                    freq[j]--;
                }
            }
            check = 0;
        }
        return s;
    }
};