#include<iostream>
using namespace std;

int main(){


     cout<<"enter the size of the square matrix : ";
    int n;
    cin>>n;

    int s;

    cout<<"enter the 0th diagonal element : ";
    cin>>s;

    int tridiamat[n][3];
    tridiamat[0][0]=0;
    tridiamat[0][1]=s;
    tridiamat[0][2]=0;

  

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"enter the element "<<j<<" diagonal of the "<<i<<" : ";
            cin>>tridiamat[i][j];
        }
        
    }

    cout<<"the elements of the tri diagonal matrix are : "<<endl;
    for (size_t i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<tridiamat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;
    cout<<endl;
    


    int t = 1 , u = 1;
    int tridiag[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                tridiag[i][j]=tridiamat[i][1];
            }
            else if (j-i==1)
            {
                tridiag[i][j]=tridiamat[t][2];
                t++;
            }
            else if (i-j==1)
            {
                tridiag[i][j]=tridiamat[u][0];
                u++;
            }
            else{
                tridiag[i][j]=0;
            }
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < n; j++)
        {
            cout<<tridiag[i][j]<<" ";
        }
        cout<<endl;
    }
    

}