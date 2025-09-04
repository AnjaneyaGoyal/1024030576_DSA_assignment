#include<iostream>
using namespace std;


int main(){

    char ch;
    cout<<"enter the character : ";
    cin>>ch;
    if ((int)ch>=65 && (int)ch<91)
        {
            ch+=32;
        }
    
    cout<<"the character in lowercase is : ";
    cout<<ch;

}