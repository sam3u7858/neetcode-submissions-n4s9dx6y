class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";

        int n = word1.size();
        int m = word2.size();
        int i = 0;

        
        res.reserve(n + m);
        for(i=0; i<min(n, m); i++){
            res+=word1[i];
            res+=word2[i];
        }

        if(n<m){
            res.append(word2.begin()+i, word2.end());
        }
        else{
            res.append(word1.begin()+i , word1.end());
        }
        return res;
    }
};