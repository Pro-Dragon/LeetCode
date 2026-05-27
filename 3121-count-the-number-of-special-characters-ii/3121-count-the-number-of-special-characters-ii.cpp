class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        int n = word.size(), count = 0;
        for(int i = 0; i < n; i++) {
            if(word[i] < 97 && !mp[word[i]]) {
                if(mp[word[i] + 32]) {
                    count++;
                    mp[word[i]] = 1;
                }
                else mp[word[i]] = -1;
            }
            else if(word[i] >= 97 && mp[word[i] - 32]) {
                if(mp[word[i] - 32] == 1) {
                    count--;
                    mp[word[i] - 32] = -1;
                }
            }
            else if(!mp[word[i]]) mp[word[i]] = 1;
        }
        return count;
    }
};