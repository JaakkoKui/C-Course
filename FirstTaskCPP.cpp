#include <iostream>

using namespace std;
int task;

int main(){
    std::cout << "Choose task to run:\n1. String calculator\n2. \n3. \n0. Exit\n";
    std::cin >> task;
    switch (task)
    {
    case 1:
        cout << "Wassup";
        break;
    
    default:
        break;
    }

    return 0;
}