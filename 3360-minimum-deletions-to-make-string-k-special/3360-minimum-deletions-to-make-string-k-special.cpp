class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        int n = word.size(), res = n;
        for(int i = 0; i < n; i++)  {
            freq[word[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            int count = 0;
            for(int j = 0; j < 26; j++) {
                if(freq[i] > freq[j]) count += freq[j];
                else if(freq[j] > freq[i] + k) count += (freq[j] - freq[i] - k);
            }
            res = min(res, count);
        }
        return res;
    }
};