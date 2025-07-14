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
    bool check = 0;
    TreeNode *num1, *num2, *prv = NULL; 
    void solver(TreeNode* root) {
        if(!root) return;
        solver(root->left);
        if(prv && prv->val > root->val) {
            num1 = (!check) ? prv : num1;
            num2 = root;
            check = 1;
        }
        prv = root;
        solver(root->right);
    }
    void recoverTree(TreeNode* root) {
        solver(root);
        swap(num1->val, num2->val);
    }
};