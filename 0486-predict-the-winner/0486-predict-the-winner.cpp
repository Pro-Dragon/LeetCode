class Solution {
public:
    bool solve(vector<int> &nums, bool turn, int player1, int player2, int i, int j) {
        if(i > j) {
            return player1 >= player2;
        }
        if(turn) return (solve(nums, !turn, player1 + nums[i], player2, i + 1, j) || solve(nums, !turn, player1 + nums[j], player2, i, j - 1));
        else return (solve(nums, !turn, player1, player2 + nums[i], i + 1, j) && solve(nums, !turn, player1, player2 + nums[j], i, j - 1));
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, true, 0, 0, 0, nums.size() - 1);
    }
};