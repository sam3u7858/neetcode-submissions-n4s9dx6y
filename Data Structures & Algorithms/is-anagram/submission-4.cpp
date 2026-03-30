class Solution {
public:
    bool isAnagram(string s, string t) {
        int matches[26] = {0};
        for(auto &c:s){
            matches[c - 'a'] += 1;
        }

        for(auto&c:t){
            matches[c - 'a'] -=1;
        }


        for(int i=0; i<26; i++){
           if(matches[i]!=0){
                return false;
           }
        }
        return true;

    }
};
