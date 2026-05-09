class Solution {
public:
    vector<vector<int>> res;
    map<vector<int>, bool> maps;
    void printVector(vector<int>& pf){
        printf("[");
        for(auto const& p:pf){
            printf("%d ", p);
        }

        printf("]\n");
    }

    void dfs(vector<int>& perm, vector<int>& nums, int k){

     

        
    

        if(perm.size()==k){
            if(maps.find(perm) == maps.end()) {
                res.push_back(perm);
                maps[perm] = true;
            }
            
            
            return;
        }

     

        for(int i=0; i<nums.size(); i++){
            int tmp = nums[i];
            perm.push_back(tmp);
            swap(nums[i], nums[nums.size()-1]);
            nums.pop_back();
            dfs(perm, nums, k);

            
            nums.push_back(tmp);
            swap(nums[nums.size()-1], nums[i]);
            perm.pop_back();
        }


        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> perm = {};
        sort(nums.begin(), nums.end());

        dfs(perm, nums, nums.size());
        return res;
    }
};