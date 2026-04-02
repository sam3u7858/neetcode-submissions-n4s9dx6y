class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCount = 0;
        int res = 0;
        int l = 0;
        vector<int> counts(26, 0);

        for(int r=0; r<s.size(); r++){
            counts[s[r] - 'A'] +=1;
            maxCount = max(counts[s[r] - 'A'], maxCount);

            while((r-l+1) - maxCount > k){
                counts[s[l] - 'A']--;
                l++;
            }
            res = max((r-l+1), res);


        }

        return res;


    }
};
