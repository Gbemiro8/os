#include<chrono>
#include<iostream>
#include<thread>

int main(int argc, char *argv[]) {
  // this program causes my os to keep printing the command-line argument even when I terminate with Ctrl+c
  if (argc != 2) {
    std::cout << "this file requires an input to run";
    return 0;
  }
  // using namespace std::chrono_literals;

  char *var = argv[1];
  while (1) {
    // Spin(1); wait for one second
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << var << std::endl;
  }
  return 0;
}
