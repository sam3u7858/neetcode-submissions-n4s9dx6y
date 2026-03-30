class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry = 0;
        int sum = 0;
        for(int i=0; i<32; i++){
            int x =  (1 << i) & a ;
            int y =  (1 << i) & b  ;
            
            sum |= carry ^ x ^ y; 
            carry = (unsigned int)((x & y) | (carry & (x ^ y))) << 1;

        }
        
        return sum;
    }
};
