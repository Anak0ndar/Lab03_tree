#include <iostream>
#include "menu.h"

using namespace std;

/*int multTwice(int a){
    return a*2;
}

bool isEven(int a){
    if(a%2 == 0)
        return true;
    return false;
}*/

template <class T>
void print(const TreeElement<T>* Tree, size_t tabs = 0) {
    if (Tree != nullptr) {
        std::cout << std::string(tabs, '\t') << Tree->data << std::endl;
        print(Tree->rightChild, tabs + 1);
        print(Tree->leftChild, tabs + 1);
    }
}

int main() {
    mainMenu();
    return 0;
}