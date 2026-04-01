#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string.h>
#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#define mod 1e9+7
using namespace std;
char s[101][102],s1[30];
int main()
{
    int n,i,j,k=0,a[27][27]={0},l1,l2,p,b[27]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf(" %s",s[i]);
    for(i=0;i<26;i++) s1[i]='.';
    s1[i]='\0';
    for(i=0;i<n-1;i++)
    {
        l1=strlen(s[i]);
        l2=strlen(s[i+1]);
        for(j=0;j<l1&&j<l2;j++)
        {
            if(s[i][j]==s[i+1][j]) continue;
            else
            {
                if(a[s[i][j]-'a'][s[i+1][j]-'a']==0)
                {
                    a[s[i][j]-'a'][s[i+1][j]-'a']=-1;
                    a[s[i+1][j]-'a'][s[i][j]-'a']=1;
                }
                else if(a[s[i][j]-'a'][s[i+1][j]-'a']==1)
                {
                    printf("Impossible\n");
                    return 0;
                }
            }
            break;
        }
        if(j==l1||j==l2)
        {
            if(l1>l2)
            {
                printf("Impossible\n");
                return 0;
            }
        }
    }
    while(1)
    {
        for(i=0;i<26;i++)
        {
            if(b[i]==1) continue;
            for(j=0;j<26;j++)
                if(a[i][j]>0) break;
            if(j<26) continue;
            for(j=0;j<26;j++)
                if(a[i][j]<0) a[j][i]=0;
            s1[k]=i+'a';
            b[i]=1;
            break;
        }
        if(s1[k]=='.')
        {
            printf("Impossible\n");
            return 0;
        }
        else k++;
        if(k==26) break;
    }
    printf("%s\n",s1);
    return 0;
}
