class Solution {
public:

    bool isFit(vector<int>& nums, int capa, int k){
        int reg = 1;
        int curr = 0;
   
        for(auto const& n: nums){
            if(n + curr > capa){
                reg += 1;
                curr = 0;
                if(reg > k) return false;
            }

            curr += n;
            
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // vector<int> prefixSum;
        // int res = 0; 
        // prefixSum[0] = nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     prefixSum[i] = prefixSum[i-1] + nums[i];
        // }

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(isFit(nums, mid, k)) high = mid - 1;
            else{
                low = mid + 1;
            }
        }

        

        


        return low;


    }
};