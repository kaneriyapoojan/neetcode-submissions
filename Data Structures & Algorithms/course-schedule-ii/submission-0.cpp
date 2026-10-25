class Solution {

    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visit;
    unordered_set<int> cycle;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> ans;

        for(int i = 0; i < numCourses; i++){
            preMap[i] = {};
        }
        for( auto& pre: prerequisites){
            preMap[pre[0]].push_back(pre[1]);
        }

        for(int c = 0; c < numCourses; c++){
            if(!dfs(c, ans)){
                return {};
            }
        }
        return ans;
    }

    private:
    bool dfs(int course, vector<int>& ans){

        if(cycle.count(course)){
            return false;
        }
        if(visit.count(course)){
            return true;
        }

        cycle.insert(course);
        if(preMap.count(course)){
            for(int pre: preMap.at(course)){
                if(!dfs(pre, ans)){
                    return false;
                }
            }
        }
        cycle.erase(course);
        visit.insert(course);
        ans.push_back(course);
        return true;
    }
};
