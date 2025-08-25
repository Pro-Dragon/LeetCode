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
    void solve(queue<TreeNode*> pq1, queue<TreeNode*> &pq2) {
        while(!pq1.empty()) {
            int i = pq1.size(), sum = 0, cur = 0;
            while(i--){
                cur = 0;
                if(pq1.front()->left) {
                    sum += pq1.front()->left->val;
                    cur += pq1.front()->left->val;
                    pq1.push(pq1.front()->left);
                }
                if(pq1.front()->right) {
                    sum += pq1.front()->right->val;
                    cur += pq1.front()->right->val;
                    pq1.front()->right->val = cur;
                    pq1.push(pq1.front()->right);
                }
                if(pq1.front()->left) pq1.front()->left->val = cur;
                pq1.pop();
            }
            i = pq2.size();
            while(i--){
                cur = 0;
                if(pq2.front()->left) {
                    pq2.front()->left->val = sum - pq2.front()->left->val;
                    pq2.push(pq2.front()->left);
                }
                if(pq2.front()->right) {
                    pq2.front()->right->val = sum - pq2.front()->right->val;
                    pq2.push(pq2.front()->right);
                }
                pq2.pop();
            }
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> pq1, pq2;
        pq1.push(root);
        pq1.front()->val = 0;
        pq2.push(root);
        solve(pq1, pq2);
        return root;
    }
};