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
    vector<vector<int>> res;
    void OG(TreeNode *root, int targetSum, vector<int> &ans, int sum) {
        ans.push_back(root->val);
        if(root->left) OG(root->left, targetSum, ans, sum + root->val);
        if(root->right) OG(root->right, targetSum, ans, sum + root->val);
        ans.pop_back();
        if(!root->left && !root->right) {
            ans.push_back(root->val);
            if(sum + root->val == targetSum) res.push_back(ans);
            ans.pop_back();
            return;
        }
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        if(root)OG(root, targetSum, ans, 0);
        return res;
    }
};