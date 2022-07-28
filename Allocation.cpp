#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h> 

using namespace std; 

int main()
{
    //FILE* fp = fopen("allocation.txt", "r");
    int T;
    //fscanf(fp, "%d", &T);
    scanf("%d", &T);
    for( int i = 0; i<T; i++)
    {
        int N;
        int B;
        //fscanf(fp, "%d %d", &N, &B);
        scanf("%d %d", &N, &B);
        int j = 0;
        int* A = (int*) malloc(sizeof(int) * N);
        for(j=0; j<N;j++)
        {
            //fscanf(fp, "%d", &A[j]);
            scanf("%d", &A[j]);
        }
        sort(A, A+N);
        int accumulator = 0;
        
        for(j=0; j<N;j++)
        {
            accumulator += A[j];
            if(accumulator > B)
                break;
            
        }
        printf("Case #%d: %d\n",i+1, j);
        free(A);

    }
}
