//Ass1
#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;
int main(){
    pid_t child_pid;
    pid_t this_pid;

    string file;//"destination.txt";
    string pattern;//="copy";
    string line;
    ifstream inputFile;//(file);
    int n;
    
    int status;
    pid_t terminated_child_pid;
    
    int ch;
    while(1)
    {
        cout<<"\nChoose option to execute:-\n";
        cout<<"1.cp command\n";
        cout<<"2.grep command\n";
        cout<<"3.getpid()\n";
        cout<<"4.wait()\n";
        cout<<"5.exit()\n";

        cin>>ch;

        switch(ch)
        {
            case 1: child_pid = fork();
                    // cout<<"ass1 : "<<getpid()<<endl;
                    if(child_pid<0){
                        cerr<<"Fork failed"<<endl;
                        break;
                    }
                    else if(child_pid==0){
                        char *args[]={"cp","source.txt","destination.txt",NULL};

                        execvp("cp",args);
                        perror("execvp");
                        break;
                    }
                    else{
                        wait(nullptr);
                        cout<<"File copied succesfully";
                    }
                    break;

            case 2: cout<<"Enter the file from which you have to find pattern: ";cin>>file;
                    cout<<"\nEnter the pattern: ";cin>>pattern;
                    child_pid = fork();
                    if(child_pid<0){
                        cerr<<"Fork failed"<<endl;
                        break;
                    }
                    else if(child_pid==0){
                        char *args2[]={"grep","-i","-n","copy","source.txt"};
                        execvp("grep",args2);
                        perror("execvp");
                        break;
                    }
                    else{
                        wait(NULL);
                        cout<<"Above is the result^"<<endl;
                    }
                    
                    break;

            case 3: cout<<"PID of this process is "<<getpid()<<endl;
                    break;

            case 4: child_pid = fork();
                    // cout<<"ass1 : "<<getpid()<<endl;
                    if(child_pid<0){
                        cerr<<"Fork failed"<<endl;
                        break;
                    }
                    else if(child_pid==0){
                        cout<<"child process starting: "<<child_pid<<endl;
                        // sleep(3);
                        cout<<"child process exiting: "<<child_pid<<"\n"<<endl;
                        break;
                    }
                    else{
                        cout<<"parent process: "<<getpid()<<endl;
                        
                        wait(nullptr);
                        cout<<"child process terminated"<<endl;
                    }
                    break;

            case 5: cout<<"Quiting\n";
                    exit(EXIT_SUCCESS);
                    //return 0;

        default:cout<<"Invalid input";
        }
    }   
    
    // execv("./ex2",args);
    // cout<<" Back in ass1"<<endl;
    #ifdef _WIN32
    system("pause");
    #endif

    return 0;
}
