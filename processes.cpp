#include <sys/types.h>   // for fork, wait
#include <sys/wait.h>    // for wait
#include <unistd.h>      // for fork, pipe, dup, close
#include <stdio.h>       // for NULL, perror
#include <stdlib.h>      // for exit

#include <iostream>      // for cout

using namespace std;

int main( int argc, char** argv ) {
    int fds[2][2];
    int pid;
    if ( argc != 2 ) {
        cerr << "Usage: processes command" << endl;
        exit( -1 );
    }
    if ( ( pid = fork( ) ) < 0 ) {                      // fork a child
        perror( "fork error" );
    }
    else if ( pid == 0 ) {                              // I'm a child 
        int pid2;
        if(pipe(fds[0])<0{                              // create a pipe using fds[0]
            perror("pipe error");
        }
        dup2(fds[0][0],read);                        //reads from fds[0]
        close(fds[0][1]);
        if((pid2=fork())<0){                            // fork a grand-child
          perror("Fork error on grand-child");
        }
        else if (pid == 0){                             // if I'm a grand-child
                                                        //I'm a grand-child    
            if(pipe(fds[1])<0){                         // create a pipe using fds[1]
                perror("pipe2 error");
            }
            dup2(fds[1][0],read);
            close(fds[1][1]);
            close(fds[0][0]);
            dup2(fds[0][1],write);
            int pid3;
            if((pid3 = fork())<0){                        // fork a great-grand-child
                perror("Fork error on great-grand-child");
            }
            else if (pid == 0){                         // if I'm a great-grand-child  
                dup2(fds[1][1],write);
                close(fds[1][0]);
                close(fds[0][1];
                execlp("ps","ps","-A",NULL);                        // execute "ps"
            }
            else                                            // else if I'm a grand-child
                execlp("grep","grep",argv[1],NULL);                     // execute "grep"
            }
        else {
                                                        // else if I'm a child

            execlp("wc","wc","-l",NULL);                              // execute "wc"
        }
    } 
    else {                                              // I'm a parent
        wait( NULL );
        cout << "commands completed" << endl;
    }
}
