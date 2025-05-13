class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> d(10, 0);
        for(int i : digits) d[i]++;
        vector<int> res;
        for(int i = 100; i <= 998; i += 2) {
            int a = i / 100, b = i % 10, c = (i / 10) % 10;
            d[a]--;
            d[b]--;
            if(d[a] >= 0 && d[b] >= 0 && d[c])
            res.push_back(i);
            d[a]++;
            d[b]++;
        }
        return res;
    }
};