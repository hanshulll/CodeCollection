/* A C++ program to read and write multiple student details to files,
 read them and if required, delete the files aswell */

#include<iostream> //Used for the standard I/O functions ie cin and cout
#include<fstream> //Used for file manipulation tasks

using namespace std;



char filename[20]; //A string to store the name of the file globally

struct student{     // A structure to store student details
    char name[20];
    char usn[20];
    int age;
};

student studentInput(); // A function prototype for a function that takes student data
void studentDisplay(struct student); // A function prototype for a functon that displays student data
void studentWrite(struct student); // A function prototype for a function that writes data to a file
student studentRead(struct student); // A function prototype for a function that reads data from a file

int main()
{
    int n; // To store the number of records 
    char ch; // To store the choice 
    student *s;
    s = new student[10]; // To store the records
    cout<<"We will create a file! Give it a name:\n";
    cin>>filename;
    // A do while loop to control the exit of the program.
    do{ RESTART:
        cout<<"************************************************************\n";
        cout<<"Choose what to do with the file "<<filename<<". \n1- Added details of a certain number of students to it.\n2- Read from the file "<<filename<<" and display the student records on it.\n3- Delete the file named "<<filename<<".\n4- Done with the everything? Exit!\n";
        cout<<"************************************************************\n";
        cout<<"Choice:";
        cin>>ch;
        cout<<"\n************************************************************\n";
        
        switch(ch)
        {
            case '1':   cout<<"Enter the number of student records to be written.\n";
                        cin>>n;
                        
                        // A loop to write n number of records
                        for(int i=0;i<n;i++)
                        {   
                            s[i] = studentInput();
                            studentWrite(s[i]);

                        }
                        break;
            case '2':
                        // A loop to read n number of records
                        for(int i=0;i<n;i++)
                        {
                            studentRead(s[i]);
                            studentDisplay(s[i]);
                        }   
                        break;
            case '3':   remove(filename);
                        cout<<"*****File sucessfully deleted!*****"; exit(0); // To delete the file specified
            case '4':   exit(0); //For the exit

            default: cout<<"Invalid Choice selected! Please try again."; goto RESTART;
                      
        }

    
    }while(1);

}
student studentInput() // A function that takes student data
{   
    student s;
    cout<<"\n************************************************************\n";
    cout<<"Enter the student's name:\n";
    cin>>s.name;
    cout<<"Enter the student's USN:\n";
    cin>>s.usn;
    cout<<"Enter the student's age:\n";
    cin>>s.age;
    cout<<"\n************************************************************\n";

    return s;
}
void studentDisplay(student s) // A function that displays student data
{
    cout<<"*****File Read Sucessfully*****\n\nName: "<<s.name<<"\nUSN: "<<s.usn<<"\nAge: "<<s.age<<"\n\n**************************\n";
   
}
void studentWrite(student s) // A function that writes data to a file
{
    ofstream outputFile;
    outputFile.open(filename,ios::out|ios::app);
    outputFile<<s.name<<"\n"<<s.usn<<" \n"<<s.age<<"\n";
    outputFile.close();
}
student studentRead(student s) // A function that reads data from a file
{
    char ch;
    ifstream inputFile;
    inputFile.open(filename);
    
    
    inputFile.get(s.name,30);
    inputFile.get(ch);
    inputFile.get(s.name,30);
    inputFile.get(ch);
    inputFile.close();
    return s;
}