#include <iostream>
#include <pthread.h>

#define Pthread_create(thread, attr, start_routine, arg) assert(pthread_create(thread, attr, start_routine, arg) == 0);
#define Pthread_join(thread, value_ptr) assert(pthread_join(thread, value_ptr) == 0);


volatile int counter = 0;

void* worker(void *arg) {
    for (int i = 0; i < *(int *)arg; i++) {
        counter++;
    }
    return (void*)&counter;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "this program requires an argument";
        exit(1);
    }
    int loops = atoi(argv[1]);

    pthread_t p1, p2;
    void *ans;
    Pthread_create(&p1, NULL, worker, &loops);
    Pthread_create(&p2, NULL, worker, &loops);
    Pthread_join(p1, &ans);
    Pthread_join(p2, &ans);
    std::cout << *(int*)ans << std::endl;
}
