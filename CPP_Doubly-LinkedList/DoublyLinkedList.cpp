// Name: Seakmeng Hor
// Course: cs201 section 1

#include <iostream>
using namespace std;

// Generic template for the Double_node class
template <class T>

// create doubly linked-list class
class Double_node {
   private:
    T data;
    Double_node<T> *next;
    Double_node<T> *prev;

   public:
    // constructor
    Double_node(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    // return data
    T getData() { return this->data; }

    // Return next
    Double_node<T> *getNext() { return this->next; }

    // Return prev
    Double_node<T> *getPrev() { return this->prev; }

    // Set data to the input data
    void setData(T data) { this->data = data; }

    // Set next to the input next
    void setNext(Double_node<T> *next) { this->next = next; }

    // Set prev to the input prev
    void setPrev(Double_node<T> *prev) { this->prev = prev; }

    // Destructor is a member function that is invoked automatically when the
    // object goes out of scope or is explicitly destroyed by a call to delete.
    ~Double_node() {
        this->setPrev(nullptr);
        this->setNext(nullptr);
    }
};

template <class T>
// create functions class
class Double_list {
   private:
    // Node pointer pointing to the first node (or NULL if list is empty)
    Double_node<T> *list_head;
    // Node pointer pointing to the last node (or NULL if list is empty)
    Double_node<T> *list_tail;
    // Number of items(nodes) contain within the list
    int list_size;

   public:
    // Default constuctor
    Double_list() {
        // if the user don't pass list, set the list_head, list_tail, and
        // list_size to NULL, NULL, and 0
        this->list_head = nullptr;
        this->list_tail = nullptr;
        this->list_size = 0;
    }

    // Copy constructor
    //  use & to pass by reference so that the function can modify the list
    Double_list(const Double_list &dl) {
        // if the user pass list, set the list_head, list_tail, and list_size to
        // the list
        this->list_head = dl.list_head;
        this->list_tail = dl.list_tail;
        this->list_size = dl.list_size;
    }

    // Set list_head to the input list_head
    void set_head(Double_node<T> *list_head) { this->list_head = list_head; }

    // Set list_tail to the input list_tail
    void set_tail(Double_node<T> *list_tail) { this->list_tail = list_tail; }

    // Set list_size to the input list_size
    void set_size(int list_size) { this->list_size = list_size; }

    // return size list (optional)
    int return_size() {
        Double_node<T> *temp = this->list_head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->getNext();
        }
        return count;
    }

    // Return list_head
    Double_node<T> *head() const { return this->list_head; }

    // Return list_Tail
    Double_node<T> *tail() const { this->list_tail; }

    // Return list_size if empty return 0
    int size() const { return this->list_size; }

    // print the node's data inside the list from front to back
    void print_list() {
        // create a temp node to store the list_head
        // list_head know head address and head know where is next and so on
        Double_node<T> *temp = this->list_head;
        // if the list is empty, print "List is empty"
        if (temp == nullptr) {
            cout << "List is empty" << endl;
        } else {
            // if the list is not empty, print the data inside the list
            while (temp != nullptr) {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
    }

    // print the node's data inside the list from back to front
    void print_list_reverse() {
        // create a temp node to store the list_prev
        // list_prev know prev address and prev know where is prev and so on
        Double_node<T> *temp = this->list_tail;
        // if the list is empty, print "List is empty"
        if (temp == nullptr) {
            cout << "List is empty" << endl;
        } else {
            // if the list is not empty, print the data inside the list
            while (temp != nullptr) {
                cout << temp->getData() << " ";
                temp = temp->getPrev();
            }
            cout << endl;
        }
    }

    // Return true if list_size equal to 0, else return false
    bool empty() const {
        // if we haven't set_head() list_head will = nullptr by default
        // so if we haven't set_head() it will return false, true otherwise
        return this->list_head == nullptr;
    }

    // Return the number of nodes storing a value equal to the argument
    int count(T obj) const {
        Double_node<T> *temp = this->list_head;
        int count = 0;
        // if empty list return 0
        if (temp == nullptr) {
            return count;
        } else {
            while (temp != nullptr) {
                if (temp->getData() == obj) {
                    count++;
                }
                temp = temp->getNext();
            }
        }
        return count;
    }

    // Return the item stored inside the node the list_head pointer's pointing
    T front() const {
        Double_node<T> *temp = this->list_head;
        return temp->getData();
    }

    // Return the item stored inside the node the list_tail pointer's pointing
    // to
    T back() const {
        Double_node<T> *temp = this->list_tail;
        return temp->getData();
    }

    // Add a node storing the argument to the front of the list
    void push_front(T obj) {
        Double_node<T> *temp = this->list_head;
        // store temp of first element
        T temp_front = temp->getData();
        // create new node with first element value assigned to it
        Double_node<T> *new_node = new Double_node<T>(temp_front);
        // set first element to input obj
        temp->setData(obj);
        // set new_node's next to second element
        new_node->setNext(temp->getNext());
        // insert new node to second element
        temp->setNext(new_node);
        // set previous to first element
        new_node->setPrev(temp);

        //* notice that this function doesn't have set_head() because we swap
        //* the value of first element without changing it index
    }

    // Add a node storing the argument to the back of the list
    void push_back(T obj) {
        Double_node<T> *temp = this->list_tail;
        // create new node with input value assigned to it
        Double_node<T> *new_node = new Double_node<T>(obj);
        // set last element's next to new node (insert new node to the back)
        temp->setNext(new_node);
        // set new_node prev to previous element
        new_node->setPrev(temp);
        // set new tail because we have added one last element
        set_tail(new_node);
    }

    // Remove a node from the front of the list and return the data it stores
    T pop_front() {
        Double_node<T> *temp = this->list_head;
        T temp_data = temp->getData();
        // set head to second element
        set_head(temp->getNext());
        // set previous to null because second element becomes first element
        temp = this->list_head;
        temp->setPrev(nullptr);
        return temp_data;
    }

    // Remove a node from the back of the list and return the data it stores
    T pop_back() {
        Double_node<T> *temp = this->list_tail;
        // store last data
        T temp_data = temp->getData();
        // make list_tail to the prev node cuz we are gonna delete the last
        // element
        this->list_tail = temp->getPrev();
        // now make temp equal to previous of last element
        temp = this->list_tail;
        // set next equal null
        temp->setNext(nullptr);
        // set tail again
        set_tail(temp);

        // delete next of last element
        delete temp->getNext();

        return temp_data;
    }

    // Swap the contents of this list with the argument list
    void swap(Double_list *list) {
        // store temp first
        Double_node<T> *temp_head = this->list_head;
        Double_node<T> *temp_tail = this->list_tail;
        T temp_size = this->list_size;

        // swap
        this->set_head(list->list_head);
        this->set_tail(list->list_tail);
        this->set_size(list->list_size);

        list->set_head(temp_head);
        list->set_tail(temp_tail);
        list->set_size(temp_size);
    }
    // Delete the first node (from the front) storing a value equal to the
    // argument and return 1 if an object is found and deleted, else return 0
    int erase(T obj) {
        Double_node<T> *temp = this->list_head;
        while (temp != nullptr) {
            if (temp->getData() == obj) {
                // if the node is the first element
                if (temp->getPrev() == nullptr) {
                    pop_front();
                    return 1;
                } else if (temp->getNext() == nullptr) {
                    pop_back();
                    return 1;
                } else {
                    // if the node is neither front or back
                    // set previous of next node to previous of current node
                    temp->getNext()->setPrev(temp->getPrev());
                    // set next of previous node to next of current node
                    temp->getPrev()->setNext(temp->getNext());
                    // delete current node
                    delete temp;
                    return 1;
                }
            }
            temp = temp->getNext();
        }
        return 0;
    }

    // Copy the argument list to this list
    Double_list &operator=(const Double_list &rhs) {
        Double_list<T> *temp = new Double_list<T>(rhs);
        return temp;
    }

    // Destructor is a member function that is invoked automatically when the
    // object goes out of scope or is explicitly destroyed by a call to delete .
    ~Double_list() {
        // delete all nodes
        Double_node<T> *temp = this->list_head;
        while (temp != nullptr) {
            Double_node<T> *temp2 = temp->getNext();
            // delete temp;
            temp->~Double_node();
            temp = temp2;
        }
        // A message to show that the function has been used
        cout << "Destructed" << endl;
    }
};

int main() {
    // assign value
    Double_node<int> *head = new Double_node<int>(33);
    Double_node<int> *second = new Double_node<int>(33);
    Double_node<int> *tail = new Double_node<int>(35);

    // set next and previous to each node
    head->setNext(second);
    second->setPrev(head);
    second->setNext(tail);
    tail->setPrev(second);

    // create doubly linked-list and pass list
    Double_list<int> *dl = new Double_list<int>();
    dl->set_head(head);
    dl->set_tail(tail);
    dl->set_size(dl->return_size());

    // print the list
    cout << "\nprint list: ";
    dl->print_list();
    cout << "print list reverse: ";
    dl->print_list_reverse();

    // print size by return_size() function
    cout << "\nFind size function: " << dl->return_size() << endl;
    cout << "Size() function : " << dl->size() << endl;

    // is the list empty? (comment dl->set_head(head) to see the different)
    cout << "\nis the list empty? : " << dl->empty() << endl;

    // count obj
    cout << "\ncount(33): " << dl->count(33) << endl;
    cout << "count(55): " << dl->count(55) << endl;

    // front and back function
    cout << "\nfront(): " << dl->front() << endl;
    cout << "back(): " << dl->back() << endl;

    // push front and push back
    dl->push_front(5);
    cout << "\nNew list after push_front(5): ";
    dl->print_list();

    dl->push_back(10);
    cout << "New list after push_back(10): ";
    dl->print_list();

    // pop front and pop back
    cout << "\npop_front, the data it store is: " << dl->pop_front() << endl;
    cout << "print new list: ";
    dl->print_list();
    cout << "New size: " << dl->return_size() << endl;

    cout << "\npop_back, the data it store is: " << dl->pop_back() << endl;
    cout << "print new list: ";
    dl->print_list();
    cout << "New size: " << dl->return_size() << endl;

    //--------------------Double List ----------------------
    // copy list
    Double_list<int> *dl2 = new Double_list<int>(*dl);
    cout << "\nprint dl2 list after copy: ";
    dl2->print_list();
    cout << "dl2 size: " << dl->return_size() << endl;

    // -----------------------------------------------------

    // erase element
    cout << "\nerase(33): " << dl->erase(33) << endl;
    dl->print_list();

    //--------------------New List -------------------------
    Double_node<int> *head2 = new Double_node<int>(99);
    Double_node<int> *second2 = new Double_node<int>(88);
    Double_node<int> *tail2 = new Double_node<int>(11);
    // create list
    Double_list<int> *dl3 = new Double_list<int>();
    // set next and previous to each node
    head2->setNext(second2);
    second2->setPrev(head2);
    second2->setNext(tail2);
    tail2->setPrev(second2);
    // set head, tail
    dl3->set_head(head2);
    dl3->set_tail(tail2);
    dl3->set_size(dl3->return_size());

    cout << "\nprint dl3 list before swap: ";
    dl3->print_list();
    cout << "print dl list before swap: ";
    dl->print_list();

    // start swap
    dl->swap(dl3);
    cout << "\nprint dl3 list after swap: ";
    dl3->print_list();
    cout << "print dl list after swap: ";
    dl->print_list();

    // make some change to test whether it change value of both list or not
    cout << "\nTest change value after swap" << endl;
    dl3->push_back(77);
    cout << "print dl3 list after dl3 push_back(77): ";
    dl3->print_list();
    cout << "print dl list after dl3 push_back(77): ";
    dl->print_list();
    // -----------------------------------------------------
    
    // operator =
    cout << "\nTest operator = " << endl;
    Double_list<int> *dl4 = dl;
    cout << "print dl4 list after operator = : ";
    dl4->print_list();
    cout << "print dl list after operator = : ";
    dl->print_list();

    // Double_list Destructor
    cout << endl;
    delete dl;

    return 0;
}