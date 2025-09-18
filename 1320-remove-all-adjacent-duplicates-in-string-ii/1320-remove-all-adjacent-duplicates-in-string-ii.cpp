class Solution {
public:
    string removeDuplicates(string s, int k) {
        string str;
        vector<int> freq;
        int n = s.size();
        str.push_back(s[0]);
        freq.push_back(1);
        for(int i = 1; i < n; i++) {
            if(freq.size() && str.size() && str.back() == s[i]) freq[freq.size() - 1]++;
            else freq.push_back(1);
            str.push_back(s[i]);
            if(freq.back() == k) {
                int j = k;
                while(j--) {
                    str.pop_back();
                }
                freq.pop_back();
            }
        }
        return str;
    }
};