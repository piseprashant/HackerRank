// Rules
// 1 - Having same rank - Rank of new AP (absolute parent) increase by value 1
// 2 - Having diff rank - Rank doesn't change.
// 3. Height shouldn't be increased while Union operation
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


/*
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */

int luckBalance(int k, vector<vector<int>> contests) {
	int LuckBalance = 0;
	vector<int> importantContestLuck;
	int count = 0;
	for (int iterContest = 0; iterContest < contests.size(); iterContest++)
	{
		if (contests[iterContest][1] == 1)
		{
			count++;
			// store imporant context in a vector and sort them later in ascending order as per luck
			importantContestLuck.push_back(contests[iterContest][0]);
		}
		LuckBalance += contests[iterContest][0];
	}

	// now sort the importantContestLuck in ascending order as per luck
	std::sort(importantContestLuck.begin(), importantContestLuck.end());

	int sub = 0;
	if (count)
	{
		for (int addRemaingLuck = 0; addRemaingLuck < count - k; addRemaingLuck++)
		{
			sub += importantContestLuck[addRemaingLuck];
		}
	}
	
	return LuckBalance - 2*sub;
}


int main()
{
	vector<vector<int>> contests = { {5, 1}, {2, 1}, {1, 1}, {8, 1}, {10, 0}, {5, 0} };

	std::cout << luckBalance(3, contests) << std::endl;
	
	return 0;
}


