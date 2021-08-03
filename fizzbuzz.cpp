#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
    int test_3,test_5;
    vector<string> res;
    for(int i=0;i<n;i++)
    {
        test_3 = (i+1) % 3;
        test_5 = (i+1) % 5;
        if(test_3 == 0 || test_5 ==0)
        {
            if(test_3 == 0 && test_5 ==0)
                res.push_back("FizzBuzz");
            else if(test_3 == 0)
                res.push_back("Fizz");
            else
                res.push_back("Buzz");
        }
        else
            res.push_back(to_string(i+1));
    }
    return res;
}

int main()
{
    vector<string> x = fizzbuzz(15);
    for(auto temp:x)
        cout<<temp<<" ";
}