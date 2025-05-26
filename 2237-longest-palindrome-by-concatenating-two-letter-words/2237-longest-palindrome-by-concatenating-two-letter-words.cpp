class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count1 = 0, n = words.size(), count2 = 0;
        string str;
        vector<vector<int>> mp(26, vector<int>(26));
        for(int i = 0; i < n; i++) {
            str = words[i];
            swap(str[0], str[1]);
            if(str == words[i]) {
                if(!(mp[str[0] - 'a'][str[1] - 'a'] % 2)) count2++;
                else count2--;
            }
            if(mp[str[0] - 'a'][str[1] - 'a'] > 0) {
                count1 += 4;
                mp[str[0] - 'a'][str[1] - 'a']--;
            }
            else mp[words[i][0] - 'a'][words[i][1] - 'a']++;
        }
        return count1 + ((count2 > 0) ? 2 : 0);
    }
};