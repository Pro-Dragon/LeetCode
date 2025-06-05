class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<int, vector<int>> mp;
        vector<int> freq1(26, 0), freq2(26, 0);
        int n = s.size(), total_count = 0, cur_count = 0, count1 = 0, count2 = 0, index = -1, res = 0;
        for(int i = 0; i < n; i++) {
            freq1[s[i] - 'a']++;
            if(freq1[s[i] - 'a'] == 1) total_count++;
            if(freq1[s[i] - 'a'] == k) cur_count++;
            freq2[s[i] - 'a'] = i;
            mp[i] = freq1;
            count1 = cur_count;
            count2 = total_count - cur_count;
            while(count1 && count2) {
                for(int j = 0; j < 26; j++) if(freq1[j] && freq1[j] < k) index = max(index, freq2[j]);
                count2 = 0;
                for(int j = 0; j < 26; j++) {
                    if((freq1[j] - mp[index][j]) > 0 && (freq1[j] - mp[index][j]) < k) {
                        count1--;
                        count2++;
                    }
                    freq1[j] -= mp[index][j];
                }
            }
            if(!count2) res = max(res, i - index);
            index = -1;
            freq1 = mp[i];
        }
        return res;
    }
};