class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int seq_size = nums.size();

        unordered_map<int,int> m;
        // Add items into list;
        for(auto i:nums){
            m[i] = 1; //set
        }

    
        vector<int> sequence_start;
        // "O(2 * n)"
        for(auto i:nums){
            if(m.find(i-1) != m.end()){
                //found i-1
            }
            else{
                sequence_start.push_back(i);
            }
        }

        // "O(3*n)", Find the longest number
        int longestCosectiveCount = 0;
        for(auto i:nums){
            int currentCosectiveCount = 0;
            while(m.find(i + currentCosectiveCount) != m.end()){
                currentCosectiveCount+=1;
            }
            longestCosectiveCount = max(longestCosectiveCount, currentCosectiveCount);
        }
    
        return longestCosectiveCount;
    }
};
