//Ass_2_priority

#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int,int>> processes;
    unordered_map<int,int> buf,temp;
    
    cout<<"Number of processes you want to enter:\t";
    int n; cin>>n;

    cout<<"\nEnter data of processes"<<endl;
    int i=0;
    while(i<n){
        int a,b,c;
        cout<<"\nPriority of process "<<i+1<<"     :";cin>>c; 
        cout<<"Arrival time of process "<<i+1<<" :";cin>>a;
        cout<<"Burst time of process "<<i+1<<"   :";cin>>b;
        processes.push_back(make_pair(a,b));
        buf[a]=c;
        i++;
    }

    sort(processes.begin(),processes.end());
    for(int i=0;i<n;i++){
        temp[processes[i].first]=i;
    }
    // vector<pair<int,int>> buf=processes;
    vector<int> wt(n,0),ct(n,0),tat(n,0);
    vector<bool> bl(n,0);
    int ttat=0;
    // cout<<"index"<<endl;
    
    i=0;
    int euww=0;
    int index=0;
    priority_queue<pair<int,int>> pq;
                                                    //      procceses[AT,BT]
                                                    //      buf[AT]=Priority
    while(1){
        if(i>=processes[index].first){
            wt[index]=i-processes[index].first;

            int ind=i+1;
            i+=processes[index].second;
            while(ind<=i){
                if(ind<=i && ind<n && processes[ind].first<=i){
                    pq.push({-buf[processes[ind].first],processes[ind].first});
                }
                ind++;
            }
            ct[index]=i;
            if(!pq.empty()){index=pq.top().second;pq.pop();}
            
            euww++;
            i--;
        }
        if(euww==n)break;
        i++;
    }

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-processes[i].first;
        ttat+=tat[i];
    }

    cout<<"\nprocesse | "<<"Arrival time | "<<"Burst time | "<<"Waiting time | "<<"Turn around time | "<<"Completion time\n";
    
    for(int i=0;i<n;i++){
        cout<<"  "<<i+1<<"\t\t"<<processes[i].first<<"\t\t"<<processes[i].second<<"         \t"<<wt[i]<<"         \t"<<tat[i]<<"         \t"<<ct[i]<<endl;
    }

    return 0;
}
