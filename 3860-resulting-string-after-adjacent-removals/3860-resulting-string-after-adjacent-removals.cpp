class Solution {
public:
    string resultingString(string s) {
        string str;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(str.size() == 0) str.push_back(s[i]);
            else if(abs(str.back() - s[i]) == 1 || abs(str.back() - s[i]) == 25) str.pop_back();
            else str.push_back(s[i]);
        }
        return str;
    }
};