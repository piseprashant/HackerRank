
int maxMin(int k, vector<int> arr) {
    
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int unfairness = 0;
    int min = 999999999;
    for (int i=0; i <=n-k; i++)
    {
        int maxPtr = i + k -1;
        unfairness = arr[maxPtr] - arr[i];
        
        if (min > unfairness)
        {
            min = unfairness;
        }
    }
    return min;
}

