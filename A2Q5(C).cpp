#include<iostream>
using namespace std;

int main(){

    cout<<"enter the size of square matrix : ";
    int n;
    cin>>n;

    int t=((n*n)+n)/2; 
    int arr[t];

    for (int i = 0; i < t; i++)
    {
        cout<<"enter the "<<i+1<<" element of the lower traingular matrix : ";
        cin>>arr[i];
    }
    

    cout<<"the element array is : ";
    for (int i = 0; i < t; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    int x = 0;
    int arr_ltm[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<  n; j++)
        {
            if (i>=j)
            {
                arr_ltm[i][j]=arr[x];
                x++;
            }
            else{
                arr_ltm[i][j]=0;
            }
        }
    }
    cout<<"the lower triangular matrix is :"<<endl;
    for (size_t i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr_ltm[i][j]<<" ";
        }
        cout<<endl;
    }
}