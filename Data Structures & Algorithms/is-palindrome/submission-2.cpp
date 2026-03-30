class Solution {
public:
    bool vaildChar(char c){
        if(c-'a' < 26 && c-'a'>=0) return true;
        if(c-'A' < 26 && c-'A'>=0) return true;
        if(c-'0'< 10 && c-'0' >=0) return true;
        return false;
    }

    
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.length() - 1;

        
        
        //w a sitacaroracatisa w
        while(head < tail){
            while(head < tail && !vaildChar(s[head]))head+=1;
            while(head < tail && !vaildChar(s[tail]))tail-=1;
            
            if(tolower(s[head]) != tolower(s[tail])){
                return false;
            }
            head+=1;
            tail-=1;
        }
        return true;
       

    }
};