//Ass_2_SJF


#include<bits/stdc++.h>
#include<vector>

using namespace std;
int main(){
    vector<pair<int,int>> processes;
    unordered_map<int,int> buf;
    cout<<"\nNumber of processes you want to enter:\t";
    int n; cin>>n;
    int maxi=0;

    cout<<"\nEnter data of processes"<<endl;
    
    int i=0;
    while(i<n){
        int a,b;
        cout<<"\nEnter Arrival time of process "<<i+1<<": ";cin>>a;
        cout<<"Enter Burst time of process "<<i+1<<":  ";cin>>b;
        maxi=max(maxi,a);
        processes.push_back(make_pair(a,b));
        i++;
    }

    //sorting as per arrival time
    sort(processes.begin(),processes.end());
    for(int i=0;i<processes.size();i++){
        buf[processes[i].first]=i;
    }
    priority_queue<pair<int,int>> pq;
    
    i=0;
    int j=0;
    int curr=0;
    vector<int> wt(n,0),tat(n,0),ct(n,0);
    int twt=0,ttat=0,tct=0;

    while(!pq.empty() || i<=maxi){
        while(processes[j].first<i)j++;
        if(processes[j].first==i){
            pq.emplace(make_pair{-processes[j].second,processes[j].first});
        }
        if(!pq.empty() && curr==0){
            curr=abs(pq.top().first);
            wt[buf[pq.top().second]]=i-pq.top().second;
            wt+=wt[buf[pq.top().second]];
            pq.pop();
        }
        curr--;
        i++;
    }

    for(int i=0;i<n;i++){
        tat[i]=wt[i]+processes[i].second;
        ttat+=tat[i];
        ct[i]=tat[i]+processes[i].first;
        tct+=ct[i];
    }

    cout<<"\nprocesse | "<<"Arrival time | "<<"Burst time | "<<"Waiting time | "<<"Turn around time | "<<"Completion time\n";
    for(int i=0;i<n;i++){
        cout<<"  "<<i+1<<"\t\t"<<processes[i].first<<"\t\t"<<processes[i].second<<"         \t"<<wt[i]<<"         \t"<<tat[i]<<"         \t"<<ct[i]<<endl;
    }
    cout<<"\nAverage waiting time "<<float(twt)/(float)n;
    cout<<"\nAverage turn around time "<<float(ttat)/(float)n<<endl;
    cout<<"Average completion time="<<(float)tct/(float)n<<endl;
    
    return 0;
}
