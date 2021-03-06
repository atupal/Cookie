#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N,C;
int v1[3],v2[3];
int cmp(const void *a,const void *b)
{
    if(*(string*)a>*(string*)b)
        return 1;
    else
        return 0;
}

int main()
{
    string result[8];
    int temp,i,i1(0),i2(0),j,id(0);
    string s[8]={
      "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
      "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010",
      "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101",
      "0110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110",
      "1001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001",
      "1100011100011100011100011100011100011100011100011100011100011100011100011100011100011100011100011101",
      "0011100011100011100011100011100011100011100011100011100011100011100011100011100011100011100011100011",
      "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
    };
    cin>>N>>C;
    cin>>temp;
    while(temp!=-1)
    {
        v1[i1++]=temp-1;
        cin>>temp;
    }
    cin>>temp;
    while(temp!=-1)
    {
        v2[i2++]=temp-1;
        cin>>temp;
    }
    if(C==0)
    {
        for(i=0;i<N;i++)
            cout<<s[7][i];
        cout<<endl;
    }
    else if(C>=1)
    {
        for(i=0;i<8;i++)
        {
            if(i==3)
            {
                if(C==2) continue;
            }
            if(i==4 || i==5 || i==6 || i==7)
            {
                if(C<2) continue;
            }
            for(j=0;j<i1;j++)
            {
                temp=v1[j];
                if(s[i][temp]!='1') break;
            }
            if(j==i1)
            {
                for(j=0;j<i2;j++)
                {
                    temp=v2[j];
                    if(s[i][temp]!='0') break;
                }
                if(j==i2)
                {
                    result[id]=s[i];
                    id++;
                }
            }
        }
        qsort(result,id,sizeof(string),cmp);
        for(i=0;i<id;i++)
        {
            for(j=0;j<N;j++)
                cout<<result[i][j];
            cout<<endl;
        }
    }
    return 0;
}
