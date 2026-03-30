class Solution {
public:
    vector<vector<string>> res;

    vector<string> addToRes(vector<int> path, int n){
        vector<string> path_temp;
        for (int i: path){
           string temp(n, '.');
           temp[i] = 'Q';
           path_temp.push_back(temp);
        }
        return path_temp;
    }
    void dfs(int n, int phase, vector<int>& path){
        if(phase >= n){ // From 0-n-1
            res.push_back(addToRes(path, n));
            return;
        }

        for(int i=0; i<n; ++i){
            bool valid = true;
            // Check is there a queen in same row
            for(int j=0; j<path.size(); ++j){
                int pos = path[j];
                if(pos == i){
                    valid = false;
                    break; // same row, invalid path
                }
                // Check diagonal
                if(abs(j-phase) == abs(pos-i)){
                    valid = false;
                    break; // in same diagonal, invalid path.
                }
                
            }
            
            if(valid == true){
                path.push_back(i);
                dfs(n, phase+1, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> path;
        dfs(n, 0, path);
        return res;
    }
};