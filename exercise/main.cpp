#include <iostream>
#include <thread>

static unsigned  nt = 10;
void call_from_thread() {
    std::cout << "Hello world " << std::endl;
}

int main() {
    std::thread t[nt];
    for(int i = 0; i < nt; i++) {
       t[i](call_from_thread);
       t[i].join();
    }
    return 0;
}
