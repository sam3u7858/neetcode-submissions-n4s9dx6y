class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> inDegree(26, -1);
        vector<unordered_set<char>> adj(26);

        for(const string& w :words){
            for(char c: w){
                if(inDegree[c - 'a'] == -1) inDegree[c - 'a'] = 0;
            }
        }


        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            if(w1 > w2 && w1.find(w2) == 0){
                return ""; //invalid lexicographcally 
            }
            for(int j=0; j<min(w1.size(), w2.size()); j++){
            
                if(w1[j] != w2[j]){
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';
                    // This time v > u and u -> v
                    if(adj[u].find(v) ==  adj[u].end()){
                        adj[u].insert(v);
                        inDegree[v]++;
                    }
                    break;
                }
            }
        }

        queue<int> q;
        int totalNodes = 0;
        for(int i=0; i<26; i++){
            if(inDegree[i] != -1){
                totalNodes += 1;
                if(inDegree[i] == 0) q.push(i);
            }
        }

        string res = "";
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res += (char)(curr + 'a');

            for(int nei:adj[curr]){
                inDegree[nei]--;
                if(inDegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        return res.length() == totalNodes ? res : "";

    }
};
