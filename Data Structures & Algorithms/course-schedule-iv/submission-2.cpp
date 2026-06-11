class Node {
    public:
    int val;
    vector<Node> subs;

    Node(int val){
        this->val = val;
    }
};


class Solution {
public:
    int n;
    bool isPre(int a, int b, unordered_map<int, vector<int>> &_pre, vector<vector<bool>> &memo ){

        if(memo[a][b] == true) return true;

        queue<int> qs;
        qs.push(a);
        vector<bool> visited(n, false);

        while(!qs.empty()){
            int query = qs.front(); qs.pop();
            
            
            for(auto const& p: _pre[query]){
                if(memo[p][b] == true) return true;

                if(p == b) {
                    memo[a][b] = true;
                    return true;
                }
                else{
                    memo[a][p] = true;
                    if(!visited[p]){
                        qs.push(p);
                        visited[p] = true;
                    }
                    
                }
            }

        }
        
        

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> res;
        n = numCourses;
        vector<vector<bool>> memo(n+1, vector<bool>(n+1, false));
       

        //Node* c = new Node(1);
        unordered_map<int, vector<int>> _pre;
        
        for(auto const& p: prerequisites){
            int curr = p[1];
            int pre = p[0];

            if(_pre.find(pre) ==  _pre.end()){
                vector<int> tmp;
                tmp.push_back(curr);
                _pre[pre] = tmp;
            }
            else{
                _pre[pre].push_back(curr);
            }
        }
        


        for(auto const& q:queries){
            res.push_back(isPre(q[0], q[1], _pre, memo));
        }


        return res;
    }
};

