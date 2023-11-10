#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class university
{
    string RollNo, Name, Subject, Address;

public:
    university() : RollNo(""), Name(""), Subject(""), Address("") {}
    setRollNo(string rollno)
    {
        RollNo = rollno;
    }
    setName(string name)
    {
        Name = name;
    }
    setSubject(string sub)
    {
        Subject = sub;
    }
    setAddress(string add)
    {
        Address = add;
    }

    string getName()
    {
        return Name;
    }
    string getRollNo()
    {
        return RollNo;
    }
    string getAddress()
    {
        return Address;
    }
    string getSubject()
    {
        return Subject;
    }
};

add(university student)
{
    string rollNo, name, subject, address;
    cout << "\tEnter RollNo of Student:";
    cin >> rollNo;
    student.setRollNo(rollNo);

    cout << "\tEnter name of student: ";
    cin >> name;
    student.setName(name);

    cout << "\tEnter subject of student:";
    cin >> subject;
    student.setSubject(subject);

    cout << "\tEnter Address of student:";
    cin >> address;
    student.setAddress(address);

    ofstream out("D:/university.txt", ios::app);
    if (!out)
    {
        cout << "\tError: File can't open!" << endl;
    }
    else
    {
        out << " \t" << student.getRollNo() << " : " << student.getName() << " : " << student.getSubject()
            << " : " << student.getAddress() << endl
            << endl;
    }
    out.close();
    cout << "\tStudent Adde successfully" << endl;
}

search()
{
    string rollno;
    cout << "\tEnter roll NO of student:";
    cin >> rollno;

    ifstream in("D:/university.txt");

    if (!in)
    {
        cout << "\tError: file can't open!" << endl;
    }

    string line;
    bool found = false;

    while (getline(in, line))
    {

        int data = line.find(rollno);
        if (data != string::npos)
        {

            cout << "\t" << line << endl;
            found = true;
        }
        if (!found)
        {
            cout << "\tstudent not found" << endl;
        }
    }
    in.close();
}

update(university student)
{
    string rollno;
    cout << "\tEter rollno of student:";
    cin >> rollno;

    ifstream infile("D:/university.txt");
    ofstream outfile("D:/university temp.txt");

    if (!infile || !outfile)
    {
        cout << "\tError: file can't open!" << endl;
    }
    string line;
    bool found = false;
    while (getline(infile, line))
    {
        int position = line.find(rollno);
        if (position != string::npos)
        {
            string address;
            cout << "\tEnter your New Address:";
            cin >> address;
            student.setAddress(address);

            int newpos = line.find_last_of(':');
            line.replace(newpos + 2, string::npos, student.getAddress());
        }
        outfile << line << endl;
        found = true;
    }
    if (!found)
    {
        cout << "\tStudent not found!" << endl;
    }

    outfile.close();
    infile.close();
    remove("D:/university.txt");
    rename("D:/university temp.txt", "D:/university.txt");
    cout << "\tData updated" << endl;
}

int main()
{
    university student;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;
        cout << "\twelcome" << endl;
        cout << "\t**************" << endl;
        cout << "\t1.Add Student." << endl;
        cout << "\t2.search Student." << endl;
        cout << "\t3.update data of student." << endl;
        cout << "\t4.Exit." << endl;
        cout << "\tEnter Your Choice: ";
        cin >> val;

        if (val == 1)
        {
            system("cls");
            add(student);
            // sleep(6000);
        }
        else if (val == 2)
        {
            system("cls");
            search();
            // sleep(6000);
        }
        else if (val == 3)
        {
            system("cls");
            update(student);
            //  Sleep(6000);
        }
        else if (val == 4)
        {
            system("cls");
            exit = true;
            cout << "\tOkay" << endl;
            // sleep(3000);
        }
    }
}