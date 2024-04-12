#include <iostream>
#include <string>
using namespace std;

class ContactNode {
public:
	/* Declare member functions here */
	ContactNode(string contactName = "Null", string contactPhoneNumber = "Null", ContactNode* nextNodePtr = nullptr);
	~ContactNode();
	void InsertAfter(ContactNode* nodeLoc);
	ContactNode* GetNext();
	string GetName();
	string GetPhoneNumber();
	void PrintContactNode();

private:
	// Class members.
	string contactName;
	string contactPhoneNumber;
	ContactNode* nextNodePtr;
};

// Constructor
ContactNode::ContactNode(string contactName, string contactPhoneNumber, ContactNode* nextNodePtr) {
	this->contactName = contactName;
	this->contactPhoneNumber = contactPhoneNumber;
	this->nextNodePtr = nextNodePtr;

	cout << "Constructor: " << contactName << ", ThisNodePtr: " << this << " Created." << endl;
}

// Destructor
ContactNode::~ContactNode() {
	cout << endl << "Curr Object Deleted: " << this;
}

// Insert node into linked nodes list.
void ContactNode::InsertAfter(ContactNode* nodeLoc) {
	ContactNode* tmpNext = nullptr;

	tmpNext = this->nextNodePtr;    // Remember next
	this->nextNodePtr = nodeLoc;    // this -- node -- ?
	nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
}

// Get location pointed by nextNodePtr
ContactNode* ContactNode::GetNext() {
	return this->nextNodePtr;
}

// Function returns contact's name details 
string ContactNode::GetName() {
	return this->contactName;
}

// Function returns contact's phone number details 
string ContactNode::GetPhoneNumber() {
	return this->contactPhoneNumber;
}

// Prints instance of selected node.
void ContactNode::PrintContactNode() {
	cout << "Name: " << this->contactName << endl;
	cout << "Phone number: " << this->contactPhoneNumber << endl;
	cout << "Address: " << this << endl;
}

// Function reads user's name and phone number input.
void GetInput(string& userName, string& userPhone) {

	// Read user name
	cout << endl << "Enter name: " << endl;
	getline(cin, userName);

	// Read user phone
	cout << "Enter phone: " << endl;
	getline(cin, userPhone);
}

int main() {

	// Variables.
	string userName, userPhone;
	const string PROMPT_ACTION = "Enter Three names and phone numbers as follows: Roxanne Hughes 443 - 555 - 2864";
	const int ITERATIONS = 3;

	// Create ContactNode objects
	ContactNode* headObj = nullptr;
	ContactNode* currObj = nullptr;
	ContactNode* lastObj = nullptr;

	// Define Head and tail of "ContactNode" linked List.
	headObj = new ContactNode;
	lastObj = headObj;

	// Print instructions prompt.
	cout << PROMPT_ACTION << endl;

	// Repeat action "ITERATIONS" times.
	for (int i = 0; i < ITERATIONS; i++) {

		// Get user input
		GetInput(userName, userPhone);

		// Add node to linked list.
		currObj = new ContactNode(userName, userPhone);		// Create new node instance.
		lastObj->InsertAfter(currObj);						// Append current node to list.
		lastObj = currObj;									// Update last list's node.
	}
	cout << endl;

	// Reset the cursor to the head of the list.
	currObj = headObj->GetNext();
	// Loop though all list's nodes starting the head and print all persons.
	for (int i = 0; i < ITERATIONS; i++) {
		cout << "Person " << i + 1 << ": " << currObj->GetName() << ", " << currObj->GetPhoneNumber() << endl;
		currObj = currObj->GetNext();						// Move cursor to the next node.
	}

	// Reset the cursor to the head of the list.
	currObj = headObj->GetNext();
	cout << endl << "CONTACT LIST" << endl;

	// Loop though all list's nodes starting the head and print all members.
	while (currObj != nullptr) {

		currObj->PrintContactNode();						// Print node's values.
		currObj = currObj->GetNext();						// Move cursor to the next node.
		cout << endl;
	}

	// Reset the cursor to the head of the list.
	currObj = headObj;

	// Clear all allocated memory.
	while (currObj != nullptr) {

		ContactNode* next = currObj;
		currObj = currObj->GetNext();
		delete next;
	}
	delete currObj;

	return 0;
}
