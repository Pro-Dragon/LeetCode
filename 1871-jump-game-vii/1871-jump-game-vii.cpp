class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), j;
        vector<int> vis(n, 0);
        vis[0] = 1;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 1 && s[i] == '0') {
                j = max(min(i + maxJump, n - 1), i + minJump);
                while(j < n && !vis[j] && j >= i + minJump) {
                    vis[j] = 1;
                    j--;
                }
            }
        }
        return vis.back() && s.back() == '0';
    }
};