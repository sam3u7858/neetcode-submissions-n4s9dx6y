class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;

        unordered_map<char, int> charSet;

        for(int r=0; r<s.size();  r++){
            if(charSet.find(s[r])!=charSet.end()){
                // The current char is duplicate  
                if(l < charSet[s[r]]+1) l = charSet[s[r]]+1;
                
                charSet[s[r]] = r;

            }  

            charSet[s[r]] = r; 
            res = max(res, r-l+1);
        }
        return res;
    }
};
