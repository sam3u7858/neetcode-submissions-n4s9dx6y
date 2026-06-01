class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        if(s.empty()) return true;
        vector<char> dct;

        for(const auto c:s){
            dct.push_back(c);
        }

        int curr = 0;
        for(int i=0; i<t.size(); i++){
            
            if(dct[curr] == t[i]){
                if(curr == dct.size()-1){
                    return true;
                }
                curr++;
            }
            
        }

        return false;
    }
};