class Solution {
public:
    
    string ans="";
      bool func(string &s,int i,int j){
        if(i>j)return true; 
       
        if(s[i]==s[j]){
            bool res=func(s,i+1,j-1);
            string s1=s.substr(i,j-i+1);
            if(res && ans.size()<s1.size()) ans=s1;
            return res;
        }
        return false;
    }
    string longestPalindrome(string s) {  
        ans="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                func(s,i,j);
            }
        }
          return ans;
    }
};
