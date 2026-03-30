class Solution {
public:
    vector<vector<int>> res;

    bool checkDup(vector<int>& v1, vector<int>& v2){
        if(v1.size() != v2.size()) return false;
        for(int i=0; i<v1.size(); i++){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }

    


    void dfs(vector<int>& candidates, vector<int>& path, int index, int target, int sum){
        if(target == sum){
            for(auto v:res){
                if(checkDup(path, v))return;
            }
            res.push_back(path);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(candidates[i] + sum > target)return;
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
