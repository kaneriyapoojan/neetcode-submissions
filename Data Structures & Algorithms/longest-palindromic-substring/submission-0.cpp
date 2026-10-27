class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size() == 0) return {};
        if(s.size() == 1) return s;

        int maxL = 0;
        int start = 0;
        for(int c = 0; c < s.size(); c++){

        //for odd length;
            int i = c; 
            int j = c;
            while(i >= 0 && j < s.size() && s[i] == s[j]){

                int l = j - i + 1;
                if(l > maxL){
                    start = i;
                    maxL = l;
                }
                i--;
                j++;
                
            }
            
            i = c;
            j = c + 1;
            while(i >= 0 && j < s.size() && s[i] == s[j]){

                int l = j - i + 1;
                if(l > maxL){
                    start = i;
                    maxL = l;
                }
                i--;
                j++;
                
            }

        }
        return s.substr(start, maxL);

    }
};
