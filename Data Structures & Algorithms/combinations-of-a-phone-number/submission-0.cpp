class Solution {
public:
    vector<string> res;

    vector<char> getPossibleChars(char digit){
        if(digit == '2'){
            return {'a', 'b', 'c'};
        }
        if(digit == '3'){
            return {'d', 'e', 'f'};
        }
        if(digit == '4'){
            return {'g', 'h', 'i'};
        }
        if(digit == '5'){
            return {'j', 'k', 'l'};
        }
        if(digit == '6'){
            return {'m', 'n', 'o'};
        }
        if(digit == '7'){
            return {'p', 'q', 'r', 's'};
        }
        if(digit == '8'){
            return {'t', 'u', 'v'};
        }
        if(digit == '9'){
            return {'w', 'x', 'y', 'z'};
        }

    };

    void dfs(string digits, string path, int currentIndex){
        
        if(digits == ""){
            return;
        }
        if(currentIndex >= digits.length()){
            res.push_back(path);
            return;
        }

        vector<char> vs = getPossibleChars(digits[currentIndex]);
           
        //DFS
        for(int j=0; j<vs.size(); j++){
            // Add to path
            dfs(digits, path+vs[j], currentIndex+1);
        }

    }
    
    vector<string> letterCombinations(string digits) {
            dfs(digits, "", 0);
            return res;
    }
};
