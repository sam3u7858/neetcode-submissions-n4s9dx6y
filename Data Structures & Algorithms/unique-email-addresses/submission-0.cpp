class Solution {
public:
    string emailEscape(string& s){
        bool isPlus = false;
        string str = "";
        int i;
        for(i=0; i<s.size(); i++){
            if(s[i] != '.' &&  !isPlus){
                str += s[i];
            }
            if(s[i] == '+'){
                isPlus = true;
            }
            if(s[i] == '@'){
                str += s[i];
                i++;
                break;
            }
        }

        for(;i<s.size(); i++){
            str += s[i];
        }
        return str;
    }

    int numUniqueEmails(vector<string>& emails) {
        int count = 0;
        unordered_set<string> emailList;

        for(auto& e:emails){
            if(!emailList.count(emailEscape(e))){
                count++;
                emailList.insert(emailEscape(e));
            }
            
        }

        return count;


    }
};