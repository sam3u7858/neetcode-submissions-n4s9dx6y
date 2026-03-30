class Solution {
public:

    int half = 0;
    vector<vector<char>> memo;
    int sumVector(vector<int>& v){
        int sum = 0;
        for(auto &n:v){
            sum += n;
        }
        return sum;
    }

    bool dfs(vector<int>& nums, int curSum , int index){
        if(curSum == half) return true;
        if(curSum > half || index >= nums.size()) return false;

        if(memo[index][curSum] != -1) return memo[index][curSum]; 

        bool res = dfs(nums, curSum+nums[index], index+1) || dfs(nums, curSum, index+1);
        return memo[index][curSum] = res;
        
    }

    bool canPartition(vector<int>& nums) {
        int sums = sumVector(nums);
        if(sums %2 == 1){
            return false;
        }
        half = sums / 2;
        memo.assign(nums.size()+1, vector<char>(half+1, -1));
        return dfs(nums, 0, 0);


    }
};
