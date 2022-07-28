#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h> 

using namespace std; 

int main()
{
    int T;
    scanf("%d", &T);
    for( int i = 0; i<T; i++)
    {
        int N;
        int K;
        int P;
        scanf("%d %d %d", &N, &K, &P);
        int** beauty_values_sum = (int**) malloc(sizeof(int*)*N);
        int** dp = (int**) malloc(sizeof(int*)*N);
        //int* plates_chosen = (int*) malloc(sizeof(int) * N);
        //int plates_chosen_total = N*K;
        for( int j = 0; j<N; j++)
        {
            beauty_values_sum[j] = (int*) malloc(sizeof(int) * K);
            for(int l = 0; l < K; l++)
            {
                int temp;
                scanf("%d", &temp);
                if(l==0)
                    beauty_values_sum[j][l] = temp;
                else
                    beauty_values_sum[j][l] = temp + beauty_values_sum[j][l-1];
            }

        }

        for( int j = 0; j<N; j++)
        {
            dp[j] = (int*) malloc(sizeof(int) * P);
            for( int l = 0; j<P; l++)
            {
                dp[j][l] = 0;
                for( int m = 0; j<min(l,K); m++)
                {
                   dp[j][l] = max(dp[j][l], beauty_values_sum[j][m]+dp[j-1][l-m]);
                }
                printf("%d\n", dp[j][l]);
            }
        }


        /*while(plates_chosen_total > P)
        {
            int stack_minimizer = 0;
            int min_beauty = 101;
            for(int j = 0; j<N; j++)
            {
                if(plates_chosen[j] > 0 && beauty_values[j][plates_chosen[j]-1] < min_beauty)
                {
                    min_beauty = beauty_values[j][plates_chosen[j]-1];
                    stack_minimizer = j;
                }
            }
            plates_chosen[stack_minimizer]--;
            plates_chosen_total--;
        }
        int beauty_total = 0;
        for(int j = 0; j<N; j++)
        {
            for(int l = 0; l < plates_chosen[j]; l++)
            {
                beauty_total += beauty_values[j][l];
            }
            
        }*/
        printf("Case #%d: %d\n",i+1, dp[N-1][P-1]);

        
    }
}