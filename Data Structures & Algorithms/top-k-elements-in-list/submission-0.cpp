class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> unique;
        unordered_map<int,int> bucket;

        for(int n:nums){
            if(bucket.find(n) != bucket.end()){
                bucket[n] += 1;    
            }
            else{
                bucket[n] = 1;
                unique.push_back(n);
            }
        }

        vector<int> result;
        for(int i=0; i<k; i++){
            int maxN = -1001; // As problem states
            int currentMaxN = -1001;  
            for(int n:unique){
                int temp_queried_number_from_dict = bucket[n];
                if( temp_queried_number_from_dict > maxN){
                    maxN = temp_queried_number_from_dict;
                    currentMaxN = n;
                }
            }
            result.push_back(currentMaxN);
            bucket[currentMaxN] = 0;
        }
        return result;
    }
};
