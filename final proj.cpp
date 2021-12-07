/*Mustafa Esam,Mohamed Elfeki,Ahmed Awad,Osama Ahmed, Mohamed abdallah*/
/*The functions in the code have for loop to search in the array of object of class student
that the user want to edit or display or even when he insert a student to make sure that the
roll number he adds is new and not used before, switch cases is used to get the user command
whether he likes to end the program or call the same function again or to go to the main menu.
The the full mark in the code is 100 and the number of max students can be changed easily */
//Student Report Management System
#include <iostream>
#include <fstream>
#include <string>
#include<cstdio>
using namespace std;

 class student
{
 string first_name , second_name;
 string full_name;
 int roll_no;
 int Marks[20];
 string department;
 float summarks;
 float avgmarks;//the percentage of the student
 int num_subject;
 public:
     struct address
     {
         string city;
         string resarea;
         string zip;
     };
     address setaddress;

    //setting the private members through set functions
     void setname(string n,string m)//setting name
     {
         first_name = n;
         second_name = m;
         full_name = first_name +' '+ second_name;
     }
     void setroll(int r)//setting roll number
     {
         roll_no = r;
     }
     void setSubject(int l)//setting subjects
     {
         num_subject = l;
     }
     void setmarks(int m[])//setting marks

     {

         for (int j = 0; j < num_subject; j++)
         {
             Marks[j] = m[j];
         }
     }

     void setAddress(address a)//setting address
     {
         setaddress = a;
     }
     void setdepart(string dep)
     {
         department = dep;

     }
     void calc(float sum ,float avg)
     {
         summarks = sum;
         avgmarks = avg;

     }
     void print()// function to print the details of a student
     {
         cout << "Name: " <<full_name <<"\t Roll number: "<<roll_no<< "\t "<<endl;
         cout << "Department: "<<department<<endl;
         cout << "Marks of subjects: ";
         for (int k = 0; k < num_subject; k++)
         {
             cout << Marks[k] << "  ";
         }

         cout << "\t Total percentage: " << avgmarks<<"\t" ;
         cout << "The grade is: ";
         if (avgmarks < 50)//printing the grade of each student
             cout << "F"<<endl;
         else if ( avgmarks < 65)
             cout << "D" << endl;
         else if ( avgmarks < 75)
             cout << "C" << endl;
         else if ( avgmarks < 85)
             cout << "B" << endl;
         else
             cout << "A" << endl;
         cout << "The address is: "<<setaddress.resarea<<"   "<<setaddress.city;
         cout << "\tThe zip code: "<<setaddress.zip<<endl;
         return;
     }
     // friend functions to use the functions in the class and the members
     friend void insert();
     friend void display();
     friend void edit();
     friend void search();
     friend void calculate();
 };
 student s[100]; //declaring an array of objects
 int i; //global variable used as a counter for the array of objects

 void insert() // function to add a new student
 {
     begin:
      cout << "Enter the first name and last name \n";
      string f, l;
      cin >> f >> l;
      s[i].setname(f, l);//setting the name in the array of objects
      again:
      cout << "Enter the roll number\n";
      int r;
      cin >> r;
      /*this for loop is repeated in the code it search for the require roll number and when
      it finds it it run the function but if not found it asks for another number through switch case*/
      for (int k = 0; k < 100; k++)
      {
          if (r == s[k].roll_no)
          {
              cout << "This roll number already exists choose another one\n";
              goto again;
          }
          s[i].setroll(r);
          cout << "Enter the address residential area,city,zip code \n";
          student::address area;
          cin >> area.resarea >> area.city >> area.zip;
          s[i].setAddress(area);
          cout << "Enter the department\n";
          string dept;
          cin >> dept;
          s[i].setdepart(dept);
          cout << "Enter the number of subjects \n";
          int num;
          cin >> num;
          int score[20];
          cout << "Enter the marks of the subjects\n";
          int sum = 0;
          for (int z = 0; z < num; z++)
          {
              cin >> score[z];
              sum += score[z];
          }
          float avg = sum / num;
          s[i].calc(sum, avg);
          s[i].setSubject(num);
          s[i].setmarks(score);
          cout << "To enter another student press 1 to exit press 0\n";
          int x;
          again2:
          cin >> x;
          switch (x)
          {
          case 0:
              goto end;
              break;
          case 1:
              i++;
              goto begin;
          default:
              cout << "Enter the right command please\n";
              goto again2;
          }
      }
       end:
       i++;
  }
 void search() // function to search for a student using name or roll number
 {
     cout << "To search by roll number press 1 to search by name press 2\n";
     int m;
     bool flag = 1;
     cin >> m;
     switch (m) {
     case 1:
         cout << "Enter roll number of the student you want to find \n";
         int test;
         cin >> test;
         for (int k = 0; k < 100; k++)
         {
             if (test == s[k].roll_no)
             {
                 flag = 0;
                 cout << "The student is found \n";

             }
         }
         if (flag)
             cout << "The student you are searching for is not found\n";
         break;
      case 2:
         cout << "Enter the first name and the last name of the student you want to find \n";
         cout << "N.B. First letter in each name must be a capital letter\n";
         string who1,who2;
         cin >> who1>>who2;
         for (int k = 0; k < 100; k++)
         {
             if (who1== s[k].first_name && who2==s[k].second_name)
             {
                 flag = 0;
                 cout << "The student is found \n";

             }
         }
         if (flag)
             cout << "The student you are searching for is not found\n";
         break;
     }
 }
 void display() //function to display the data of a student using the roll number
 {
     Begin:
     cout << "Enter roll number of the student you want to display \n";
     int test;
     cin >> test;
     bool flag=1;
     for (int k = 0; k < 100; k++)
     {
         if (test == s[k].roll_no)
         {
             flag = 0;
             s[k].print();//calling the member function through the global array of objects s
             break;
         }
     }
         if (flag)
         {
             cout << "The student you want to display is not found\n";
         }
         cout << "If you want to display another student press 1 to exit press 0\n";
         int x;
         again:
         cin >> x;
         switch (x)
         {
         case 0:
             break;
         case 1:
             goto Begin;
         default:
         cout << "Enter the right command please\n";
         goto again;
         }

 }

 void edit() // function to edit the data of a student
 {
     /*The function allow the user to edit each member of the student separately*/

     cout << "Enter roll number of the student you want to edit \n";
     int test;
     cin >> test;
     int k;//declaring k out of the loop to use it in the function
     bool flag = 1;
     for (k = 0; k < 100; k++)//searching for the student
     {
         if (test == s[k].roll_no)
             flag = 0;
             break;
     }
     if (flag)
     {
         cout << "The student you want to edit is not found\n";
         return;
     }
     Begin:
     cout << "To edit the name press 1 to edit the roll number press 2 \nto edit the address press 3 to edit the department press 4 \nto edit the marks of the students press 5\n";
     int x;
     cin >> x;
     int r;
     string f, l;
     student::address area;
     string dept;
     int num;
     int score[20];
     int sum = 0;
     float avg;
     switch (x)
     {
      case 1:
         cout << "Enter the first name and last name \n";
         cin >> f >> l;
         s[k].setname(f, l);
         break;
      case 2:
          again:
          cout << "Enter the roll number\n";
          cin >> r;
          for (int k = 0; k < 100; k++)
          {
              if (r == s[k].roll_no)
              {
                  cout << "This roll number already exists choose another one\n";
                  goto again;
              }
          }
          s[k].setroll(r);
          break;
      case 3:
          cout << "Enter the address residential area,city,zip code \n";
          cin >> area.resarea >> area.city >> area.zip;
          s[k].setAddress(area);
          break;
      case 4:
          cout << "Enter the department\n";

          cin >> dept;
          s[k].setdepart(dept);
          break;
      case 5:
          cout << "Enter the number of subjects \n";
          cin >> num;

          cout << "Enter the marks of the subjects\n";

          for (int z = 0; z < num; z++)
          {
              cin >> score[z];
              sum += score[z];
          }
               avg = sum / num;
              s[k].calc(sum, avg);
              s[k].setSubject(num);
              s[k].setmarks(score);
              break;
      default:
          cout << "Enter the right command please\n";
     }

     cout << "If you want to edit another thing press 1 to exit press 0\n";
     Begin4:
     cin >> x;
     switch (x)
     {
     case 0:
         break;
     case 1:
         goto Begin;
         break;
     default:
         cout << "Enter the right command please\n";
         goto Begin4;
     }
     cout << "The edit is successful\n";

 }
 void calculate() //function to calculate total marks, total percentage and grade of a student
 {
   Begin:
     cout << "Enter roll number of the student you want to calculate his total marks  \n";
     int test;
     cin >> test;
     bool flag = 1;
     for (int k = 0; k < 100; k++)//for loop testing the array to find the student
     {
         if (test == s[k].roll_no)
         {
             flag = 0;
             cout << "The total marks:"<<s[k].summarks<<"\t The total percentage: "<<s[k].avgmarks<<"\t";
             cout << "The grade is ";
             if (s[k].avgmarks < 50)
                 cout << "F" << endl;
             else if (s[k].avgmarks < 65)
                 cout << "D" << endl;
             else if (s[k].avgmarks < 75)
                 cout << "C" << endl;
             else if (s[k].avgmarks < 85)
                 cout << "B" << endl;
             else
                 cout << "A" << endl;
             break;
         }
     }
     if (flag)
     {
         cout << "The student you are searching for is not found\n";
     }
     cout << "If you want to calculate the marks of another student press 1 to exit press 0\n";
     int x;
     Begin5:
     cin >> x;
     switch (x)
     {
     case 0:
         break;
     case 1:
         goto Begin;
     default:
        cout << "Enter the right command please\n";
         goto Begin5;
     }

 }

 int main()
 {
     /* declaring some variables to store the data from the file
     s1 for first name
     s12 for second name
     s2 for roll number
     s3 s4 s5 for address
     s6 for department
     n for the number of subjects */


     string s1,s12,s3,s4,s5,s6;
     int scores[20];
     int n,s2;
     fstream f1;
     f1.open("why.txt");

     student::address d;
      i = 0;
     while (f1)
     {
             f1 >>s1>>s12>>s2>>s3>>s4>>s5>>s6 >>n; //reading data from file
             float sum = 0;
             for (int j = 0; j < n; j++)//for loop to read the marks
             {
                 f1 >> scores[j];
                 sum += scores[j];
             }
             d.city = s4;
             d.resarea = s3;
             d.zip = s5;
             float avg = sum / n;
             //calling setter functions
             s[i].setname(s1,s12);
             s[i].setroll(s2);
             s[i].setSubject(n);
             s[i].setmarks(scores);
             s[i].setAddress(d);
             s[i].setdepart(s6);
             s[i].calc(sum,avg);
             i++;

             if (f1.eof())//when the text ends the loop breaks
                  break;
     }

     // The main menu of the program
     start:
     cout << "The main menu\nEnter the command number \n1) Display student's data \n";
     cout << "2) Insert new student's data\n3) Search for student by roll number or name \n4) Edit student's data\n";
     cout << "5) Calculate the total marks and percentage\n";
     int y;
     Begin:
     cin >> y;
     switch (y)//getting the command from the user and calling the required function
     {
     case 1:
         display();
         break;
     case 2:
         insert();
         break;
     case 3:
         search();
         break;
     case 4:
         edit();
         break;
     case 5:
         calculate();
         break;
     default:
         cout << "Enter the right command please\n";
         goto Begin;

     }
     cout << "To get back to the main main menu press 1 to exit program press 0\n";
     int com;
     begin3:
     cin >> com;
     switch (com)
     {
     case 0:
         break;
     case 1:
         goto start;
     default:
         cout << "Enter the right command please\n";
         goto begin3;
     }
     f1.close();
     return 0;
 }




