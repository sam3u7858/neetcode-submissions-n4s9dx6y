class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        stringstream ss(path);
        string s;
        vector<string> st;


        while(getline(ss, s, '/')){
            if(s ==  "" || s == ".") continue;
            if(s == ".."){
                if(!st.empty()) st.pop_back();
            }
            else{
                st.push_back(s);
            }
        }

        res.reserve(path.size());
        for(auto& str:st){
            res+="/";
            res+=str;
        }
        return res.empty() ? "/" : res;
    }
};