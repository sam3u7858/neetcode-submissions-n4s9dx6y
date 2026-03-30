class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int current_m = 0;
        // use a state machine to simulate

        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        
        vector<int> res;
        
      

        while(res.size() < matrix.size() * matrix[0].size()){

           

            if(current_m == 0 ){
               for(int k = left; k<=right; ++k) res.push_back(matrix[top][k]);
               top++;
               current_m = 1;

            }

            else if(current_m == 1){
               for(int k = top; k<=bottom; ++k) res.push_back(matrix[k][right]);
               right--;
               current_m = 2;
             
      
            }

            else if(current_m == 2){
               for(int k = right; k>=left; --k) res.push_back(matrix[bottom][k]);
               bottom--;
               current_m = 3;
              
            }

            else if(current_m == 3){
               for(int k = bottom; k>=top; --k) res.push_back(matrix[k][left]);
               left++;
               current_m = 0;
               
            }


        }



        return res;


    }
};
