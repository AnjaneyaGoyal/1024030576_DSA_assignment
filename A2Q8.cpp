#include<iostream>
using namespace std;

int main(){

    cout<<"enter the size of array : ";
    int n;
    cin>>n;

    int arr[n],dist_arr[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"enter the element "<<i+1<<" of the array : ";
        cin>>arr[i];
    }

    int t =0 ;
    
    for (int i = 0; i < n; i++)
    { 
     bool found = false;
     for (int j = 0; j < t; j ++)
     {
        if (arr[i]==dist_arr[j])
        {
            found=true;
            break;
        }
     }
        if (found==false)
        {
            dist_arr[t]=arr[i];
            t++;
        }
    }
    cout<<endl;
cout<<"the distinct element array is : ";
for (int i = 0; i < t; i++)
{
    cout<<dist_arr[i]<<" ";
}
cout<<"the number of distinct elements in the array : "<<t;

}