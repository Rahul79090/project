#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Function declarations
void login();
void addPatient();
void addDiagnosis();
void viewHistory();
void hospitalInfo();

int main()
{
    int choice;

    login();

    while (true)
    {
        cout << "\n\n=====================================\n";
        cout << "      HOSPITAL MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add New Patient Record\n";
        cout << "2. Add Diagnosis Information\n";
        cout << "3. Full History of Patient\n";
        cout << "4. Information About Hospital\n";
        cout << "5. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            addDiagnosis();
            break;
        case 3:
            viewHistory();
            break;
        case 4:
            hospitalInfo();
            break;
        case 5:
            cout << "\nThank you for using Hospital Management System!\n";
            return 0;
        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    }
}

//  LOGIN 
void login()
{
    string password;

    cout << "\n=====================================\n";
    cout << "              LOGIN\n";
    cout << "=====================================\n";
    cout << "Enter Password: ";
    cin >> password;

    if (password != "pass")
    {
        cout << "Wrong password! Try again.\n";
        login();
    }
    else
    {
        cout << "Access Granted!\n";
    }
}

//  ADD PATIENT 
void addPatient()
{
    string filename;
    ofstream file;

    cout << "\nEnter patient file name: ";
    getline(cin, filename);

    file.open(filename);
    if (!file)
    {
        cout << "Error creating file!\n";
        return;
    }

    string name, address, contact, age, sex, blood, disease, id;

    cout << "Name: ";
    getline(cin, name);
    cout << "Address: ";
    getline(cin, address);
    cout << "Contact Number: ";
    getline(cin, contact);
    cout << "Age: ";
    getline(cin, age);
    cout << "Sex: ";
    getline(cin, sex);
    cout << "Blood Group: ";
    getline(cin, blood);
    cout << "Past Disease: ";
    getline(cin, disease);
    cout << "Patient ID: ";
    getline(cin, id);

    file << "---------- Patient Details ----------\n";
    file << "Name: " << name << endl;
    file << "Address: " << address << endl;
    file << "Contact: " << contact << endl;
    file << "Age: " << age << endl;
    file << "Sex: " << sex << endl;
    file << "Blood Group: " << blood << endl;
    file << "Past Disease: " << disease << endl;
    file << "Patient ID: " << id << endl;

    file.close();
    cout << "\nPatient record saved successfully!\n";
}

//  ADD DIAGNOSIS 
void addDiagnosis()
{
    string filename;
    fstream file;

    cout << "\nEnter patient file name: ";
    getline(cin, filename);

    file.open(filename, ios::app);
    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    time_t now = time(0);

    string symptoms, diagnosis, medicine, ward;

    cout << "Symptoms: ";
    getline(cin, symptoms);
    cout << "Diagnosis: ";
    getline(cin, diagnosis);
    cout << "Medicines: ";
    getline(cin, medicine);
    cout << "Ward Type: ";
    getline(cin, ward);

    file << "\n---------- Diagnosis ----------\n";
    file << "Date: " << ctime(&now);
    file << "Symptoms: " << symptoms << endl;
    file << "Diagnosis: " << diagnosis << endl;
    file << "Medicines: " << medicine << endl;
    file << "Ward Type: " << ward << endl;

    file.close();
    cout << "\nDiagnosis added successfully!\n";
}

//  VIEW HISTORY 
void viewHistory()
{
    string filename;
    ifstream file;

    cout << "\nEnter patient file name: ";
    getline(cin, filename);

    file.open(filename);
    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    string line;
    cout << "\n========== Patient History ==========\n";
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// HOSPITAL INFO 
void hospitalInfo()
{
    cout << "\n========== Hospital Information ==========\n";
    cout << "Hospital Name: City Care Hospital\n";
    cout << "Address: Main Road, India\n";
    cout << "24x7 Emergency Services Available\n";
    cout << "Specialists in All Departments\n";
}