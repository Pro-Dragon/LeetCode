class Solution {
public:
    struct Comp {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        long long count = 0, n = damage.size(), life = hp, damPrefix = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> req;
        for(int i = 0; i < n; i++) {
            life -= damage[i];
            if(life - requirement[i] < 0) req.push({life - requirement[i], i});
        }
        for(int i = 0; i < n; i++) {
            while(!req.empty() && req.top().second < i || !req.empty() && req.top().first + damPrefix >= 0) req.pop();
            count += ((n - i) - req.size());
            damPrefix += damage[i];
        }
        return count;
    }
};