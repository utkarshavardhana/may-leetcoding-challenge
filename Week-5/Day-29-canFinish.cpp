class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int> > graph(numCourses);
        vector<int> Indegree(numCourses);
        for(auto & prerequisite : prerequisites) {
            graph[prerequisite[0]].emplace(prerequisite[1]);
            Indegree[prerequisite[1]]++;
        }
        queue<int> vQue;
        for(int i = 0 ; i < numCourses ;i++ )
            if(!Indegree[i]) {
                vQue.push(i);
            }
        while(!vQue.empty()) {
           int node =  vQue.front();    vQue.pop();
           for(auto elem : graph[node]) {
               Indegree[elem]--;
               if(!Indegree[elem]) {
                   vQue.push(elem);
               }
           }
        }
        for(auto elem : Indegree) {
            if(elem > 0)
                return false;
        }
        return true;
    }
};
