class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_set<int> m;
        for(int val : nums){
            
            if(m.find(val) != m.end()){
                return true;
            }
            m.insert(val);
        }
        return false;
    }
};