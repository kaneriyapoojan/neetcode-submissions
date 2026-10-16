class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;

        for(char c: s){
            if(sm.find(c) !=sm.end()){
                sm[c]+=1;
            } else {
                sm[c] = 1;
            }

        }

        for(char c: t){
            if(tm.find(c) !=tm.end()){
                tm[c]+=1;
            } else {
                tm[c] = 1;
            }
        }

        for(char c: s){
            if(sm[c] != tm[c]){
                return false;
            }
        }
        return true;
    }
};

