class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        for(int mask=0; mask < (1<<n); mask++){
            int xorr = 0;
            for(int i=0; i<n; i++){
                if((mask & (1 << i)) !=0){
                    xorr ^= nums[i];
                }
            }
            res += xorr;
        }
        return res;
       
    }
};