class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size(), maxi = 0, temp;
        for (int i = 0; i < n; i++) {
            int l = i, h = i, check = 1;
            while (l >= 0 && h < n) {
                if (s[l] != s[h]) {
                    if (check) {
                        l--, check = 0;
                        continue;
                    }
                    else break;
                   
                } l--, h++;
            }
            temp = (h - l) - 1;             
            if(temp != n && check) temp++;             
            maxi = max(maxi, temp);
            l = i, h = i, check = 1;
            while (l >= 0 && h < n) {
                if (s[l] != s[h]) {
                    if (check) {
                        h++, check = 0;
                        continue;
                    }
                    else break;
                    
                }l--, h++;
            }
            temp = (h - l) - 1;             
            if(temp != n && check) temp++;             
            maxi = max(maxi, temp);
            l = i, h = i + 1, check = 1;
            while (l >= 0 && h < n) {
                if (s[l] != s[h]) {
                    if (check) {
                        h++, check = 0;
                        continue;
                    }
                    else break;
                    
                }l--, h++;
            }
            temp = (h - l) - 1;             
            if(temp != n && check) temp++;             
            maxi = max(maxi, temp);
            l = i, h = i + 1, check = 1;
            while (l >= 0 && h < n) {
                if (s[l] != s[h]) {
                    if (check) {
                        l--, check = 0;
                        continue;
                    }
                    else break;
                    
                }l--, h++;
            }
            temp = (h - l) - 1;
            if(temp != n && check) temp++;
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};