class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }

        int map[26] = {0};
        for(char c:s){
            map[c - 'a'] +=1;
        }

        for(char c:t){
            map[c - 'a'] -=1;
        }

        for(int i = 0; i<26; i++){
            if(map[i] != 0) return false;
        }
        return true;
    }
};
