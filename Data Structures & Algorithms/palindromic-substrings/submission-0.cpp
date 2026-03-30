class Solution {
public:
    int countSubstrings(string s) {
        int res = 0; // count

        //odd
        for(int i = 0; i < s.length(); i++){
            int l = i;
            int r = i;

            while(l >= 0 && r < s.size() && s[l] == s[r]){
                res +=1;
                l--;
                r++;
            }
        }

        //even
        for(int i = 0; i < s.length(); i++){
            int curr = i;
            int next = i+1;
            while(curr >=0 && next < s.length() && s[curr] == s[next])
            {
                res+=1;
                curr--;
                next++;
            }
        }

        return res;
    }
};
