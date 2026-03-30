class Solution {
public:

    bool compareArray(int* arr1, int size1, int* arr2, int size2){
        if(size1 != size2) return false;
        for(int i=0; i < size1; i++){
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()){
            return false;
        }
        
        int s1_map[26] = {0};
        int s2_map[26] = {0};
        int l = 0;
        int r = s1.length();

        // calculating number
        for(int i=0; i<s1.length(); i++){
            s1_map[s1[i] - 'a'] += 1;
            s2_map[s2[i] - 'a'] += 1;
        }

        if(compareArray(s1_map, 26, s2_map, 26))return true;
        while(r < s2.length()){
            
            s2_map[s2[l]-'a'] -=1;
            s2_map[s2[r]-'a'] +=1;

            if(compareArray(s1_map, 26, s2_map, 26))return true;
            
            r += 1;
            l += 1;
        }

        return false;
    }
};
