// https://www.youtube.com/watch?v=K4TIlM1c-w4&t=404s
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


string reverseShuffleMerge(string str)
{
    int n = str.size();

    //initializing arrays
    int unused[26] = { 0 };
    int used[26] = { 0 };
    int required[26] = { 0 };
    char res[100000];
    int j = 0;


    //filling array mapping char freq
    for (int i = 0; i < n; i++)
    {
        unused[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        required[i] = unused[i] / 2;
    }

    // last character
    char ch = str[n - 1];
    int ch_position = ch - 'a'; // index present in above arrays
    res[j++] = ch;
    unused[ch_position]--;
    used[ch_position]++;

    //rest of char 
    //add ---- req is smaller than pres
    // ch smaller 
    //ch bigger

    for (int i = n - 2; i >= 0; i--)
    {
        ch = str[i];
        ch_position = ch - 'a';
        // to add or not 
        if (used[ch_position] < required[ch_position])
        {
            //add char
            if (ch > res[j - 1])
            {
                res[j++] = ch;
                unused[ch_position]--;
                used[ch_position]++;
            }
            else {
                //check bigger ele -- we re
                //pop 

                while (j > 0 && ch < res[j - 1] && used[res[j - 1] - 'a'] - 1 + unused[res[j - 1] - 'a'] >= required[res[j - 1] - 'a'])
                {
                    used[res[--j] - 'a']--;
                }
                res[j++] = ch;
                unused[ch_position]--;
                used[ch_position]++;
            }
        }
        else
        {// rejecting / discarding the perticulr char
            unused[ch_position]--;
        }
    }

    string ret;
    for (int i = 0; i < n / 2; i++)
    {
        ret.push_back(res[i]);
    }
    return ret;
}


int main()
{
    string str = "abcdefgabcdefg";

	std::cout << reverseShuffleMerge (str) << std::endl;

	return 0;
}


