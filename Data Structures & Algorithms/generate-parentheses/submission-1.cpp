class Solution {
public:

    vector<string> preres;
    void dfs(int n, string s, int open, int close){
        if(n == open && n == close){
            preres.push_back(s);
            return;
        } 

        if( close > open){
            // pruning
            return;
        }

        if(open < n) dfs(n, s+"(",open+1, close);
        if(close < n) dfs(n, s+")", open, close+1);

    }


    vector<string> generateParenthesis(int n) {
        dfs(n, "", 0, 0);
        return preres;
    }
};
