//Ass2_FCFS

#include<bits/stdc++.h>
#include<vector>

using namespace std;
int main(){
    vector<pair<int,int>> processes;
    cout<<"\nNumber of processes you want to enter:\t";
    int n; cin>>n;

    cout<<"\nEnter data of processes"<<endl;
    
    int i=0;
    while(i<n){
        int a,b;
        cout<<"\nEnter Arrival time of process "<<i+1<<":\t";cin>>a;
        cout<<"Enter Burst time of process "<<i+1<<":\t";cin>>b;
        
        processes.push_back(make_pair(a,b));
        i++;
    }
    vector<pair<int,int>> buf;
    sort(processes.begin(),processes.end());

    vector<int> wt(n,0),tat(n,0),ct(n,0);
    int total_wt=0,total_tat=0,total_ct=0;

    for(int i=1;i<n;i++){
        wt[i]= (wt[i-1] + processes[i-1].second) - processes[i].first;
        // cout<<wt[i-1]<<" "<<processes[i-1].second<<" "<<processes[i-1].first<<endl;
        total_wt+=wt[i];
    }

    for(int i=0;i<n;i++){
        tat[i]= wt[i] + processes[i].second;
        total_tat+=tat[i];
        ct[i]=tat[i]+processes[i].first;
        total_ct+=ct[i];
    }

    cout<<"\nprocesse | "<<"Arrival time | "<<"Burst time | "<<"Waiting time | "<<"Turn around time | "<<"Completion time\n";
    for(int i=0;i<n;i++){
        cout<<"  "<<i+1<<"\t\t"<<processes[i].first<<"\t\t"<<processes[i].second<<"         \t"<<wt[i]<<"         \t"<<tat[i]<<"         \t"<<ct[i]<<endl;
    }

    cout<<"\nAverage waiting time="<<(float)total_wt/(float)n<<endl;
    cout<<"Average turn around time="<<(float)total_tat/(float)n<<endl;
    cout<<"Average completion time="<<(float)total_ct/(float)n<<endl;
    cout<<endl;
    return 0;
}
