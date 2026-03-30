class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> wordSets;
        for(auto& word:wordList){
            wordSets[word] = true;
        }

        if(wordSets.find(endWord) == wordSets.end()) return 0;

        // BFS from first letter
        int count = 1;
        queue<string> qe;

        qe.push(beginWord);

        while(!qe.empty()){
            int size = qe.size();
            for(int k=0; k<size; k++){
                string curr = qe.front();
                qe.pop();

                for(int i=0; i<curr.size(); i++){
                    char og = curr[i];
                    for(char j='a'; j<='z'; j++){
                        curr[i] = j;
                        if(curr == endWord) return count+1;

                        if(wordSets.count(curr)){
                            qe.push(curr);
                            wordSets.erase(curr);
                        }
                    }
                    curr[i] = og;
                }
            }
            count ++;
        }

        return 0; 
        
        
    }
};
