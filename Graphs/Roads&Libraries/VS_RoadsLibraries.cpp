
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

int dfs(vector<vector<int>>& adjList, int src, vector<bool>& visited) {
    visited[src] = true;
   
    int ans = 1; // size of the component with current src/node as source.

    /*
    //   1 + 1 + 1 = 3
    //    O ANS = 1
        /   \
      1/     \1
      0       0
    */
    //cout << "ans=" << ans << endl;
    for (unsigned int i = 0; i < adjList[src].size(); ++i)
    {
        if (!visited[adjList[src][i]])
        {
            ans += dfs(adjList, adjList[src][i], visited);
            //cout << "adjList[src][i]="  << adjList[src][i] << "  ans=" << ans << endl;
        }
        else
        {
            //cout << "visited adjList[src][i]=" << adjList[src][i] << endl;
        }
    }
   // cout  << "ans-" << ans << endl;
    return ans;   // size of component
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    // core logic to create adjanceny list
    /*
    O <--> O
    */
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < cities.size(); ++i)
    {
        adjList[cities[i][0]].push_back(cities[i][1]);
        adjList[cities[i][1]].push_back(cities[i][0]);
     //   cout << "cities[i][1]= " << cities[i][1] << "  cities[i][0] = " << cities[i][0] << endl;
    }

    vector<int> comps;

    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i)
    {
        if (adjList[i].size() > 0 && !visited[i])
        {
            comps.push_back(dfs(adjList, i, visited));
        }
        // only 1 disconnected city and push only 1 component
        else if (adjList[i].size() == 0) {
            comps.push_back(1);
        }
    }

    long long int ans = 0;

    // business logic

    // iterate to all the components
    for (int i = 0; i < comps.size(); ++i)
    {
        // is it min cost to build roads or libraries
        // compp n - 1
       // cout <<  "ans = " << ans <<  "(comps[i] - 1) * c_road + c_lib = " << (comps[i] - 1) * c_road + c_lib << " comps[i] * c_lib= " << comps[i] * c_lib << endl;
        ans += min((comps[i] - 1) * c_road + c_lib, comps[i] * c_lib);
    }
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

	std::cout << roadsAndLibraries(n, c_lib, c_road, cities) << std::endl;

	return 0;
}


