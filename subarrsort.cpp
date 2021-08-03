#include<bits/stdc++.h>
using namespace std;
bool wrong(vector<int> arr,int index)
{
    int x = arr[index];
    if(index==0)
        return x>arr[1];
    if(index == arr.size() - 1)
        return x<arr[index-1];
    return x>arr[index +1] or x<arr[index -1];
}
pair<int,int> subarraysort(vector<int> arr)
{
    int largest,smallest,temp;
    smallest = INT_MAX;
    largest = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {    
        if(wrong(arr,i))
        {
            smallest = min(smallest,arr[i]);
            largest = max(largest,arr[i]);
        }
    }
    //find index where smallest and largest to be fit
    if(smallest == INT_MAX)
        return make_pair(-1,-1);
    int left=0;
    while(smallest >= arr[left]) 
        left++;
    int right = arr.size() -1;
    while (largest<= arr[right])
        right--;
    return {left,right};
}
int main()
{
    vector<int> inp = {1,2,3,4,5,8,6,7,9,10,11};
    auto p = subarraysort(inp);
    cout << p.first<<" and "<<p.second<<endl;
    return 0;
}