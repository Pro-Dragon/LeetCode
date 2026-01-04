class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long n = s.size(), mini, swapscount = 0, rem;
        int mismatch0 = 0, mismatch1 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i] && (s[i] - '0')) mismatch1++;
            if(s[i] != t[i] && !(s[i] - '0')) mismatch0++;
        }
        mini = (long)flipCost * (mismatch0 + mismatch1);
        swapscount = ((long)min(mismatch0, mismatch1) * swapCost);
        rem = abs(mismatch0 - mismatch1);
        if(mini > (long)(rem * flipCost) + swapscount) mini = (long)(rem * flipCost) + swapscount;
        swapscount += ((long)crossCost * (rem / 2) + (long)swapCost * (rem / 2));
        if(rem % 2) swapscount += (flipCost);
        if(mini > swapscount) mini = swapscount;
        return mini;
    }
};