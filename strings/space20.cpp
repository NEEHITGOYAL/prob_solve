#include<bits/stdc++.h>
using namespace std;

void replacechar(char* str)
{
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if(str[i]==' ')
            spaces++;
    int idx = strlen(str) + 2*spaces;
    str[idx] = '\0';
    for (int i = strlen(str)-1; i >= 0; i--)
    {
        if (str[i] ==' '){
            str[idx-1] = '0';
            str[idx-2] = '2';
            str[idx-3] = '%';
            idx = idx -3 ;
        }
        else{
            str[idx-1] = str[i];
            idx--;
        }
    }
}
int main()
{
    char inp[10000];
    cin.getline(inp,1000);
    replacechar(inp);
    cout<<inp<<endl;
    return 0;
}