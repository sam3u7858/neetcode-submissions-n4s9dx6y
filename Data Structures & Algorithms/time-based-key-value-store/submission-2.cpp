class TimeMap {
public:
    unordered_map<int, unordered_map<string, string>> tmap; 
    int mostRecent;

    TimeMap() {
        mostRecent = 0;
    }
    
    void set(string key, string value, int timestamp) {
        tmap[timestamp][key] = value;
        mostRecent = max(mostRecent, timestamp);
        return;
    }
    
    string get(string key, int timestamp) {
        unordered_map<string, string> timestamp_map;
        if(tmap.find(timestamp) != tmap.end()){
             timestamp_map = tmap[timestamp];
        }
        else if(mostRecent == 0){
            return "";
        }
        else{
            for(int i=timestamp; i>0; i--){
                if(tmap.find(i) != tmap.end()){
                    timestamp_map = tmap[i];

                     if(timestamp_map.find(key) != timestamp_map.end()){
                        return timestamp_map[key];
                    }
                   
                }
            }
        }

        if(timestamp_map.find(key) != timestamp_map.end()){
            return timestamp_map[key];
        }
        else{
            return "";
        }




    }
};
