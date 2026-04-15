class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return 0;
        vector<int> freq1(26, 0), freq2(26, 0);
        for(int i = 0; s1[i]; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        if(freq1 == freq2) return 1;
        for(int i = s1.size(), j = 0; s2[i]; i++, j++) {
            freq2[s2[j] - 'a']--;
            freq2[s2[i] - 'a']++;
            if(freq1 == freq2) return 1;
        }
        return 0;
    }
};