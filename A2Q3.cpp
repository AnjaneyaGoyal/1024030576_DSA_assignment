#include<iostream>
#include<string>

using namespace std;

int main(){

    cout<<"enter the size of array you want : ";
    int n ; 
    cin>>n;
    int arr[n];
    for (int i = 0; i < n-1; i++)
    {
        cout<<"enter the element of the array : ";
        cin>>arr[i];
    }
    int s = 0 ;
    int diff = arr[1]-arr[0];
    for (int i = 0; i < n-1; i++)
    {
        int t = arr[i+1]-arr[i];
        if (diff==t)
        {
            continue;
        }
        else{
            int a = arr[i+1]-arr[i+2];
            if (a!=diff)
            {
                s=i+1;
            }
            else{
                s=i;
            }  
            break;  
        }
    }
    cout<<"Missing Element Index : "<<s<<endl;
    for (int i = n-1; i >= s ; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[s]=arr[s-1]+diff;

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

}