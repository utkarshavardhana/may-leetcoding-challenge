class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        for(vector<int> d : dislikes) {
            graph[d[0]-1].push_back(d[1]-1);
            graph[d[1]-1].push_back(d[0]-1);
        }
        
        vector<int> colors(N);
        for(int i = 0; i < N; i++) {
            if(colors[i] == 0 && !dfs(graph, colors, i, 1)) return false;
        }
        
        return true;
    }
    
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int idx, int cc) {
        if(colors[idx] != 0) return colors[idx] == cc;
        colors[idx] = cc;
        
        for(int nidx : graph[idx]) {
            if(!dfs(graph, colors, nidx, -cc)) return false;
        }
        return true;
    }
};
