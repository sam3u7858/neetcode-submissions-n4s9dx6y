class Solution {
public:
    string stringCal(string& a, string& b, int dir){
        // a -> normal number
        // b -> 0000~9999


        if(a.size()!=b.size()) return "";

        string tmp = a;
        for(int i=0; i<a.size(); i++){
            if(dir >0){
                tmp[i] = a[i] + (b[i] - '0');
            }   
            else{
                tmp[i] = a[i] - (b[i] - '0');
            }
            if(tmp[i] > '9') tmp[i] = '0';
            if(tmp[i] < '0') tmp[i] = '9';
        }
        return tmp;

    }

    int openLock(vector<string>& deadends, string target) {
        string tmp = "0000";
        unordered_map<string, bool> dontVisit;
        string dir[4] ={"0001", "0010", "0100", "1000"}; 
        int res = 0;

        for(const string& s:deadends){
            dontVisit[s] = true;
        }
        if(dontVisit["0000"]) return -1;
        if(target == "0000") return 0;
        
        queue<string> bq;
        bq.push("0000");
        dontVisit["0000"] = true;
        
        while(!bq.empty() ){
            int size = bq.size();
            for(int i=0; i<size; i++){
                auto curr = bq.front(); bq.pop();
                if(curr == target) return res;

                for(auto & v:dir){
                    auto next = stringCal(curr, v, 1);
                    auto prev = stringCal(curr, v, -1);

                    if(dontVisit[next] != true){
                        bq.push(next);
                        dontVisit[next] = true; 
                    }
                    if(dontVisit[prev] != true){
                        bq.push(prev);
                        dontVisit[prev] = true;
                    }
                }
            }

            
            res++;

        }

        

        return -1;
    }
};