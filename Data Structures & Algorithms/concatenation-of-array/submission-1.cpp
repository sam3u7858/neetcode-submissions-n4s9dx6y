class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(2*size,0);
        for(int i=0; i<2*size; i++){
            res[i] = nums[i%size];
        }
        return res;
    }
};