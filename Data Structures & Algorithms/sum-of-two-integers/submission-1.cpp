class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry = 0;
       

        while(b != 0){ // if carry exist
            
            int answer = a ^ b;
            carry = (unsigned int)(a & b)  <<1;
            a = answer;
            b = carry;

        }

    
        return a;
    }
};
