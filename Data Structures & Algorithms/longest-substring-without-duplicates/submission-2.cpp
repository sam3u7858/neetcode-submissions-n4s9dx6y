class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> appear(128, false);
        int l=0;
        int res=0;
        for(int r=0; r<s.size(); r++){
            while(appear[s[r]]){
               
                appear[s[l]] = false;
                l++;
                
    } 
         
            appear[s[r]] = true;
            res = max(res, r-l+1);
        }
        return res;

    }
};
