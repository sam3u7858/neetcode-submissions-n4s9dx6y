class Solution {
public:
    int appendCharacters(string s, string t) {
        int pt = 0;
     
        int res = 0;
        for(int i=0; i<s.size(); i++){
            if(pt < t.size() && s[i] == t[pt]){
                pt++;
            }
        }

        res = t.size() - pt;


        return res;
    }
};