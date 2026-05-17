class Solution {
public:

    int getPaliCountFromPos(string &s, int m){
        int count = 0;
        int n = s.length();

        // odd;
        int l = m - 1;
        int r = m + 1;
        while(l >= 0 && r < n){
            if(s[l] == s[r]) count++;
            else{
                break;
            }

            --l;
            ++r;
        }

        // even
        if(m+1 < n && s[m+1] == s[m]){
            l = m-1;
            r = m+2;
            count++;

            while(l>=0 && r<n){
                if(s[l] == s[r]) count++;
                else{
                    break;
                }
                --l;
                ++r;
            }
        }

        return count;



    }



    int countSubstrings(string s) {
        int res = 0;
        int n = s.length();

        for(int m=0; m<n; m++){
            res+= getPaliCountFromPos(s, m);
            res+=1;
        }

        return res;


    }
};
