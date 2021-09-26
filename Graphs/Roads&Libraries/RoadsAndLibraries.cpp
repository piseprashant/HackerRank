
int dfs(vector<vector<int>>& v, int src, vector<bool>& visited) {
    visited[src] = true;
    int ans = 1;
    
    for (int i=0; i<v[src].size(); ++i)
    {
        if (!visited[v[src][i]])
        {
            ans += dfs(v, v[src][i], visited );
        }
    }
    return ans;   // size of component
}
    
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    // core logic to create adjanceny list
    vector<vector<int>> v(n+1);
    for (int i=0; i < cities.size(); ++i)
    {
        v[cities[i][0]].push_back(cities[i][1]);
        v[cities[i][1]].push_back(cities[i][0]);
    }
    
    vector<int> comps;
    
    vector<bool> visited(n+1, false);
    
    for (int i=1; i<=n; ++i)
    {
        if (v[i].size()>0 && !visited[i])
        {
            comps.push_back(dfs(v, i, visited));
        }
        // only 1 disconnected city and push only 1 component
        else if (v[i].size() == 0) {
            comps.push_back(1); 
        }
    }
    
    long long int ans = 0;
    
    // business logic
    
    // iterate to all the components
    for (int i=0; i < comps.size(); ++i)
    {
        // is it min cost to build roads or libraries
        // compp n - 1
        ans += min((comps[i] - 1) *c_road + c_lib, comps[i]*c_lib );
    }
    return ans;
}

