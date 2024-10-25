#include <iostream>
using std::cout;

template<typename T>
class linkedList {
    struct Node {
        T value;
        Node* next;
    };
    public: 
        Node* head = nullptr;
        Node* tail = head;
   
    
    int length = 0;
    public:

        void display() {
            while (head != nullptr) {
                cout << head->value << "\n";
                
                head = head->next;
            }
        }
        void insert(int index, T value) {
            int counter = 0;
            Node* newNode = new Node;
            Node* current = head;
            
            // insert at beginning
            if (index == 0) {
                newNode->value = value;
                newNode->next = head;
                head = newNode;
            }
            // insert at end
            if (index == (-1)) {
                Node* current = new Node;
                current->value = value;
                current->next = nullptr;
                if (length == 0) {
                    head = current;
                    tail = head;
                }

                tail->next = current;
                tail = tail->next;
                length++;
            }

            
        }
        // ! Create method to get each element from linked list.
        

       

        
};



void populateList() {
    linkedList<int> numbers;

    for (int i = 1; i <= 10; i++)
    {
        numbers.insert(-1, i);
        
    }
    numbers.display();
}




