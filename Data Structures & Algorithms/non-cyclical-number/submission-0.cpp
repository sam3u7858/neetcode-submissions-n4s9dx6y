class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> hashmap;


        while(n != 1){

            n = calculateDigits(n);
            
            // Not present in the hash set
            if (hashmap.find(n) == hashmap.end()){
                hashmap[n] = true;  
            }
            // Repeated, No way to escape
            else{
                return false;
            }

        }

        return true;


    }

    int calculateDigits(int n){
        string s =  to_string(n);
        int sum = 0;
        for(int i=0; i<s.length(); i++){
            int digit = (s[i] - '0');
            sum += digit * digit;
        }
        return sum;
    }
};
