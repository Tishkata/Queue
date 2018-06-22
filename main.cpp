#include "queue.h"

int main()
{
    /** Creating a Queue of int type, in this case we call the default constructor. */
    Queue<int> myQueue;

    /** Adding elements into Queue */
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    /** Print Queue */
    cout << "Queue elements: ";
    myQueue.print();
    cout << endl;

    /** Creating a new Queue with the same values as the one above, in this case we call the copy constructor. */
    Queue<int> copyQueue(myQueue);

    /** print copied Queue */
    cout << "Copied Queue elements: ";
    copyQueue.print();
    cout << endl;

    /** Creating new Queue with assignment operator, almost the same as the copy constructor */
    Queue<int> assignmentQueue = copyQueue;

    /** Print assignment Queue */
    cout << "Assignment Queue elements: ";
    assignmentQueue.print();
    cout << endl;

    /** Front element of Queue */
    cout << "Queue front element: " << assignmentQueue.front() << endl;

    /** Back element of Queue */
    cout << "Queue back element: " << assignmentQueue.back() << endl;

    /** Remove element of Queue, in this case we remove 1 */
    assignmentQueue.dequeue();
    cout << "New Queue elements: ";
    assignmentQueue.print();
    cout << endl;
    return 0;
}
