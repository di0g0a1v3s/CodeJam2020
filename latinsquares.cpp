#include<bits/stdc++.h> 
#include <stdlib.h>
#include <stdio.h>

using namespace std; 


// C++ program to Check if a given array contains duplicate 
//  elements within k distance from each other 
bool checkDuplicates(int arr[], int N) 
{ 
    // Creates an empty hashset 
    unordered_set<int> myset; 
  
    // Traverse the input array 
    for (int i = 0; i < N; i++) 
    { 
        // If already present n hash, then we found 
        // a duplicate within k distance 
        if (myset.find(arr[i]) != myset.end()) 
            return true; 
  
        // Add this item to hashset 
        myset.insert(arr[i]); 
  
    } 
    return false; 
} 

/*bool checkDuplicates(int arr[], int N) 
{
    for(int i= 0; i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(arr[i]==arr[j])
                return true;
        }
    }
    return false;
}*/

int trace(int** matrix, int N)
{
    int trace = 0;
    for(int i = 0; i<N; i++)
    {
        trace += matrix[i][i];
    }
    return trace;
}

int repeated_rows(int** matrix, int N)
{
    int repeated = 0;
    for(int i = 0; i<N; i++)
    {
        if(checkDuplicates(matrix[i],N) == true)
            repeated++;
    }
    return repeated;

}


  


void free_matrix(int** matrix, int N)
{
    for(int i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}


int main()
{
    //FILE* fp = fopen("latinsquares.txt", "r");
    int T;
    //fscanf(fp, "%d", &T);
    scanf("%d", &T);
    for( int i = 0; i<T; i++)
    {
        int N;
        //fscanf(fp, "%d", &N);
        scanf("%d", &N);
        int** matrix = (int**)malloc(sizeof(int*)*N);
        int** matrix_T = (int**)malloc(sizeof(int*)*N);
        for(int j=0;j<N;j++)
        {
            matrix[j] = (int*)malloc(sizeof(int)*N);
            matrix_T[j] = (int*)malloc(sizeof(int)*N);
            
        }
        for(int j=0;j<N;j++)
        {
            for(int l = 0; l < N; l++)
            {
                //fscanf(fp, "%d", &matrix[j][l]);
                scanf("%d", &matrix[j][l]);
                matrix_T[l][j] = matrix[j][l];
            }
        }
        printf("Case #%d: %d %d %d\n",i+1, trace(matrix, N), repeated_rows(matrix, N), repeated_rows(matrix_T, N));
        free_matrix(matrix, N);
        free_matrix(matrix_T, N);
    }
    //fclose(fp);

}