class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0), res;
        freq[s[0] - 'a']++;
        int n = s.size(), cur_grp = 1, prv = 0, i;
        for(i = 1; i < n; i++) {
            if(!freq[s[i] - 'a']) {
                res.push_back(i - prv);
                freq[s[i] - 'a'] = ++cur_grp;
                prv = i;
            }
            else {
                cur_grp = freq[s[i] - 'a'];
                int j = 0;
                while(j < 26) {
                    if(freq[j] > cur_grp) freq[j] = cur_grp;
                    if(res.size() >= cur_grp) {
                        prv -= res.back();
                        res.pop_back();
                    }
                    j++;
                }
            }
        }
        res.push_back(i - prv);
        return res;
    }
};