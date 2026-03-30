class CountSquares {
public:

    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            return std::hash<T1>{}(p.first) ^ (std::hash<T2>{}(p.second) << 1);
        }
    };

    unordered_map<std::pair<int, int>, int, pair_hash> freqMap;

    CountSquares() {

    }
    
    void add(vector<int> point) {
        // Check if there is a key:
        std::pair<int, int> key = {point[0], point[1]};
        bool ifKey = freqMap.find(key) != freqMap.end();
        if(ifKey){
            freqMap[key] +=1;
        }
        else{
            freqMap[key] = 1;
        }
    }
    
    int count(vector<int> point) {
        // pass 1
        int x = point[0] , y = point[1];
        int possibleCount = 0;
        
        for (const auto& entry : freqMap) {
            auto key = entry.first;
            int qx = key.first, qy= key.second;

            if (abs(qx - x) != abs(qy - y) || qx == x || qy == y)
                continue;
            int freq = freqMap[{qx, qy}];
            
            auto it1 = freqMap.find({qx, y});   // (qx, y)
            if (it1 == freqMap.end()) continue;

            auto it2 = freqMap.find({x,  qy});  // (x,  qy)
            if (it2 == freqMap.end()) continue;

            possibleCount +=  entry.second * it1->second * it2->second;

           
        }
        
        return possibleCount;

    }
};
