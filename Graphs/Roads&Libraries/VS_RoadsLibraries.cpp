
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
//#include<bits/stdc++.h>

using namespace std;

int dfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[src] = true;
    int cost = 0;

    for (int i = 0; i < adj[src].size(); ++i)
    {
        if (!visited[adj[src][i]])
        {
            cost += 1;
            cost += dfs(i, adj, visited);
        }
    }
    return cost;   // size of component
}

long roadsAndLibraries(int n, int m, int c_lib, int c_road, vector<vector<int>> cities)
{
    if (c_lib < c_road)
    {
        return c_lib * n;
    }

    if (m == 0) { return n * c_lib; }
        
    // core logic to create adjanceny list
    vector<vector<int>> adj(n + 1);

    //create adjanceny list
    for (int i = 0; i < cities.size(); ++i)
    {
        adj[cities[i][0]].push_back(cities[i][1]);
        adj[cities[i][1]].push_back(cities[i][0]);
    }

    vector<int> comps;

    vector<bool> visited(n + 1, false);
    int vis = 0;
    for (int i = 1; i < n+1; ++i)
    {
        if (adj[i].size() > 0 && !visited[i])
        {
            vis = dfs(i, adj, visited);
        }
        //// only 1 disconnected city and push only 1 component
        //else if (adj[i].size() == 0) {
        //    comps.push_back(1);
        //}
    }

    long long int ans = 0;
    ans = (((vis)*c_road) + ((n - vis) * c_lib));
    // business logic

    //// iterate to all the components
    //for (int i = 0; i < comps.size(); ++i)
    //{
    //    // is it min cost to build roads or libraries
    //    // compp n - 1
    //    ans += min((comps[i] - 1) * c_road + c_lib, comps[i] * c_lib);
    //}
    return ans;
}


int main()
{
    int n = 6;
    int m = 6;
    int c_lib = 2, c_road = 5;
    /*
    
            {3, 3, 2, 1},
    {1, 2},
    {3, 1},
    {2, 3},
    */
    vector<vector<int>> cities = {

    {6, 6, 2, 5},
    {1, 3},
    {3, 4},
    {2, 4},
    {1, 2},
    {2, 3},
    {5, 6 }
};

	std::cout << roadsAndLibraries(n, m, c_lib, c_road, cities) << std::endl;

	return 0;
}


