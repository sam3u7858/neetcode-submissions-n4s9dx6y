class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Reverse the Martix Vertically 
        int n = matrix.size();
        
        for(int i=0; i<n/2; i++){
           swap(matrix[i], matrix[n - 1 - i]);
        }
        // Transpose
        for(int i=0; i<n; i++){
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
                cout << "Ap:"<< i << j << "Bp:" << j << i << endl;
            }
        }
    }
};
