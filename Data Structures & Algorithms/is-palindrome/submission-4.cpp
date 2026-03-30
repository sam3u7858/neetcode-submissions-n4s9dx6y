class Solution {
public:
    bool vaildChar(char c){
        //In a-z || A-Z
        if(toupper(c)-'A' < 26  &&  toupper(c) -'A' >=0) return true;
        if(c - '0' <= 9 &&  c-'0' >=0) return true;
        return false;

    }

    bool isPalindrome(string s) {
        vector<char> validString;
        for(auto const& c:s){
            if(vaildChar(c)) validString.push_back(c);
        }

        int l = 0;
        int r = (int)validString.size()-1;
        while(l < r){
            
            if(toupper(validString[l]) != toupper(validString[r])){
               
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
