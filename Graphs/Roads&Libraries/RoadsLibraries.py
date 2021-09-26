
# def roadsAndLibraries(n, c_lib, c_road, cities):
# Complete the roadsAndLibraries function below.
def dfs(s,arr,visited):
    visited[s]=True
    cost=0
    for i in arr[s]:
        if(not visited[i]):
            cost+=1
            cost+=dfs(i,arr,visited)
    return cost

def roadsAndLibraries(n,m, c_lib, c_road, cities):
    if(c_lib<c_road):
        return c_lib*n
    if(m==0):
        return n*c_lib
    arr=[[0] for i in range(n+1)]
    visited=[False for i in range(n+1)]
    for i in range(1,n+1):
        arr[i][0]=i
    for i in range(m):
        arr[cities[i][0]].append(cities[i][1])
        arr[cities[i][1]].append(cities[i][0])
    vis=0
    for i in range(1,n+1):
        if(not visited[i]):
            vis+=dfs(i,arr,visited)
    cost=(((vis)*c_road)+((n-vis)*c_lib))
    return cost

