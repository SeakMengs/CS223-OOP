/// @author: Seakmeng Hor, Bunlong Prak, Sopheaknita Chea
/// @course: CS201 Section 1

#include <bits/stdc++.h>

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
        for (int i = 0; i < this->arraySize; i++) {
            temp[i] = employee[i];
        }
        delete[] employee;
        employee = temp;
    }

    // function to insert data at specific index
    void insertData(int age, string id, string name, string gender,
                    string position, int index) {
        if (index == this->arraySize) {
            resize(arraySize + 10);
            setArraySize(arraySize + 10);
        }
        employee[index].setAge(age);
        employee[index].setId(id);
        employee[index].setName(name);
        employee[index].setGender(gender);
        employee[index].setPosition(position);
    }

/// @implements --------------------------------------------------------------
    // Feature#2 add data from behind
    void push_back(int age, string id, string name, string gender,
                   string position) {

    }

    // Feature#2 delete data from the front
    void pop_front() {

    }

    // Feature#1 print data
    void printData() {

    }

    void search(string id) {

    }
//*----------------------------------------------------------------------------

    // destructor to avoid memory leak
    ~Database() {
        delete[] employee;
        cout << "\nDestructor called in order to avoid memory leak" << endl;
    }
};

int main() {
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