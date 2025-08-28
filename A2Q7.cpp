#include<iostream>
using namespace std;

int main(){

    cout<<"enter the size of an array : ";
    int n;
    cin>>n;
    int arr[n];
    int t = 0;

    for (int i = 0; i < n; i++)
    {
       cout<<"enter the "<<i+1<<" element of the array : ";
       cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i<j && arr[i]>arr[j])
            {
                t++;
            }
            else{
                continue;
            }
        }
    }
    cout<<"the total number of inversions in the array are : "<<t;

}