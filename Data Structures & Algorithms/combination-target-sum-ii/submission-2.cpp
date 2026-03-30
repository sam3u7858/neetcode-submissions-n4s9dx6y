class Solution {
public:
    vector<vector<int>> res;


   
    void dfs(vector<int>& candidates, vector<int>& path, int index, int target, int sum){
        if(target == sum){
            res.push_back(path);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(candidates[i] + sum > target)return;

            if (i > index && candidates[i] == candidates[i-1]) {
            continue;
            }

            path.push_back(candidates[i]);
            dfs(candidates, path, i+1, target, sum+candidates[i]);
            path.pop_back();
        }
        return;

        


    }

    

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        dfs(candidates, vec, 0, target, 0);
        return res;
    }
};
