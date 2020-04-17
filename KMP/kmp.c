#include<stdio.h>

#include<string.h>
#include<stdlib.h>
#include<malloc.h>
void prefix_table(char pattern[],int *prefix,int n)
{
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else {
            if(len > 0)
            {
                len = prefix[len - 1];
            }
            else{ 
                prefix[i] = len;
                i++;
            } 

        }
    }
}
void move_prefix_table(int prefix[],int n )
{
    int i = 0;
    for(i = n - 1;i > 0;i--)
    {
        prefix[i]= prefix[i - 1];
    }
    prefix[0] = -1;
}
void kmp_search(char text[],char pattern[])
{
    int n = strlen(pattern);
    int *prefix = (int *)malloc(sizeof(int) * n);
    int m = strlen(text);
    int i = 0;
    int j = 0;
    prefix_table(pattern,prefix,n);
    move_prefix_table(prefix,n);
    while(i < m)
    {
        if(j == n - 1 && text[i] == pattern[j])
        {
            printf("%d\n", i - j);
            j = prefix[j];
        }

        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else{
            j = prefix[j];
            if(j == -1)
            {
                j++;
                i++;
            }
        }
    }

}
int main()
{

    char text[] = "ABABABBABCDF";
    char pattern[] = "BCD";
    kmp_search(text,pattern);

    return 0;
}

