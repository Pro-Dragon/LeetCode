class Solution {
public:
    int maxi = 0;
    vector<string> words;
    vector<int> score;
    int helper(vector<int> &freq, int i, vector<int> &fre) {
        int n = words[i].size(), count = 0;  
        fre = freq;
        while(n--) {
            if(freq[words[i][n] - 'a']) {
                freq[words[i][n] - 'a']--;
                count += (score[words[i][n] - 'a']);
            }
            else {
                freq = fre;
                return -1;
            }
        }
        return count;
    }
    int Dragon(int i, vector<int> freq, int res) {
        if(i == words.size()) {
            maxi = max(maxi, res);
            return maxi;
        }
        vector<int> fre;
        fre = freq;
        int val = helper(freq, i, fre);
        if(val > 0) Dragon(i + 1, freq, res + val);
        freq = fre;
        Dragon(i + 1, freq, res);
        return maxi;
    }
    int maxScoreWords(vector<string>& word, vector<char>& letters, vector<int>& s) {
        vector<int> freq(26, 0);
        int n = letters.size();
        for(int i = 0; i < n; i++) {
            freq[letters[i] - 'a']++;
        }
        words = word;
        score = s;
        return Dragon(0, freq, 0);
    }
};