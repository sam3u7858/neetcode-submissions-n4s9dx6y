class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int cont = 0;
        for(auto const& n:nums){
            if(n==1){
                cont++;
            }
            else{
                res = max(cont, res);
                cont=0;
            }
        }

        res = max(cont, res);
        cont=0;

        return res;
    }
};