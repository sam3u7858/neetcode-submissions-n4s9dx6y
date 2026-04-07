class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0)return 0;

        unordered_map<char, int> freq;
        
        int maxCount = 0;
        int res = 0;
        int l = 0;
        for(int r=0; r<s.size(); r++){
            freq[s[r]] +=1;
            maxCount = max(maxCount, freq[s[r]]);

            while((r-l+1)-maxCount > k){
                freq[s[l]]--;
                l++;
            }
            res = max((r-l+1), res);
        }
        return res;
    }
    
};
