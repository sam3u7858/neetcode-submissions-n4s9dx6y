class Solution {
private:
    void printVector(std::vector<std::string> &t) {
    for (const std::string &s : t) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

    vector<string> splitPath(string& path){
        vector<string> res;
        string tmp;
        for(int i=0; i<path.size(); i++){
            char c = path[i];
            if(c == '/' ){
                if(tmp.size()!=0){
                    res.push_back(tmp);
                }
                tmp = "";
            }
            else{
                tmp+=c;
                if(i==path.size()-1){
                    res.push_back(tmp);
                }
            }

        }

        //printVector(res);
        return res;


    }

public:
    string simplifyPath(string path) {
        string res;
        vector<string> pathSplit = splitPath(path);
        stack<string> st;

     

        for(string p:pathSplit){
            if(p == ".."){
                if(!st.empty())st.pop();
            }
            else if(p == "."){
                continue;
            }
            else{
                st.push(p);
            }

        }

        vector<string> tmp;
       
        while(!st.empty()){
            tmp.push_back(st.top()); st.pop();
        }

        reverse(tmp.begin(), tmp.end());
        

        res+='/';
        for(int i=0; i<tmp.size();i++){
            string curr = tmp[i];
            res+=curr;
            if(!(i==tmp.size()-1)){
                res+="/";
            }
        }

        return res;
    }
};