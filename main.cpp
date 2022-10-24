#include <iostream>
#include "priority_queue_1.h"
#include <string>
#include <sstream>
using namespace std;

int main(){
    priority_queue<int> queue;

    queue = priority_queue<int>();

    cout << queue.empty() <<  " empty" << endl;
    queue.push(5);
    queue.push(8);
    queue.push(3);
    queue.push(4);
    queue.push(12);
    queue.push(27);
    queue.push(1);
    int aux = 0;
    aux = queue.sizeq();

    cout << aux << " size" << endl;

    cout << queue.top() << " top" << endl;

    cout << queue.empty() << " empty" << endl;

    cout << "pop " << queue.get_head() << " head" << endl;
    queue.pop();
    
    cout << "tail " << queue.get_tail() << endl;

    queue.printq();
}
