// https://www.youtube.com/watch?v=h6_lIwZYHQw
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


long candies( int n, vector<int> arr) {

    vector<int> candies(n,0);
    

    candies[0] = 1;
    for (int i = 1; i < arr.size(); i++)
	// iterate from left to right and check neighbours
        if (arr[i - 1] < arr[i])
            candies[i] = candies[i - 1] + 1;
        else
            candies[i] = 1;


    long sumCandies = candies[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--)
    {
	// iterate from right to left and check neighbours and also take max values in result array
        if (arr[i] > arr[i + 1])
            candies[i] = max(candies[i + 1] + 1, candies[i]);
	// do calculate max candies required
        sumCandies += candies[i];
    }

    return sumCandies;
}



int main()
{
    vector<int> arr = { 8, 2, 4, 3, 5, 2, 6, 4, 5 };

	std::cout << candies(arr.size(), arr) << std::endl;

	return 0;
}


