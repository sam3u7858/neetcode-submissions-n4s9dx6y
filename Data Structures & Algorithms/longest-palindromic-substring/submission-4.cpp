class Solution {
public:
    string longestPalindrome(string s) {
       string res;
       int resLen = 0;
       // odd check
        for(int i=0; i<s.length(); i++){
            string temp = "";
            temp += s[i];
            int l = i - 1;
            int r = i + 1;
            int templen = 1;
            
            while(l >= 0 && r < s.length()){
                if(s[l] == s[r]){
                    cout << l << " " << r << " " << endl; 
                    temp = s[l] + temp + s[r];
                    cout << temp << endl;
                    templen += 2;
                }
                else{
                    break;
                }
                
                l -= 1;
                r += 1;
            }

            if(templen > resLen){
                resLen = templen;
                res = temp;
            }

        }



       // even check
       int resIdx = 0;
       for(int i = 0; i < s.length(); i++){
           int tempLen = 1;
           int current = i;
           int next = i + 1;

           while(current >= 0 && next < s.length() && s[current] ==  s[next]){
                if(next - current + 1 > resLen){
                    resIdx = current;
                    resLen = next - current + 1;
                    res = s.substr(resIdx, resLen);
                } 
                current--;
                next++;                
              
           }


       }
    

      return res;
    }   
};
