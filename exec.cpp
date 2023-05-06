#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

int main() {
    int child_pid = fork();
    if (child_pid < 0) {
        std::cout << "something went wrong creating the child process";
        exit(1);
    }
    else if (child_pid == 0) {
        // std::cout << "this is the child path";
        char *args[3];
        args[0] = strdup("wc");
        args[1] = strdup("runnable.py");
        args[2] = NULL;
        execvp(args[0], args);
        std::cout << "pid of child is" << getpid() << std::endl; // this shouldn't print out
    }
    else {
        // wait on the child process to finish and return result
        int rc_wait = wait(NULL);
        std::cout << rc_wait << std::endl;
    }
    std::cout << (int) getpid() << " would this be printed twice" << std::endl; // this pid is the parent pid
}
