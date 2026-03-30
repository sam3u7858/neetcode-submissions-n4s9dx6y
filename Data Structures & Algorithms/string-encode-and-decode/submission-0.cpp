class Solution {
public:

    vector<int> sub;

    string encode(vector<string>& strs) {
        string encodedString = "#";

        for(string s:strs){
            string c = "";
            int leng = 0;
            for(char c:s){
                encodedString+=c;
                leng+=1;

            }
            sub.push_back(leng);
            
        }

        return encodedString;

    }

    vector<string> decode(string s) {
        vector<string> decodedString;
        int cursor = 1;
        
        for(int i=0; i<sub.size(); i++){
            string substring = s.substr(cursor, sub[i]);
            cursor = cursor + sub[i];
            decodedString.push_back(substring);
        }
        

        return decodedString;

    }
};
