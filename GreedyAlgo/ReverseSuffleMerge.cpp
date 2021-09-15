
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


string reverseShuffleMerge(string s)
{
    int n = s.length();

    //start from right to left 
    vector<char> sarr(s.rbegin(), s.rend());

    int alpha_size = 26;

    vector<int> unused(alpha_size, 0);

    // fill array mapping char frequency
    for (int i = 0; i < n; i++) {
        unused[sarr[i] - 'a']++;
    }

    vector<int> did_use(alpha_size, 0);

    vector<int> can_use(unused.begin(), unused.end());

    // result string
    vector<char> A;

    // 0(n) loop
    for (int i = 0; i < n; i++) {
        // to add or not 
        if (did_use[sarr[i] - 'a'] < unused[sarr[i] - 'a'] / 2)
        {
            //check bigger ele -- we re
                //pop 

            //while (j > 0 && ch < res[j - 1] && used[res[j - 1] - 'a'] - 1 + unused[res[j - 1] - 'a'] >= required[res[j - 1] - 'a'])
            while (A.size() > 0 && sarr[i] < A.back() 
                && did_use[A.back() - 'a'] + can_use[A.back() - 'a'] - 1 
                >= unused[A.back() - 'a'] / 2) 
            {
                did_use[A.back() - 'a']--;
                A.pop_back();
            }
            // push element
            A.push_back(sarr[i]);
            did_use[sarr[i] - 'a']++;
            can_use[sarr[i] - 'a']--;
        }
        else
        {
            // rejecting / discarding the perticulr char
            can_use[sarr[i] - 'a']--;
        }
    }
    return string(A.begin(), A.end());
}


int main()
{
    string str = "abcdefgabcdefg";

	std::cout << reverseShuffleMerge (str) << std::endl;

	return 0;
}


