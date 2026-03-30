class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int seq_size = nums.size();

        unordered_map<int,int> m;
        // Add items into list;
        for(auto i:nums){
            m[i] = 1;
        }

        int longestCosectiveCount = 0;
        for(auto i:nums){
            int currentCosectiveCount = 0;
            while(m.find(i + currentCosectiveCount) != m.end()){
                // found next
                
                currentCosectiveCount +=1;
            }



            longestCosectiveCount = max(currentCosectiveCount, longestCosectiveCount);
        }
        return longestCosectiveCount;
    }
};
