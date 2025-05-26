class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count1 = 0, n = words.size(), count2 = 0;
        string str;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            str = words[i];
            swap(str[0], str[1]);
            if(str == words[i]) {
                if(!(mp[str] % 2)) count2++;
                else count2--;
            }
            if(mp[str] > 0) {
                count1 += 4;
                mp[str]--;
            }
            else mp[words[i]]++;
        }
        return count1 + ((count2 > 0) ? 2 : 0);
    }
};