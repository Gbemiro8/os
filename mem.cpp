#include<iostream>
#include<thread>

void print(int *var) {
    std::cout << "address " << var << ' ' << "value " << *var << std::endl;
}

int main(int argc, char *argv[]) {
    int *var = new int();
    assert(var != nullptr);

    *var = 5;
    print(var);
    *var = *var * 2;
    print(var);
    delete var;
    return 0;
}
