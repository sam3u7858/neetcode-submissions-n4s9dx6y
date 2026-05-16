class Solution {
public:

    bool isPalindromic(string s, int start, int end){
        int l = start;
        int r = end;

        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            ++l;
            --r;
        }
        return true;


    }

    string longestPalindrome(string s) {
        int n = s.length();
        int resLeng = 0;
        string res = "";

      
        // Brute force
        for(int l=0; l<n; l++){
            for(int r=l; r<n; r++){
                if(isPalindromic(s, l, r)){
                    if(r-l+1 > resLeng){
                        res = s.substr(l, r-l+1);
                        resLeng = r-l+1;
                    }
                }



            }
        }

        
        
        return res;
    }
};
