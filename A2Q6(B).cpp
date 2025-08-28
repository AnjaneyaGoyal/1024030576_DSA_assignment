#include<iostream>
using namespace std;

int main(){

    int r,c;
    cout<<"enter the number of rows of the matrix : ";
    cin>>r;
    cout<<"enter the number of columns of the matrix : ";
    cin>>c;

    int t1;
    cout<<"enter the number of non zero elements in matrix 1 :";
    cin>>t1;
    int mat1[t1][3]; 
    for (int i = 0; i < t1; i++)
    {
        cout<<"enter the row column value : ";
        cin>>mat1[i][0]>>mat1[i][1]>>mat1[i][2];
    }
    
    cout<<endl; 

    int t2;
    cout<<"enter the number of non zero elements in matrix 2 : ";
    cin>>t2;
    int mat2[t2][3]; 
    for (int i = 0; i < t2; i++)
    {
        cout<<"enter the row column value : ";
        cin>>mat2[i][0]>>mat2[i][1]>>mat2[i][2];
    }

    int res_mat[t1+t2][3];
    int i=0,j=0,k=0;

    while (i<t1 && j<t2)
    {
        if (mat1[i][0]<mat2[j][0] ||mat1[i][0]==mat2[j][0] && mat1[i][1]<mat2[j][1])
        {
            res_mat[k][0]=mat1[i][0];
            res_mat[k][1]=mat1[i][1];
            res_mat[k][2]=mat1[i][2];
            i++ , k++;
        }
        else if(mat1[i][0]>mat2[j][0] ||mat1[i][0]==mat2[j][0] && mat1[i][1]>mat2[j][1]){
            res_mat[k][0]=mat2[i][0];
            res_mat[k][1]=mat2[i][1];
            res_mat[k][2]=mat2[i][2];
            j++ , k++;
        }
        else{
            res_mat[k][0]=mat1[i][0];
            res_mat[k][1]=mat1[i][1];
            res_mat[k][2]=mat1[i][2]+mat2[j][2];
            i++ ,j++, k++;
        }
    }

    while (i < t1) {
        res_mat[k][0] = mat1[i][0];
        res_mat[k][1] = mat1[i][1];
        res_mat[k][2] = mat1[i][2];
        i++; k++;
    }
    while (j < t2) {
        res_mat[k][0] = mat2[j][0];
        res_mat[k][1] = mat2[j][1];
        res_mat[k][2] = mat2[j][2];
        j++; k++;
    }
    
    cout << "\nResultant Sparse Matrix in Triplet Form:\n";
    cout << "Row Col Value\n";
    for (int x = 0; x < k; x++) {
        cout << res_mat[x][0] << " " << res_mat[x][1] << " " << res_mat[x][2] << endl;
    }

}