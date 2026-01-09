class Solution {
public:
    int height, cmn;
    TreeNode *val;
    int solve(TreeNode *root, int level, int check) {
        if(!root) return (height == level) ? 1 : 0;
        if(solve(root->left, level + 1, 0)) check = 1;
        if(solve(root->right, level + 1, 0)) {
            if(cmn > level && check){
                cmn = level;
                val = root;
            }                
            else check = 1;
        }
        if(check) return 1;
        return 0;
    }
    int getMaxHeight(TreeNode *root, int level) {
        if(!root) return level;
        return max(getMaxHeight(root->right, level + 1), getMaxHeight(root->left, level + 1));
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        height = getMaxHeight(root, 0);
        cmn = height;
        solve(root, 0, 0);
        return val;
    }
};