class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;

        for(char c: s){
            sm[c]++;
        }

        for(char c: t){
            tm[c]++;
        }

        return sm == tm;
    }
};

