#include<bits/stdc++.h>
using namespace std;
int trappedwater(vector<int> heights)
{
    int water,temp;
    int curr_max=water=0;
    vector<int> left(heights.size());
    vector<int> right(heights.size());
    //compute left array
    for(int i=0;i<heights.size();i++)
    {
        if(heights[i]>curr_max)
            curr_max = heights[i];
        left[i] = curr_max;
    }
    // for(auto x:left)
    //     cout<< x << " ";
    //     cout<<endl;
    curr_max =0;
    //compute right array
    for(int i=heights.size()-1;i>=0;i--)
    {
        if(heights[i]>curr_max)
            curr_max = heights[i];
        right[i] = curr_max;
    }
    // for(auto x:right)
    //     cout<< x << " ";
    //     cout<<endl;
    for(int i=0;i<heights.size();i++)
    {
        temp = min(left[i],right[i]) - heights[i];
        if(temp>=0)
            water += temp;
    }
    return water;
}
int main()
{
    vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedwater(water)<<endl;
    return 0;
}