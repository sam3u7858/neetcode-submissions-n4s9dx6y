class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> resStack;

        string currentStr = "";
        int k = 0;


        for(char c:s){
            if(isdigit(c)){
                k = k * 10 + (c-'0');

            }

            else if(c == '['){
                countStack.push(k);
                resStack.push(currentStr);
                currentStr = "";
                k = 0;
            }
            else if(c == ']'){
                string temp = currentStr;
                currentStr = resStack.top();
                resStack.pop();

                int rep = countStack.top();
                countStack.pop();

                while(rep--){
                    currentStr += temp;
                }
            }
            else{
                currentStr += c;
            }
        }
        return currentStr;
    }
};