class Solution {
public:
    void evenStore(multiset<pair<int, int>> &cur, vector<double> &res, int &l) {
        res[l] = cur.rbegin()->first;
        auto val1 = *cur.rbegin();
        cur.erase(prev(cur.end()));
        res[l] += cur.rbegin()->first;
        res[l++] /= 2.0;
        cur.insert(val1);
    }
    void remove(multiset<pair<int, int>> &extra, multiset<pair<int, int>> &cur, int i, vector<int>& nums) {
        auto ind = cur.lower_bound({nums[i], i});
        if(ind != cur.end() && ind->second == i) {
            cur.erase(*ind);
            return;
        }
        ind = extra.lower_bound({nums[i], i});
        if(ind != extra.end() && ind->second == i) extra.erase(*ind);
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int size = k / 2 + 1, n = nums.size(), l = 0;
        multiset<pair<int, int>> extra;
        multiset<pair<int, int>> cur;
        vector<double> res((n - k) + 1);
        for(int i = 0, j = 0; i < n; i++) {
            if(i >= k) remove(cur, extra, j - 1, nums);
            cur.insert({nums[i], i});
            if(cur.size() > size) {
                extra.insert(*cur.rbegin());
                cur.erase(prev(cur.end()));
            }
            if(!extra.empty() && extra.begin()->first < cur.rbegin()->first) {
                auto val1 = *extra.begin();
                auto val2 = *cur.rbegin();
                extra.erase(extra.begin());
                cur.erase(prev(cur.end())); 
                extra.insert(val2);
                cur.insert(val1);
            }
            if(i >= k - 1) {
                if(k % 2) res[l++] = cur.rbegin()->first;
                else evenStore(cur, res, l);
                j++;
            }
        }
        return res;
    }
};