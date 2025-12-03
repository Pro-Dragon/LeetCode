class Solution {
public:
    int maxDistinct(string s) {
        int freq[26] = {0}, n = s.size(),count = 0;
        for(int i = 0; i < n; i++) {
            if(freq[s[i] - 'a']) continue;
            freq[s[i] - 'a']++;
            count++;
        }
        return count;
    }
};