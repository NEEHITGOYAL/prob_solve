#include<vector>
#include<bits/stdc++.h>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n);
    output[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        output[i] = output[i-1]*arr[i];
    }
    int prod =1;
    for(int i=n-1;i>0;i--)
    {
        output[i] = prod*output[i-1];
        prod=prod*arr[i];
    }
    output[0] = prod;
    
    return output;
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    vector<int> out = productArray(arr);
    for(auto x:out)
    {
        cout<<x<<" ";
    }
}
//[1,2,3,4,5]
//[120,60,40,30,24]

//[1,2,6,24,120]
