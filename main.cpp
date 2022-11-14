#include <iostream>
#include <string.h>

using namespace std;

struct date
{
    char d_m[6];
    int year;
};

class Student
{
    private:
    char name[100];
    date t;
    char address[100], faculty[100], mobile_number[20];
    int grade;

    public:
    Student();
    char *getfaculty();
    int getgrade();
    void show();
    int getyear();
};

Student::Student()
{
    cin.ignore();
    cout << "Input name: "; cin.getline(name, 100);
    cout << "Input date of born" << endl << "Day.Month: "; cin >> t.d_m;
    cout << "Year: "; cin >> t.year;
    cin.ignore();
    cout << "Input address: "; cin.getline(address, 100);
    cout << "Input faculty: "; cin.getline(faculty, 100);
    cout << "Input grade: "; cin >> grade;
    cout << "Input mobile number: "; cin >> mobile_number;
    cout << endl;
}

void Student::show()
{
    cout << "Name: " << name << endl;
    cout << "Was born: " << t.d_m << '.' << t.year << endl;
    cout << "Address: " << address << endl;
    cout << "Faculty: " << faculty << endl;
    cout << "Grade: " << grade << endl;
    cout << "Mobile number: " << mobile_number << endl;
    cout << "---" << endl;
}

int Student::getyear()
{
    return t.year;
}

char *Student::getfaculty()
{
    return faculty;
}

int Student::getgrade()
{
    return grade;
}

void List_Faculty(Student list[], int n)
{
    char faculty[100];
    cin.ignore();
    cout << "Input faculty: "; cin.getline(faculty,100); cout << endl;
    for(int i = 0; i<n; i++)
    {
        if (strcmp(list[i].getfaculty(),faculty)==0)list[i].show();
    }
}

void switch_instructions()
{
    cout << "1 - Output list of students from one faculty" << endl;
    cout << "2 - Output list of students from one faculty and one grade" << endl;
    cout << "3 - Output a list of students born after a certain year" << endl;
    cout << "0 - Exit" << endl;
}

void Student_Year(Student list[], int n)
{
    int year_check;
    cout << "Input year: "; cin >> year_check; cout << endl;
    for(int i = 0; i < n; i++)
    {
        if ((list[i].getyear()) > year_check)list[i].show();
    }
}

void List_Faculty_Grade(Student list[], int n)
{
    int k;
    char faculty[100];
    cin.ignore();
    cout << "Input faculty: "; cin.getline(faculty, 100);
    cout << "Input grade: "; cin >> k; cout << endl;
    for(int i = 0; i<n; i++)
    {
        if ((strcmp(list[i].getfaculty(), faculty)==0)&&(list[i].getgrade()==k))list[i].show();
    }
}

int main (void)
{
    int choice;
    Student *list;
    int n;
    cout << "Input a number of students: "; cin >> n;
    list = new Student[n];
    switch_instructions();
    do
    {
        cout << "Select a menu item: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                List_Faculty(list, n);
                break;
            case 2:
                List_Faculty_Grade(list, n);
                break;
            case 3:
                Student_Year(list, n);
                break;
        }
    }
    while(choice != 0);
    delete[]list;
    return 0;
}