class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int res = 0;
        int n = s.size();

        vector<int> dp(n+1, 0);
        

        for(int i=1; i<n+1; i++){
            dp[i] = dp[i - 1] + 1;

            for(auto const& d:dictionary){
                int x = d.size();
                if(i-x >= 0 && s.substr(i-x, x) == d){
                    dp[i] = min(dp[i], dp[i - x]);
                }
            }
        }
        

        return dp[n];
    }
};