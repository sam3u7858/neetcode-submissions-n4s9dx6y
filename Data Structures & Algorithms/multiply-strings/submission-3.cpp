class Solution {
public:
    string multiply(string num1, string num2) {
        long long a = convertStringToInt(num1);
        long long b = convertStringToInt(num2);
        long long rs = a * b;

      
        string result = "";
        if(rs==0){
        return "0";
        }
   
        while(rs>0){
            result += char(rs % 10 + '0');

            rs = rs / 10;

        }
        reverse(result.begin(), result.end()); 
        return result;
        
    }
    int convertStringToInt(string num){
        int val = 0;
        int pow = 1;
        for(int i = num.length()-1; i>=0; i--){
            val += pow * (num[i] - '0');
            pow*=10;
        }
        
        return val;

    }
};
