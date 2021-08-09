#include<bits/stdc++.h>
using namespace std;

string breakPalindrome(string palindrome) {
        if (palindrome.length()<=1)
            return "";
        int i=0;    
        while(i<palindrome.length()){
            if(palindrome[i] == 'a' && i != palindrome.length()-1)
                i++;
            else{
                if(palindrome[i] == 'a')
                    palindrome.replace(i,1,"b");
                else {   
                    if(i == palindrome.length()/2 && palindrome[palindrome.length() -1] == 'a'){
                        i++;
                        continue;
                    }    
                    palindrome.replace(i,1,"a");    
                }
                break;
            }     
        }
        return palindrome;
}

int main(){
    string palindrome;
    getline(cin,palindrome);
    cout<<breakPalindrome(palindrome)<<endl;
}