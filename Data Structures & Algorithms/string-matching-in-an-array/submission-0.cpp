class Solution {
public:

    bool isSubstring(string& word, string& needle){
        for(int i=0; i<word.size() - needle.size()+1; i++){
            if(word.substr(i, needle.size()) == needle) return true;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
            
            vector<string> res;

            for(int i=0; i<words.size(); i++){
                string& needle = words[i];
                int needle_size = needle.size();
                for(int j=0; j<words.size(); j++){
                    if (i==j) continue;
                    //compare words[i] and words[j];
                    
                    string& word = words[j];
                    if(word.size() < needle.size()) continue;

                    if(isSubstring(word, needle)){
                        res.push_back(needle);
                        break;
                    }
                    
                    
                }
            }
            return res;
    }
};