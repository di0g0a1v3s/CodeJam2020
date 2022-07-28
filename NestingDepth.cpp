#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std; 

int main()
{
    //FILE* fp = fopen("NestingDepth.txt", "r");
    int T;
    char buffer[100] = {0};
    //fscanf(fp, "%d", &T);
    scanf("%d", &T);
    for( int i = 0; i<T; i++)
    {
        //fscanf(fp, "%s", &buffer);
        scanf("%s", &buffer);
        int current_depth = 0;
        string st(buffer);
        int j = 0;
        while(j < st.length())
        {
            while(current_depth < ((int)st.at(j) - '0'))
            {
                st.insert(j, "(");
                j++;
                current_depth++;
            }
            while(current_depth > ((int)st.at(j) - '0'))
            {
                st.insert(j, ")");
                j++;
                current_depth--;
            }
            j++;
        }
        while(current_depth > 0)
        {
            st.append(")");
            current_depth--;
        }
        printf("Case #%d: %s\n",i+1, st.c_str());
        

    }
    //fclose(fp);
    
}