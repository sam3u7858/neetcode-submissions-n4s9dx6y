class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> counts(256, 0);
        int n = s.length();

        int l = 0;
        int r = 0;
        int res = 0;
     

        for(r=0; r<n; r++){

            counts[s[r]]++;
            while(counts[s[r]] > 1){  

                
                counts[s[l]]--;
                l++;

               
            
            }

            
            
            res = max(res, r-l+1);
            


        }


        
        return res;
        

    }
};
