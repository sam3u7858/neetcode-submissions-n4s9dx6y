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
        int resl= 0;
        int resr =0;

      
        // Brute force
        for(int l=0; l<n; l++){
            for(int r=l; r<n; r++){
                if(isPalindromic(s, l, r)){
                    if(r-l+1 > resLeng){
                        resl = l;
                        resr = r;
                        resLeng = r-l+1;
                    }
                }



            }
        }

        
        
        return s.substr(resl, resr-resl+1);
    }
};
