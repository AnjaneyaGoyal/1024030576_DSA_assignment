#include<iostream>
using namespace std;

int main(){

    cout<<"enter the size of square matrix : ";
    int n;
    cin>>n;
    int t=((n*n)+n)/2;
    int arr[t] , x=0;
    for (int i = 0; i < n; i++)
    {
        for (int  j= 0; j < n; j++)
        {
            if (i<=j)
            {
                cout<<"enter the element for i="<<i<<" and j="<<j<<" : ";
                cin>>arr[x];
                x++;
            }
            else{
                continue;
            }
        }   
    }

    cout<<endl;


    for (int i = 0; i < t; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl<<endl;

    int sym_mat[n][n] , y=0 ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < n ; j++)
        {
            if (i<=j)
            {
                sym_mat[i][j]=sym_mat[j][i]=arr[y];
            y++;
            }
            else{
                continue;
            }
        }
        
    }
    

 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<sym_mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
}