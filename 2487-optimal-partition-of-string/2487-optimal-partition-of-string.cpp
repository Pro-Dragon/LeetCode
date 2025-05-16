class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(26, 0);
        int n = s.size(), cur_partition = 1, count = 0;
        freq[s[0] - 'a'] = 1;
        for(int i = 1; i < n; i++) {
            if(freq[s[i] - 'a'] != cur_partition) {
                freq[s[i] - 'a'] = cur_partition;
            }
            else {
                freq[s[i] - 'a'] = ++cur_partition;
                count++;
            }
        }
        return count + 1;
    }
};