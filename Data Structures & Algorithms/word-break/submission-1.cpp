class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        
        vector<bool> dp(n+1, false);
        unordered_set<string> dct;
        for(auto const& s: wordDict){
            dct.insert(s);
        }
        dp[0] = true;


        for(int i=1; i<=n; i++){
            dp[i] = false;
            for(auto const &word:wordDict){
                int len = word.length();
                if(i >= len && dp[i-len] && s.substr(i-len, len) == word){
                
                    dp[i] = true;
                    break;
                }
            }

        }


        return dp[n];
    }
};
