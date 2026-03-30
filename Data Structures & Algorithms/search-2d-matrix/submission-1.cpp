class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Check each raw's max value
        int n = matrix[0].size();
        int m = matrix.size();

        

        // Search range from [0][n-1] to [m-1][n-1]
        // Get the correct row [M][n-1]
        int left = 0;
        int right = m-1;
        int M = -1;

        while(left <= right){
            int mid = left + (right - left)/2;
            int v = matrix[mid][n-1];
            if (v == target) {
                return true;
            }
            if (target < v && target >= matrix[mid][0] ){
                M = mid;
                break;
            }
            else if( v < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }

        }
        
        if( M==-1 )return false;

        for(int i: matrix[M]){
            cout << i << endl;
        }


        // Binary Search in [M][n-1]
        if(binarySearch(matrix[M], target) != -1){
            return true;
        }
        return false;

    }

    int binarySearch(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = left + (right - left)/2;
            int v = nums[mid];

            if( v == target)return mid;
            else if(v < target) left = mid + 1;
            else{
                right = mid - 1;
            }

        }
        return -1;

    }
};
