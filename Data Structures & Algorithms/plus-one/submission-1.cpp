class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--){
            if(digits[i] == 9){
                digits[i] = 0 ;

            }
            else{
                digits[i] += 1;
                return digits;
            }
        }

        vector<int> new_int;
        new_int.push_back(1);
        for(int d:digits){
            new_int.push_back(d);
        }
        return new_int;
    }
};
