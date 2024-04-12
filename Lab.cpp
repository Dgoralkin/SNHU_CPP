#include <iostream>
#include <string>
#include <vector>
using namespace std;

// a Dany Home None

// Add an employee
void AddEmployee(vector<string>& name, vector<string>& department,
    vector<string>& title) {
    string theName;
    string theDept;
    string theTitle;

    cout << endl << "Enter the name to add: " << endl;
    getline(cin, theName);
    cout << "Enter " << theName << "'s department: " << endl;
    getline(cin, theDept);
    cout << "Enter " << theName << "'s title: " << endl;
    getline(cin, theTitle);

    name.push_back(theName);
    department.push_back(theDept);
    title.push_back(theTitle);

    cout << theName << "'s information has been added." << endl;
}

// Delete an employee
void DeleteEmployee(vector<string>& name, vector<string>& department,
    vector<string>& title) {

    string theName, theDept, theTitle;
    int employeeNum;

    cout << "FIXME: Delete employee" << endl;
    // FIXME: Ask the user for the employee # to delete, then delete that employee

    cout << endl << "Enter the name to delete: " << endl;
    getline(cin, theName);
    cout << "Enter " << theName << "'s department: " << endl;
    getline(cin, theDept);
    cout << "Enter " << theName << "'s title: " << endl;
    getline(cin, theTitle);

    for (int i = 0; i < name.size(); i++) {
        if (theName == name.at(i)) {
            // cout << "Name Found: " << name.at(i) << endl;

            for (int h = 0; h < department.size(); h++) {
                if (theDept == department.at(i)) {
                    // cout << "department Found: " << department.at(i) << endl;

                    for (int z = 0; z < title.size(); z++) {
                        if (theTitle == title.at(i)) {
                            // cout << "Title Found: " << title.at(i) << endl;

                            employeeNum = i;
                            cout << "\nemployeeNum: " << employeeNum << endl;
                            cout << endl;

                            name.erase(name.begin() + i);
                            department.erase(department.begin() + i);
                            title.erase(title.begin() + i);

                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "\nEmployee does not exist!\n" << endl;
    return;
}

// List all employees
void ListEmployees(vector<string>& name, vector<string>& department,
    vector<string>& title) {
    int nElements;
    int i;

    nElements = name.size();
    if (nElements > 0) {
        cout << endl;
        for (i = 0; i < nElements; ++i) {
            cout << i << ") Name: " << name.at(i) <<
                ",\tDepartment: " << department.at(i) <<
                ",\tTitle: " << title.at(i) << endl;
        }
    }
    else {
        cout << endl << "There are no employees to list." << endl;
    }
}

// Get the action the user wants to perform
char GetAction(string prompt) {
    string answer;
    char firstChar;

    firstChar = '?';

    cout << endl << prompt << endl;
    getline(cin, answer);
    while (answer.size() == 0) {
        getline(cin, answer);
    }
    firstChar = toupper(answer[0]);

    return firstChar;
}

int main0() {
    const char EXIT_CODE = 'X';
    const string PROMPT_ACTION = "Add, Delete, List or eXit (a,d,l,x): ";

    vector<string> name(0);
    vector<string> department(0);
    vector<string> title(0);

    char userAction;

    userAction = '?';

    // Loop until the user enters the exit code.
    userAction = GetAction(PROMPT_ACTION);

    while (userAction != EXIT_CODE) {
        switch (userAction) {
        case 'A': AddEmployee(name, department, title);
            break;
        case 'D': DeleteEmployee(name, department, title);
            break;
        case 'L': ListEmployees(name, department, title);
            break;
        default: // Do nothing
            break;
        }

        userAction = GetAction(PROMPT_ACTION);
    }

    return 0;
}