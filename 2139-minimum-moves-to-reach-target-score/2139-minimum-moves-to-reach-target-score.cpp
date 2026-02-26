class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while(target > 1) {
            if(target % 2) {
                moves++;
                target--;
            }
            else if(maxDoubles) {
                moves++;
                target /= 2;
                maxDoubles--;
            }
            else {
                moves += (target - 1);
                break;
            }
        }
        return moves;
    }
};