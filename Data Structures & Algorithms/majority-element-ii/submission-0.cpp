class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int N = nums.size();
        if(N == 0)return {};

        int can1 = -1;
        int can2 = -1;

        int count1 = 0;
        int count2 = 0;
        
        for(auto const& n:nums){
        
            if(n == can1){
                count1++;
            }
            else if(n == can2){
                count2++;
            }
            else if(count1 == 0){
                can1 = n;
                count1 = 1;
            }
            else if(count2 == 0){
                can2 = n;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }

        }

        vector<int> res;
        // can1
        count1 = 0;
        count2 = 0;
        for(auto const& n:nums){
            if(n == can1){
                count1++;
            }
            else if(n == can2){
                count2++;
            }
        }

        if(count1 > N/3) res.push_back(can1);
        if(count2 > N/3) res.push_back(can2);

        return res;

    }
};