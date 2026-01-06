/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int maxi = root->val, level = 0, cur = maxi, n = qu.size(), res = 1;
        while(!qu.empty()) {
            n = qu.size(), cur = 0;
            while(n--) {
                if(qu.front()->right) qu.push(qu.front()->right);
                if(qu.front()->left) qu.push(qu.front()->left);
                cur += qu.front()->val;
                qu.pop();
            }
            level++;
            if(maxi < cur) {
                maxi = cur;
                res = level;
            }
        }
        return res;
    }
};