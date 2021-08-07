#include<bits/stdc++.h>
using namespace std;

void usestrtok(char* inp)
{
    char *token = strtok(inp," ");
    cout<<endl;
    while(token != NULL)
    {
        cout<<token<<endl;;
        token = strtok(NULL," ");
    }
}

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

    // same using strtok
    char *inp = &input[0];
    usestrtok(inp);
}
