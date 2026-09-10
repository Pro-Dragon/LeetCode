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
    int Dragon(TreeNode *root, int &count, int &sum) {
        if(!root) {
            sum = 0;
            return 0;
        }
        int nodes = Dragon(root->left, count, sum);
        int lsum = sum;
        nodes += Dragon(root->right, count, sum);
        int rsum = sum;
        sum = (lsum + rsum + root->val);
        nodes++;
        if(round(sum / nodes) == root->val) {
            count++;
        }
        return nodes;
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0, sum = 0;
        Dragon(root, count, sum);
        return count;
    }
};