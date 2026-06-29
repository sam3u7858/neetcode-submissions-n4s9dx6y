class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m) return false;

        unordered_map<char, char> convert_s;
        unordered_map<char, char> convert_t;

        char startCharS = 1;
        char startCharT = 1;

        for(char& c: s){
            if(convert_s.find(c) == convert_s.end()){
                convert_s[c] = startCharS++;
            }
            
            c = convert_s[c];
        }

         for(char& c: t){
            if(convert_t.find(c) == convert_t.end()){
                convert_t[c] = startCharT++;
            }
            
            c = convert_t[c];
        }




        return s == t;

    }
};