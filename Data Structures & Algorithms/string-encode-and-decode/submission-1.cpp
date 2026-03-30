class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;

        for(string s:strs){
            encodedString += to_string(s.length()) + "#" + s;
        }

        return encodedString;

    }

    vector<string> decode(string s) {
        vector<string> decodedString;
        int i = 0;
        while( i < s.size()){
            int j = i;
            while(s[j]!= '#') j++;
            int len = stoi(s.substr(i, j - i));
            decodedString.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
    
       
        return decodedString;

    }
};
