#include<iostream>
#include<pthread.h>
#include<unistd.h>

int main(int argc, char **argv) {
    int child_pid = fork();
    assert(child_pid >= 0);
    int x = 0;

    if (child_pid == 0) {
        // the child process path
        x = 2;
        std::cout << "value of x in child process is " << x << std::endl;
    }
    else {
        // the parent process path
        x = 1;
        std::cout << "value of x in parent process is " << x << std::endl;
    }
    std::cout << (int) getpid() << " would this be printed twice" << std::endl;
}
