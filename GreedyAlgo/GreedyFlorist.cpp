int getMinimumCost(int k, vector<int> c) {

    int finalCost = 0;
    int n = c.size();
    sort(c.begin(), c.end());    
    int tmp = k, multiplier = 1;
    int i = n - 1; // start from last 
    while (i>=0)
    {
        if (tmp == 0)
        {
            multiplier++;
            tmp = k;
        }
        finalCost += multiplier * c[i];
        cout << "c[n-1]" << c[i] << endl;
        tmp--;
        i--;
    }
    return finalCost;

}

