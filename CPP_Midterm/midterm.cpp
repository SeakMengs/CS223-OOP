/// @author: Seakmeng Hor, Bunlong Prak, Sopheaknita Chea
/// @course: CS201 Section 1

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Database {
   public:
    // default constructor of array size of 10
    Database() {
        Employee employee[10];
    }
    // constructor with fixed size
    Database(int arraySize) {
        Employee employee[arraySize];
    }
};

/// @brief Employee class to store data, access data
class Employee {
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

    void setId(int id) { this->id = id; }

    string getName() const { return this->name; }

    void setName(string name) { this->name = name; }

    string getGender() const { return this->gender; }

    void setGender(string gender) { this->gender = gender; }

    string getPosition() const { return this->position; }

    void setPosition(string position) { this->position = position; }
    //* End of Getter and Setter -----------------------------------------------

    // function to print out the data
    void printData() {
        cout << age << "\t\t" << id << "\t\t" << name << "\t\t" << gender
             << "\t\t" << position << endl;
    }
};

int main() { 
    Database database1;
    return 0;
}