#include "stack.h"

int main() {
    Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    int top = stack.top();
    std::cout << "Top element: " << top << std::endl;
    
    int popped = stack.pop();
    std::cout << "Popped element: " << popped << std::endl;


    top = stack.top();
    std::cout << "Top element: " << top << std::endl;
    
    popped = stack.pop();
    std::cout << "Popped element: " << popped << std::endl;
    
    return 0;
}
