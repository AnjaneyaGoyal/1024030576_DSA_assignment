#include<iostream>

using namespace std;



int main(){
    
    char str1[100];
    cout<<"enter the first string : ";
    cin>>str1;

    int u = 0;
    while (str1[u]!='\0')
    {
        u++;
    }
    cout<<u<<endl;
    
    char rev_str1[100];
    for (int i = 0 , j=u-1 ; i < u && j>=0; j--,i++)
    {
        rev_str1[i]=str1[j];
    }
    rev_str1[u]='\0';
    cout<<"the reversed string is : ";
    cout<<rev_str1;
    
}