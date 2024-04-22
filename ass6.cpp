//ASS_6
#include <bits/stdc++.h>

using namespace std;
int main() {
    // Write C++ code here
    vector<int> memory_part={100, 500, 200, 300, 600};
    vector<int> processes = {212, 417, 112, 426};
    
    // cout<<"Number of memory partrtions:\t";
    // int n; cin>>n;
    // int maxi=0;

    // cout<<"\nEnter size of partiotions"<<endl;
    // int i=0;
    // while(i<n){
    //     int a;
    //     cout<<"1)\t";
    //     cin>>a;
    //     memory_part.push_back(a);
    //     i++;
    // }
    
    // cout<<"\nEnter number of processes"<<endl;
    // cin>>n;
    // cout<<"Enter size of processes\t"<<endl;
    // i=0;
    // while(i<n){
    //     int a;
    //     cout<<"1)\t";
    //     cin>>a;
    //     processes.push_back(a);
    //     i++;
    // }
    // vector<bool> buf(memory_part.size(),false);
    cout<<"\nmemory parts:"<<endl;
    for(auto itr:memory_part){
        cout<<itr<<" ";
    }

    cout<<"\nprocesses:"<<endl;
    for(auto itr:processes){
        cout<<itr<<" ";
    }
    
    cout<<"\n\nFirst fit:\n";
    vector<int> sol(processes.size(),-1);
    for(int i=0;i<processes.size();i++){
        for(int j=0;j<memory_part.size();j++){
            if(memory_part[j]>=processes[i]){
                memory_part[j]=memory_part[j]-processes[i];
                sol[i]=j+1;
                break;
            }
        }
    }
    
    for(int i=0;i<processes.size();i++){
        if(sol[i]!=-1)
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<sol[i]<<endl;
        else
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<"Not allocated"<<endl;
    }cout<<endl;
    
    
    
    memory_part={100, 500, 200, 300, 600};
    sol.clear();
    sol.resize(processes.size(),-1);
    int z=-1;
    int temp=0;
    for(int i=0;i<processes.size();i++){
        for(int j=0;j<memory_part.size();j++){
            if(memory_part[j]>=processes[i] && memory_part[j]>temp){
                temp=memory_part[j];
                z=j+1;
            }
        }
        memory_part[z-1]=memory_part[z-1]-processes[i];
        sol[i]=z;
        z=-1;
        temp=0;
    }
    
    cout<<"Worst fit:\n";
    for(int i=0;i<processes.size();i++){
        if(sol[i]>-1)
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<sol[i]<<endl;
        else
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<"Not allocated"<<endl;
    }cout<<endl;

    
    memory_part={100, 500, 200, 300, 600};
    sol.clear();
    sol.resize(processes.size(),-1);
    z=-1;
    temp=INT_MAX;
    for(int i=0;i<processes.size();i++){
        for(int j=0;j<memory_part.size();j++){
            if(memory_part[j]>=processes[i] && memory_part[j]<=temp){
                temp=memory_part[j];
                z=j+1;
            }
        }
        memory_part[z-1]=memory_part[z-1]-processes[i];
        sol[i]=z;
        z=-1;
        temp=INT_MAX;
    }
    
    cout<<"Best fit:\n";
    for(int i=0;i<processes.size();i++){
        if(sol[i]>-1)
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<sol[i]<<endl;
        else
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<"Not allocated"<<endl;
    }cout<<endl;
    
    // {100, 500, 200, 300, 600}
    // {212, 417, 112, 426}
    memory_part={100, 500, 200, 300, 600};
    sol.clear();
    sol.resize(processes.size(),-1);
    int j=0,n=0;

    for(int i=0;i<processes.size();i++){
        n=0;
        while(n<memory_part.size()){
           if(memory_part[j]>=processes[i]){
                memory_part[j]=memory_part[j]-processes[i];
                sol[i]=j+1;
                j=(j+1)%memory_part.size();
                break;
             }
           j=(j+1)%memory_part.size();
           n++;
        }  
    }
    
    
    cout<<"Next fit:\n";
    for(int i=0;i<processes.size();i++){
        if(sol[i]>-1)
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<sol[i]<<endl;
        else
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<"Not allocated"<<endl;
    }cout<<endl;
    
    return 0;
}
