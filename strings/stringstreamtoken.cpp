#include<bits/stdc++.h>
using namespace std;

int main(){

    string input,token;
    vector<string> tokens;
    getline(cin,input);
    stringstream ss(input);
    while (getline(ss,token,' '))
        tokens.push_back(token);
    for (int i = 0; i < tokens.size(); i++)
        cout<<tokens[i]<<endl;
    cout<<endl;
}
