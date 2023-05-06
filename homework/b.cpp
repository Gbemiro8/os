#include<iostream>
#include<thread>
#include<unistd.h>
#include <fcntl.h>
#include <string>

int main (int argc, char *argv[]) {
    char *path = "afile.txt";
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | O_APPEND);
    int child_pid = fork();
    assert(fd != -1);
    assert(child_pid >= 0);

    if (child_pid == 0) {
        // child path
        char *str = "from child";
        int written = write(fd, str, strlen(str));
        std::cout << "child " << written << std::endl;
        assert(written == strlen(str));
    }
    else {
        // parent path
        // char *str = strcat("from parent" + (char*) getpid());
        // int rc = wait(NULL);
        char *str = "from parent";
        int written = write(fd, str, strlen(str));
        std::cout << "parent " << written << std::endl;
        assert(written == strlen(str));
    }
    fsync(fd);
    close(fd);
    return 0;
}
