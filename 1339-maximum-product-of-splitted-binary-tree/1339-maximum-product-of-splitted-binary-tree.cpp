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
    long long maxi = 0, sum = 0;
    int solve(TreeNode *root) {
        if(!root) return 0;
        int cur = root->val + solve(root->left) + solve(root->right);
        if(maxi < (long)(sum - cur) * cur) maxi = (long)((sum - cur) * cur);
        return cur;
    }
    void totalSum(TreeNode *root) {
        if(!root) return;
        sum += root->val;
        totalSum(root->left);
        totalSum(root->right);
    }
    int maxProduct(TreeNode* root) {
        totalSum(root);
        solve(root);
        int mod = 1e9 + 7;
        return maxi % mod;
    }
};