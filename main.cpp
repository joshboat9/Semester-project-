#include <iostream>
#include <string>

using namespace std;

const int MAX_RECORDS = 1000;  // Maximum number of records

class PhoneBookRecord {
public:
    int srno;
    string name;
    string mobile;
    string email;
    string group;

    void inputRecord() {
        system ("cls");
        cout << "\n\t\t********* ADD CONTACT *********\n";
		cout << "\t\tEnter Serial Number: ";
        cin >> srno;
        cin.ignore();  // Clear the newline character from the buffer
        cout << "\t\tEnter Record Name: ";
        getline(cin, name);
        cout << "\t\tEnter Mobile Number: ";
        getline(cin, mobile);
        cout << "\t\tEnter E-Mail I.D.: ";
        getline(cin, email);
        cout << "\t\tEnter Record Group: ";
        getline(cin, group);
    }

    void displayRecord() {
        cout << "\n\t\t****** PHONEBOOK RECORD ******\n";
        cout << "\t\tSr. No.    : " << srno << endl;
        cout << "\t\ttName       : " << name << endl;
        cout << "\t\tMobile No. : " << mobile << endl;
        cout << "\t\tEmail ID   : " << email << endl;
        cout << "\t\tGroup      : " << group << endl;
        cout << "\n\t\t Record Display successfully \n" << endl;
    }
    
};

class PhoneBook {
private:
    PhoneBookRecord records[MAX_RECORDS];
    int numRecords;

public:
    PhoneBook() : numRecords(0) {}

    void addRecord() {
        if (numRecords < MAX_RECORDS) {
            records[numRecords].inputRecord();
            numRecords++;
            cout << "\n\t\tRecord Added Successfully.\n";
        } else {
            cout << "\n\t\tPhone Book is Full. Cannot Add More Records.\n";
        }
    }

    void displayAllRecords() {
    	system ("cls");
        cout << "\n\t\t****** ALL PHONEBOOK RECORDS ******\n";
        for (int i = 0; i < numRecords; ++i) {
            records[i].displayRecord();
            return;
        }
    }

    void searchRecordBySrNo(int srno) {
		for (int i = 0; i < numRecords; ++i) {
            if (records[i].srno == srno) {
                records[i].displayRecord();
                return;
            }
        }
        cout << "\n\t\tRecord with Serial Number " << srno << " not found.\n";
    }

    void deleteRecordBySrNo(int srno) {
        for (int i = 0; i < numRecords; ++i) {
            if (records[i].srno == srno) {
                records[i] = records[numRecords - 1];
                numRecords--;
                cout << "\n\t\tRecord Deleted Successfully.\n";
                return;
            }
        }
        cout << "\n\t\tRecord with Serial Number " << srno << " not found.\n";
    }

    void modifyRecordBySrNo(int srno) {
        for (int i = 0; i < numRecords; ++i) {
            if (records[i].srno == srno) {
                records[i].inputRecord();
                cout << "\n\t\tRecord Modified Successfully.\n";
                return;
            }
        }
        cout << "\n\t\tRecord with Serial Number " << srno << " not found.\n";
    }
};

void displayMenu() {
	cout << "\n\t\t------------------------------------\n";
	cout << "-\t\t-----------------------------------\n";	
    cout << "\n\t\t----- PHONEBOOK MANAGEMENT -----\n";
    cout << "\t\t1. Add New Record\n";
    cout << "\t\t2. Display All Records\n";
    cout << "\t\t3. Search Record by Serial Number\n";
    cout << "\t\t4. Delete Record by Serial Number\n";
    cout << "\t\t5. Modify Record by Serial Number\n";
    cout << "\t\t6. Exit\n";
    cout << "\t\tEnter Your Choice: ";
}

int main() {
	system ("color 3F");
    PhoneBook phoneBook;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Clear the newline character from the buffer

        switch (choice) {
            case 1:
            	phoneBook.addRecord();
                break;
            case 2:
				phoneBook.displayAllRecords();
                break;
            case 3: {
                int srno;
				cout << "\t\tEnter Serial Number to Search: ";
                cin >> srno;
                phoneBook.searchRecordBySrNo(srno);
                break;
            }
            case 4: {
                int srno;
                cout << "\n\t\t***** DELETING CONTACT *****\n";
				cout << "\n\t\tEnter Serial Number to Delete: ";
                cin >> srno;
                phoneBook.deleteRecordBySrNo(srno);
                break;
            }
            case 5: {
                int srno;
                cout << "\n\t\t***** MODIFYING CONTACT *****\n";
				cout << "\n\t\tEnter Serial Number to Modify: ";
                cin >> srno;
                phoneBook.modifyRecordBySrNo(srno);
                break;
            }
            case 6:
            	system ("cls");
            	cout << "\n\t\t********* EXITING PHONEBOOK MANAGEMENT *********\n";
                cout << "\n\t\tThank You for using Phone Book Management System!\n";
                break;
                
            default:
                cout << "\n\t\tInvalid Choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

