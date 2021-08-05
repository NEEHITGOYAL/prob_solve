#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    int index;
    vector<int> result = {};
    index = big.find(small);
    while(index != -1)
    {
        result.push_back(index);
        index =  big.find(small,index+1);
    }
    return result;
}

int main()
{
     string big = "The only course you need to master The problem solving using Data Structures & Algorithms in C++";
     string small = "The";
     vector<int> result = stringSearch(big,small);
     for(int x:result)
        cout<<x<<" ";
        cout<<endl;

}