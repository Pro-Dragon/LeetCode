class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<long, long> ab, bc, ac, abc;
        ab[0] = -1, bc[0] = -1, ac[0] = -1, abc[0] = -1;
        int a = 0, b = 0, c = 0, maxi = 1, n = s.size(), ind1 = -1, ind2 = -1, ind3 = -1;
        long long diff;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                a++;
                ind1 = i;
            }
            else if(s[i] == 'b') {
                b++;
                ind2 = i;
            }
            else {
                c++;
                ind3 = i;
            }
            if(a) maxi = max(maxi, ind1 - max(ind2, ind3));
            if(b) maxi = max(maxi, ind2 - max(ind1, ind3));
            if(c) maxi = max(maxi, ind3 - max(ind2, ind1));
            if(a && b && ab.find(a - b) != ab.end()) {
               if(ind3 <= ab[a - b]) maxi = max(maxi, int(i - ab[a - b]));
            }
            if(b && c && bc.find(b - c) != bc.end() && ind1 <= bc[b - c]) maxi = max(maxi, int(i - bc[b - c]));
            if(a && c && ac.find(a - c) != ac.end() && ind2 <= ac[a - c]) maxi = max(maxi, int(i - ac[a - c]));
            if(a && b && c) {
                diff = 100000;
                diff = (long)(diff * (a - b)) + (b - c);
                if(abc.find(diff) != abc.end()) maxi = max(maxi, int(i - abc[diff]));
            }
            if(ab.find(a - b) == ab.end() || ab.find(a - b) != ab.end() && ab[a - b] < ind3) ab[a - b] = i;
            if(bc.find(b - c) == bc.end() || bc.find(b - c) != bc.end() && bc[b - c] < ind1) bc[b - c] = i;
            if(ac.find(a - c) == ac.end() || ac.find(a - c) != ac.end() && ac[a - c] < ind2) ac[a - c] = i;
            diff = ((long)100000 * (a - b)) + (b - c);
            if(abc.find(diff) == abc.end()) abc[diff] = i;
        }
        return maxi;
    }
};