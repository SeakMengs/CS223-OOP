/// @author: Seakmeng Hor, Bunlong Prak, Sopheaknita Chea
/// @course: CS201 Section 1

#include <iostream>
using namespace std;

/// @brief Employee class to store data, access data
class Employee {
    // Feature#1
   private:
    int age;
    string id;
    string name;
    string gender;
    string position;

   public:
    //* Getter and Setter ------------------------------------------------------
    int getAge() const { return this->age; }

    void setAge(int age) { this->age = age; }

    string getId() const { return this->id; }

    void setId(string id) { this->id = id; }

    string getName() const { return this->name; }

    void setName(string name) { this->name = name; }

    string getGender() const { return this->gender; }

    void setGender(string gender) { this->gender = gender; }

    string getPosition() const { return this->position; }

    void setPosition(string position) { this->position = position; }
    //* End of Getter and Setter -----------------------------------------------
};

/// @brief  Database class to store data, access data, resize array, insert data
/// and many more
class Database {
   private:
    int arraySize;
    Employee *employee;
    int currentSize = 0;

   public:
    //* Getter and Setter ------------------------------------------------------
    int getCurrentSize() const { return this->currentSize; }

    void setCurrentSize(int currentSize) { this->currentSize = currentSize; }

    int getArraySize() const { return this->arraySize; }

    void setArraySize(int arraySize) { this->arraySize = arraySize; }

    Employee *getEmployee() const { return this->employee; }

    void setEmployee(Employee *employee) { this->employee = employee; }
    //* End of Getter and Setter -----------------------------------------------

    // constructor with default fixed size of 10
    Database() {
        setArraySize(10);
        employee = new Employee[10];
    }

    // constructor with fixed size from user
    Database(int arraySize) {
        setArraySize(arraySize);
        employee = new Employee[arraySize];
    }

    // function to resize the array
    void resize(int arraySize) {
        Employee *temp = new Employee[arraySize];
        for (int i = 0; i < getArraySize(); i++) {
            temp[i] = employee[i];
        }
        delete[] employee;
        setEmployee(temp);
    }

    // function to insert data at specific index
    void insertData(int age, string id, string name, string gender,
                    string position, int index) {
        if (index == getArraySize()) {
            resize(arraySize + 10);
            setArraySize(arraySize + 10);
        }

        employee[index].setAge(age);
        employee[index].setId(id);
        employee[index].setName(name);
        employee[index].setGender(gender);
        employee[index].setPosition(position);
    }

    // Feature#2 add data from behind
    void push_back(int age, string id, string name, string gender,
                   string position) {
        insertData(age, id, name, gender, position, currentSize);
        setCurrentSize(this->currentSize + 1);
    }

    // Feature#2 delete data from the front
    void pop_front() {
        if (getCurrentSize() == 0) {
            cout << "\nEmpty data cannot be pop fronted" << endl;
            return;
        }

        Employee *temp = new Employee[getArraySize()];
        for (int i = 1; i < getCurrentSize(); i++) {
            temp[i - 1] = employee[i];
        }
        delete[] employee;
        setEmployee(temp);
        setCurrentSize(this->currentSize - 1);
    }

    // Feature#1 print data
    void printData() {
        if (getCurrentSize() == 0) {
            cout << "\nEmpty data" << endl;
            return;
        }

        cout << "\nNo.\t\tAge\t\tID\t\tName\t\tGender\t\tPosition" << endl;
        for (int i = 0; i < currentSize; i++) {
            cout << i + 1 << ".\t\t" << employee[i].getAge() << "\t\t"
                 << employee[i].getId() << "\t\t" << employee[i].getName()
                 << "\t\t" << employee[i].getGender() << "\t\t"
                 << employee[i].getPosition() << endl;
        }
    }

    // Feature#3 search using id
    void search(string id) {
        for (int i = 0; i < getCurrentSize(); i++) {
            if (employee[i].getId() == id) {
                cout << "\nAge\t\tID\t\tName\t\tGender\t\tPosition" << endl;
                cout << employee[i].getAge() << "\t\t" << employee[i].getId()
                     << "\t\t" << employee[i].getName() << "\t\t"
                     << employee[i].getGender() << "\t\t"
                     << employee[i].getPosition() << endl;
                return;
            }
        }
        cout << "\nID " << id << " not found" << endl;
    }

    // destructor to avoid memory leak
    ~Database() {
        delete[] employee;
        cout << "\nDestructor called in order to avoid memory leak" << endl;
    }
};

int main() {

    // clear terminal
    system("cls");

    // Database database1;

    // database1 with fixed array size of 50
    Database database1 = Database(50);

    database1.push_back(15, "1500", "first", "male", "student");
    database1.push_back(15, "1501", "second", "male", "student");
    database1.push_back(15, "1502", "yato", "male", "student");
    database1.push_back(15, "1503", "yato", "male", "student");
    database1.push_back(15, "1504", "yato", "male", "student");
    database1.push_back(15, "1505", "yato", "male", "student");
    database1.push_back(15, "1506", "yato", "male", "student");
    database1.push_back(15, "1507", "yato", "male", "student");
    database1.push_back(15, "1508", "yato", "male", "student");
    database1.push_back(15, "1509", "yato", "male", "student");
    database1.push_back(15, "1510", "yato", "male", "student");

    database1.pop_front();

    database1.printData();

    database1.search("1501");

    return 0;
}