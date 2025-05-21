class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int isc = 0;
        for(int i = 0; i < matrix[0].size(); i++) if(!matrix[0][i])isc = 1;
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(!matrix[i][j]){
                    int temp = 0;
                    while(temp < matrix[0].size()){
                        if(!matrix[i][temp])matrix[0][temp] = 0;
                        matrix[i][temp++] = 0;
                    }
                    j = matrix[0].size();
                }
            }
        }
        for(int i = 0; i < matrix[0].size(); i++){
            if(!matrix[0][i]){
                int temp = 0;
                while(temp < matrix.size())matrix[temp++][i] = 0;
            }
            if(isc)matrix[0][i] = 0;
        }
    }
};