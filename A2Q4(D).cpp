#include<iostream>
using namespace std;


int main(){

    char str[100];
    cout<<"enter the string : ";
    cin>>str;

    int u = 0;
    while (str[u]!='\0')
    {
        u++;
    }
    cout<<u<<endl;
    
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u-i-1 ; j++)
        {
            if ((int)str[j]>(int)str[j+1])
            {
                char ch = str[j];
                str[j]=str[j+1];
                str[j+1]=ch;
            }
            
        }
        
    }
    cout<<"the sorted string is :";
    cout<<str;

}