class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefixSum = vector<vector<int>>(n+1, vector<int>(m+1, 0));

        // init prefix from 1 to n (instead of n-1)
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1+=1;
        col1+=1;
        row2+=1;
        col2+=1;

        return prefixSum[row2][col2] -  prefixSum[row1-1][col2] - prefixSum[row2][col1-1] + prefixSum[row1-1][col1-1];

        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */