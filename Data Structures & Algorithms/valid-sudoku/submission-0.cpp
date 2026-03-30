class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check row
        int checkArray[10];

        for(int i=0; i<9; i++){
            memset(checkArray, 0, sizeof(checkArray));
            for(int j=0; j<9; j++){
                // Empty element
                if(board[i][j]== '.'){
                    continue;
                }
                // Convert the value to int
                int value = (int) board[i][j] - '0';
                if(checkArray[value]==1){
                    return false;
                }
                else{
                    checkArray[value] +=1;
                }
            }
        }
        // Check Col
        for(int i=0; i<9; i++){
            memset(checkArray, 0, sizeof(checkArray));
            for(int j=0; j<9; j++){
                // Empty element
                if(board[j][i] =='.'){
                    continue;
                }
                // Convert the value to int
                int value = (int) board[j][i] - '0';
                if(checkArray[value]==1){
                    return false;
                }
                else{
                    checkArray[value] +=1;
                }
            }
        }


        // Check 3x3 blocks
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                memset(checkArray, 0, sizeof(checkArray));
                for(int k=i*3; k<(i*3)+3; k++){
                    for(int u=j*3; u<(j*3)+3; u++){

                          if(board[k][u] == '.'){
                            continue;
                        }
                        // Convert the value to int
                        int value =  (int) board[k][u] - '0';
                        if(checkArray[value]==1){
                            return false;
                        }
                        else{
                            checkArray[value] +=1;
                        }

                    }
                }


            }
        }

        return true;
    }
};
