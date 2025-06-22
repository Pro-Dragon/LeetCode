class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        int top = 0, n = caption.size(), check = 1;
        if(caption[0] != ' ') {
            ans.push_back(tolower(caption[0]));
            check = 0;
        }
        for(int i = 1; i < n; i++) {
            if(caption[i] == ' ') top = 1;
            else {
                if(check) {
                    ans.push_back(tolower(caption[i]));
                    check = 0;
                    top = 0;
                    continue;
                }
                if(top) {
                    ans += toupper(caption[i]);
                    top = 0;
                }
                else {
                    ans += tolower(caption[i]);
                }
            }
            if(ans.size() == 100) break;
            
        }
        return ans;
    }
};