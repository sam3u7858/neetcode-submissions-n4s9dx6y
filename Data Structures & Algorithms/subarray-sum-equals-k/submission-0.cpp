class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int currSum = 0;

        unordered_map<int, int> freq;
        freq[0] = 1;

        int res = 0;

        for(int i=0; i<n; i++){
            int curr = nums[i];
            currSum+=curr;
            if(freq.find(currSum - k)!= freq.end()){
                // add the count to the list:
                res += freq[currSum - k ];
            }

            freq[currSum]++;
            
        }

        
       

       return res;
    }
};