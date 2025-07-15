class Solution {
public:
    int search(vector<vector<int>>& arr, int k, int l , int h, int i){
        if(l <= h) {
            int mid = (l + h) / 2, res = -1, mid1, mid2;
            if(i < 0){
                mid1 = mid;
                mid2 = 0;
            }
            else {
                mid1 = i;
                mid2 = mid;
            }
            if(arr[mid1][mid2] == k){
             return mid;
            }
            if(k < arr[mid1][mid2]){
                res = search(arr, k, l, mid - 1, i);
            }
            if(k > arr[mid1][mid2]){
                res = search(arr, k, mid + 1, h, i);
            }
            if(!res)return l;
            if(res)return res;
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = search(matrix, target, 0, matrix.size() - 1, -1);
        if(matrix[row][0] > target && row > 0)row--;
        if(matrix[row][0] == target)return 1;
        int column = search(matrix, target, 0, matrix[0].size() - 1, row);
        return (matrix[row][column] == target);
    }
};