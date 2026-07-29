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
    int count = 0;
    int solve(TreeNode *root) {
        if(!root) return 0;
        int maxi = max(solve(root->left), solve(root->right));
        if(root->val >= maxi) {
            count++;
            maxi = root->val;
        }
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return count;        
    }
};