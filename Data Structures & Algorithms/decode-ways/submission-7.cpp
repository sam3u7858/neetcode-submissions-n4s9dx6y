class Solution {
public:
    int numDecodings(string s) {

        if(s.size() == 0)return 0;
        int n = s.size();
        
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        dp[n-1] = (s[n-1] != '0') ? 1 : 0;

        for(int i=n-2; i>=0; i--){
            dp[i] = 0;
            if(s[i] != '0') dp[i] += dp[i+1];
            if(i+1 < n){
                int two = stoi(s.substr(i, 2));
                if(two >= 10 && two <=26){
                    dp[i] += dp[i+2];
                }
            } 
            
            



        }

        return dp[0];
    }
};
