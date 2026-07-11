class Solution {
public:
    int DRAGON(vector<vector<int>>& graph, vector<int>& v, int cur) {
        int n = graph[cur].size();
        for (int i = 0; i < n; i++) {
            int n1 = graph[graph[cur][i]].size();
            if (n != n1)
                return -1;
            for (int j = 0; j < n1; j++)
                if (!v[graph[graph[cur][i]][j]] ||
                    v[graph[graph[cur][i]][j]] < 0)
                    return -1;
        }
        return 1;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int count = 0;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            if (v[i] < 0)
                continue;
            int n1 = graph[i].size();
            int j = 0;
            v[i] = 1;
            while (j < n1) {
                if (!v[graph[i][j]])
                    v[graph[i][j]] = 1;
                else
                    break;
                j++;
            }
            if (j == n1)
                if (DRAGON(graph, v, i) > 0)
                    count++;
            j = 0;
            while (j < n1) {
                v[graph[i][j]] = -1;
                j++;
            }
            v[i] = -1;
        }
        return count;
    }
};