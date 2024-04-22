//ass3_3(child 2 pipes)

#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h>

using namespace std;
int main(){
    pid_t child;
    int fd[2],fd1[2];

    char buf[2][100];

    if(pipe(fd1)<0){
        cerr<<"pipe leaked or fork failed"<<endl;
    }
    if(pipe(fd)<0){
        cerr<<"pipe leaked or fork failed"<<endl;
    }
       child=fork();
    if(child<0){
        cerr<<"pipe leaked or fork failed"<<endl;
    }
    else if(child!=0){
        const char msg[]="Abhishek\0";
        write(fd[1],msg,100);

        wait(NULL);
        
        read(fd1[0],buf[1],100);
        cout<<"Parent recieved: "<<buf[1]<<endl;

    }
    else{
        read(fd[0],buf[0],100);
        cout<<"Child recieved: "<<buf[0]<<endl;

        const char msg2[]="Aniket\0";
        write(fd1[1],msg2,100);
    }

    return 0;
}
