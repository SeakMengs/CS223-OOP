/*
 * @Author: Seakmeng Hor, Bunlong Prak, Sopheaknita Chea
 * Course: CS201, Section 1
 * Midterm Mission
 */

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Database {
   public:

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
   //* Getter and Setter -------------------------------------------------------------------------------------------------------------------------
    int getAge() const { return age; }

    void setAge(int age) { age = age; }

    string getId() const { return id; }

    void setId(int id) { id = id; }

    string getName() const { return name; }

    void setName(string name) { name = name; }

    string getGender() const { return gender; }

    void setGender(string gender) { gender = gender; }

    string getPosition() const { return position; }

    void setPosition(string position) { position = position; }
   //* End of Getter and Setter -------------------------------------------------------------------------------------------------------------------

    void printData() {
      cout << age << "\t\t" << id << "\t\t" << name << "\t\t" << gender << "\t\t" << position << endl;
    }
};

int main() {

   return 0; 
}