class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;
        int l = 0;
        int max_f = 0;

        for(int r = 0; r < s.size(); r++){
            count[s[r]]++;
            max_f = max(max_f, count[s[r]]); // we are going to length and make length - maxf > k, so we can ignore smaller maxf     
            
            while ((r - l + 1) - max_f > k){
                count[s[l]] --; // l is out of range, so we wont consider it anymore
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
          
    }

   
};

