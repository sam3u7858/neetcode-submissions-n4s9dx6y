class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char, int> m;

        if(s.length()!=t.length()){
            return false;
        }

        for(char c: s){
            m[c] +=1;
        }

        for(char c: t){
            if(m.find(c) == m.end()){
                return false;
            }
            else if(m[c] == 0){
                return false;
            }
            else{
                m[c] -=1;
            }
        }
        return true;
    }
};
