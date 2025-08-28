#include<iostream>
using namespace std;

int main(){

    cout<<"enter the size of the square matrix : ";
    int n;
    cin>>n;

    int diag_mat[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"enter the element for "<<i+1<<" row diagonal : ";
        cin>>diag_mat[i];
    }
    
    cout<<"the array for diagonal element matrix created is :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<diag_mat[i]<<endl;
    }
    


    int mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                mat[i][j]=diag_mat[i];
            }
            else{
                mat[i][j]=0;
            }
        }
        
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    

}