/// @author: Seakmeng Hor, Bunlong Prak, Sopheaknita Chea
/// @course: CS201 Section 1

#include <iostream>
// required for file writing and reading file
#include <fstream>
#include <chrono>

using namespace std;

// declare global variable
auto start = chrono::steady_clock::now();


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
    // Declare Employee object in order to create dynamic array later
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

    // Feature#4 function to insert data at specific index (can also modify
    // data)
    void modifyData(int age, string id, string name, string gender,
                    string position, int index) {
        // since non-programmer count from 1, we adapt to their use but in our
        // program we minus index by 1 because array index start from 0
        index--;

        // since we use this function for push back, we need to check if array
        // is out of bound and resize it
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

    // Feature#4 modify age
    void modifyAge(int age, int index) {
        // since non-programmer count from 1, we adapt to their use but in our
        // program we minus index by 1 because array index start from 0
        index--;
        employee[index].setAge(age);
    }

    // Feature#4 modify id
    void modifyId(string id, int index) {
        // since non-programmer count from 1, we adapt to their use but in our
        // program we minus index by 1 because array index start from 0
        index--;
        employee[index].setId(id);
    }

    // Feature#4 modify name
    void modifyName(string name, int index) {
        // since non-programmer count from 1, we adapt to their use but in our
        // program we minus index by 1 because array index start from 0
        index--;
        employee[index].setName(name);
    }

    // Feature#4 modify gender
    void modifyGender(string gender, int index) {
        // since non-programmer count from 1, we adapt to their use but in our
        // program we minus index by 1 because array index start from 0
        index--;
        employee[index].setGender(gender);
    }

    // Feature#4 modify position
    void modifyPosition(string position, int index) {
        // since non-programmer count from 1, we adapt to their use but in our
        // program we minus index by 1 because array index start from 0
        index--;
        employee[index].setPosition(position);
    }

    // Feature#2 add data from behind
    void push_back(int age, string id, string name, string gender,
                   string position) {
        // push to last index
        modifyData(age, id, name, gender, position, getCurrentSize() + 1);
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

    // Feature#5 helper function
    void validateFileName(string &fileName) {
        // if find .csv extension, don't do anything, else we add .csv extension
        string isCSV = fileName.substr(fileName.length() - 4, 4);
        if (isCSV != ".csv") {
            fileName += ".csv";
        } else {
            cout << "\nFile name already contain .csv extension" << endl;
        }
    }

    // Feature#5 save data to csv format (by default if no file name is given,
    // it will be saved as data.csv)
    void save(string fileName = "data") {
        
        validateFileName(fileName);

        // if data is empty, print error message
        if (getCurrentSize() == 0) {
            cout << "\nEmpty data cannot be saved" << endl;
            return;
        }

        // create file if not exist, if exist, overwrite it
        fstream file(fileName, ios::out);

        // test if we can open file or not, if not print error message
        if (!file.is_open()) {
            cout << "\nSomething went wrong, maybe the file name contain "
                    "special character?"
                 << endl;
            return;
        }

        // write header to file first
        file << "Age,"
             << "ID,"
             << "Name,"
             << "Position," << endl;

        // write data to file
        for (int i = 0; i < getCurrentSize(); i++) {
            file << employee[i].getAge() << "," << employee[i].getId() << ","
                 << employee[i].getName() << "," << employee[i].getGender()
                 << "," << employee[i].getPosition() << endl;
        }

        file.close();
    }

    // Feature#5 load data from csv format (by default if no file name is given,
    // it will load data.csv)
    void load(string fileName = "data") {

        // if we don't want to load data to non-empty database, uncomment this
        // if (getCurrentSize() != 0) {
        //     cout << "\nDatabase is not empty, cannot load data" << endl;
        //     return;
        // }

        validateFileName(fileName);

        // if file is not exist, print error message
        if (!ifstream(fileName)) {
            cout << "\nFile " << fileName << " not found" << endl;
            return;
        }

        // delete current database
        delete[] employee;
        // create new array database and set current size to 0
        setEmployee(new Employee[getArraySize()]);
        setCurrentSize(0);

        // open and read file
        fstream file;
        file.open(fileName, ios::in);

        if (file.is_open()) {
            int age = 0;
            string line, id, name, gender, position;

            // read header because we don't need it to push to database
            file >> line;

            // read data and push to database while not end of file
            while (!file.eof()) {
                file >> line;

                // since we read line by line, if line is empty, it means we
                // reach end of file
                if (line == "") {
                    break;
                }

                // remove comma from line and store it to age, id, name, gender,
                // position after storing age, remove age and comma from line
                age = stoi(line.substr(0, line.find(",")));
                line.erase(0, line.find(",") + 1);

                id = line.substr(0, line.find(","));
                line.erase(0, line.find(",") + 1);

                name = line.substr(0, line.find(","));
                line.erase(0, line.find(",") + 1);

                gender = line.substr(0, line.find(","));
                line.erase(0, line.find(",") + 1);

                // the rest of line is position
                position = line;
                // set line to empty string
                line = "";

                // push data to database
                push_back(age, id, name, gender, position);
            }
        } else {
            cout << "\nFile " << fileName << " cannot be opened" << endl;
        }

        file.close();
    }

    // Feature#6 sort by id (ascending)
    void sortByIdAsc() {
        // if data is empty, print error message
        if (getCurrentSize() == 0) {
            cout << "\nEmpty data cannot be sorted" << endl;
            return;
        }

        // sort using insertion sort
        for (int i = 1; i < getCurrentSize(); i++) {
            Employee temp = employee[i];
            int j = i - 1;

            while (j >= 0 && employee[j].getId() > temp.getId()) {
                employee[j + 1] = employee[j];
                j--;
            }

            employee[j + 1] = temp;
        }

    }

    // Feature#6 sort by id (descending)
    void sortByIdDesc() {
        // if data is empty, print error message
        if (getCurrentSize() == 0) {
            cout << "\nEmpty data cannot be sorted" << endl;
            return;
        }

        // sort using insertion sort
        for (int i = 1; i < getCurrentSize(); i++) {
            Employee temp = employee[i];
            int j = i - 1;

            while (j >= 0 && employee[j].getId() < temp.getId()) {
                employee[j + 1] = employee[j];
                j--;
            }

            employee[j + 1] = temp;
        }
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

    Database database;

    // database with fixed array size of 50
    // Database database = Database(50);

    database.push_back(15, "1500", "first", "male", "student");
    database.push_back(18, "1501", "second", "female", "student");
    database.push_back(19, "1503", "yato", "male", "student");
    database.push_back(15, "1502", "kakashi", "male", "student");
    database.push_back(18, "1505", "nita", "female", "student");
    database.push_back(15, "1504", "naruto", "male", "student");
    database.push_back(11, "1506", "Sak", "male", "student");
    database.push_back(15, "1507", "L", "male", "student");
    database.push_back(15, "1509", "Bunlong", "male", "student");
    database.push_back(53, "1508", "Nate", "male", "student");
    database.push_back(19, "1511", "Meng", "male", "student");
    database.push_back(19, "1510", "Tom", "male", "student");

    database.pop_front();
    database.pop_front();

    database.printData();

    database.search("1501");
    database.search("15051");
    database.search("1511");

    // modify data at row (age, id, name, gender, position, index)
    database.modifyData(20, "1502", "Kai", "female", "doctor", 2);

    // modify by one variable at row (variable, index)
    database.modifyAge(25, 1);
    database.modifyName("Fanny", 5);

    // print database again to prove our data has been updated
    database.printData();

    // save database to csv file
    database.save();

    // create database2 to load data from csv file
    cout << "\nDatabase2 created to load data from csv file";

    Database database2;

    // load data from csv file to database2 and print it
    database2.load();
    database2.push_back(87, "1515", "Jame", "male", "actor");
    
    database2.sortByIdAsc();
    database2.printData();

    database2.sortByIdDesc();
    database2.printData();
    
    database2.save("employee_detail.csv");
    // database2.save("employee_detail!@#$%&^&*(*())");

    // load data from csv file to database2 and print it again to show we override database2
    cout << "\nLoad data from csv file to database2 again to show we override database2" << endl;
    database2.load("employee_detail");
    database2.push_back(50, "1516", "Tom", "male", "actor");
    database2.printData();

    // show time complexity
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "\n"
         << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    return 0;
}