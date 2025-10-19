class Solution {
public:
    bool solve(string t, vector<int> &freq, int i, string &str) {
            int j = (t[i] - 'a') + 1;
            while(j < 26 && !freq[j]) j++;
            if(j < 26) {
                freq[j]--;
                str += ('a' + j);
                return 1;
            }
            return 0;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string str;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++) freq[s[i] - 'a']++;
        for(int i = 0; i < n; i++) {
            if(freq[target[i] - 'a']) {
                freq[target[i] - 'a']--;
                str += target[i];
                if(i < n - 1) continue;
                if(!str.empty()) {
                    freq[str.back() - 'a']++;
                    str.pop_back();
                }
            }
            if(solve(target, freq, i, str)) break;
            else {
                do {
                    if(!str.empty()) {
                        freq[str.back() - 'a']++;
                        str.pop_back();
                    }
                } while(i-- && !(solve(target, freq, i, str)));
                if(str.empty()) return "";
            }
            break;
        }
        for(int i = 0; i < 26; i++) {
            while(freq[i]--) str += ('a' + i);
        }
        return str;
    }
};