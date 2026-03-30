
class KMP{
    public:
    int solve(string &haystack, string &needle){
        if(needle.empty()) return 0;

        vector<int> lps = buildLPS(needle);
        int i = 0;
        int j = 0;
        while(i < haystack.length()){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            if( j == needle.length()){
                return i - j;
            }

            else if(i < haystack.length() &&  haystack[i] != needle[j]){
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
            

        }
        
        return -1;

    }

    private:
    vector<int> buildLPS(string &needle){
        int m = needle.length();
        vector<int> lps(m, 0);
        int len = 0; // Longest prefix count
        int i = 1;

        while(i < m){
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;

            }
            else{
                if(len !=0){
                    len = lps[len-1];

                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;
        if(needle.empty()) return 0;
        int res = -1;

        KMP solver;
        return solver.solve(haystack, needle);
  
    }
};