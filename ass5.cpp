//Ass5
#include<iostream>
using namespace std;
int main()
{cout<<"\n"<<endl;
 int maxR[3] = {10,5,7};
 int alloc[5][3] = {{ 0, 1, 0 },
                    { 2, 0, 0 },
                    { 3, 0, 2 },
                    { 2, 1, 1 },
                    { 0, 0, 2 }};
 int max[5][3]={ { 7, 5, 3 },
                 { 3, 2, 2 },
                 { 9, 0, 2 },
                 { 2, 2, 2 },
                 { 4, 3, 3 }};
 int need[5][3];
 int available[3]={3,3,2};
 for (int i=0;i<5;i++)
 {
    for(int j=0; j<3; j++)
    {
        need[i][j] = max[i][j] - alloc[i][j];
    }
 }
 int vis[5]={-1,-1,-1,-1,-1};
 int seq[5]={-1,-1,-1,-1,-1};
 int index=0;
 ///------------------------------///

 cout<<"process\t"<<"  allocated\t"<<"max"<<endl;
 for (int i=0;i<5;i++)
 {  cout<<"  "<<i<<"\t";
    for(int j=0;j<1;j++)
    {
        cout<<"   "<<alloc[i][0]<<" "<<alloc[i][2]<<" "<<alloc[i][2]<<"    \t"<<max[i][0]<<" "<<max[i][1]<<" "<<max[i][2]<<endl;
    }
 }

 ///-------------------------------///
 for(int i=0;i<5;i++)
 {
    for(int j=0;j<5;j++)
    {
        if(vis[j]==-1 && (need[j][0]<=available[0])&& (need[j][1]<=available[1])&& (need[j][2]<=available[2]) )
        {
            vis[j]=j;
            seq[index++]=j;
            for(int k=0;k<3;k++)available[k]+=alloc[j][k];
            break;
        }
    }
 }
 

 int i=0;
 for(i=0;i<5;i++)
 {
    if(seq[i]==-1)
    { 
        cout<<"Sequence is invalid"<<endl;
        break;
    }
 }
 if (i==5)
 {
    cout<<"\nSequence is :\t";
    for(int i=0;i<5;i++)cout<<"P"<<seq[i]<<" ";
 }
 cout<<"\n"<<endl;
}

