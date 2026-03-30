class Solution {
public:

    vector<vector<string>> res;


    bool isPalindrome(string s){
        int head = 0;
        int tail = s.length() - 1;

        while(head < tail){
            if(s[head]!=s[tail]){
                return false;
            }

            head += 1;
            tail -= 1;
        }
        return true;
    }

    void dfs(string s, int current_index, vector<string>& path){
         if(current_index >= s.length()){
            res.push_back(path);
            return;
         }

         for(int i=current_index; i < s.length(); ++i){
            string sub = s.substr(current_index, i - current_index + 1);

            if(isPalindrome(sub)){
                path.push_back(sub);
                dfs(s, i+1, path);

                // Backtracking
                path.pop_back();
            }
            else{
                continue;
            }
         }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }
};
