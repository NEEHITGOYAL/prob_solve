#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
    string comp_string = "";
    for(int i=0;i<str.length();){
        char c = str[i];
        int num =1;
        int j =i+1;
        for(j=i+1;j<str.length();j++){
            if(str[j] == c){
                num++;
            }
            else
                break;    
        }
        i=j;
        comp_string = comp_string + c + to_string(num);
        if(comp_string.length()>=str.length())
            return str;
    }
    return comp_string;
}

int main(){
    string str;
    getline(cin,str);
    cout<<compressString(str)<<endl;
}