class Solution {
public:
    vector<vector<int>> res;
    void printVector(vector<int> &n){
        for(auto& i:n){
            cout << i << ","  ;
        }
        cout << endl;
        return;

    }
    void dfs(vector<int>& nums, vector<int> &path){
        // base case
        if(nums.size() == 0){
            res.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            path.push_back(nums[i]);
            
            int value_temp = nums[i];
            nums.erase(nums.begin() + i);
            cout << "Current i : " << i << " // size of nums this layer : " <<  nums.size() << endl;
            
            dfs(nums, path);
            nums.insert(nums.begin() + i, value_temp); 
            path.pop_back();
            printVector(nums);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> p;
        dfs(nums, p);
        return res;
    }
};
