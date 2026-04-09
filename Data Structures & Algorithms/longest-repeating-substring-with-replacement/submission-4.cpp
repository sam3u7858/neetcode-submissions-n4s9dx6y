class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, int> freq;
        int maxCount = 0;

        int l = 0;
        for(int r=0; r<s.size(); r++){
            char curr = s[r];
            freq[curr]++;
            maxCount = max(freq[curr], maxCount);

            while((r-l+1) - maxCount > k){
                freq[s[l]]--;
                l++;

            }

            
            res = max(res, r-l+1);

        }


        return res;
    }
};
