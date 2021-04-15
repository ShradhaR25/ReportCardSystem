

//**************************************************************
//                   HEADER FILE USED IN THIS PROJECT
//***************************************************************
#include<iostream>
#include<fstream>
#include<iomanip>


using namespace std;


//**************************************************************
//                   CLASS USED IN THIS PROJECT
//***************************************************************



class result
{
int rollno;
char grade;
int physics, chemistry, maths, english, computer;
string name;
float percent;

void gradecalc(); //function to calculate grade
public:
	
    void getdata(); //to get data of every student
    void showdata();//to display data of every student
    void showtable(); //to show the result of class in tabular form
	int getroll(){
		return rollno;
	}
	float getperc()
	{
		return percent;
	}
	
};
void result::gradecalc()
{
	percent=(physics+chemistry+maths+english+computer)/5.0;
	if(percent>=90)
		grade='A';
	else if(percent>=70&&percent<90)
		grade='B';
	else if(percent>=50&&percent<70)
		grade='C';
	else if(percent>=40&&percent<50)
	    grade='E';
	else
		grade='F';
}
void result::getdata()
{
    cout<<"\nEnter The roll number of student ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student ";
	cin>>name;
	cout<<"\nEnter The marks in physics  : ";
	cin>>physics;
	cout<<"\nEnter The marks in chemistry  : ";
	cin>>chemistry;
	cout<<"\nEnter The marks in maths : ";
	cin>>maths;
	cout<<"\nEnter The marks in english : ";
	cin>>english;
	cout<<"\nEnter The marks in computer science  : ";
	cin>>computer;
	gradecalc();
	
}
void result::showdata()
{
    cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in Physics : "<<physics;
	cout<<"\nMarks in Chemistry : "<<chemistry;
	cout<<"\nMarks in Maths : "<<maths;
	cout<<"\nMarks in English : "<<english;
	cout<<"\nMarks in Computer Science :"<<computer;
	cout<<"\nPercentage of student is  :"<<percent;
	cout<<"\nGrade of student is :"<<grade;
}
void result::showtable()
{
	cout<<"\n"<< rollno<<setw(6)<<" "<<name<<setw(10)<<physics<<setw(4)<<chemistry<<setw(4)<<maths<<setw(4)
		<<english<<setw(4)<<computer<<setw(8)<<percent<<setw(6)<<grade;
}
 void add_student();  //write the record in binary file
 void display_class();//read all records from binary file
 void display_single(int n);//accept rollno and read record from binary file
 void modify_student(int n);//accept rollno and update record of binary file
 void delete_student(int n);//accept rollno and delete selected records from binary file
 void teacher_menu();//display teacher's entry menu on screen
 void student_menu();//display student's result menu on screen
 void class_result();//display all records in tabular format from binary file
//  void sortfile();//sort the file on the basis of percent obtained by each student and thus provide rank

int main()
{	//clrscr();
	char ch;
      cout<<"\n\n\n\t\t  STUDENT";
    	cout<<"\n\n\t\tREPORT CARD";
	    cout<<"\n\n\t\t  PROJECT";
    	cout<<"\n\n\n\tMADE BY : SHRADHA RANJAN";
		cout<<"\n\n\n";
	    cout<<"\n\t INDIRA GANDHI DELHI TECHNICAL UNIVERSITY FOR WOMEN";
		do
		{cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. STUDENT RESULT MENU";
		cout<<"\n\n\t02. TEACHER MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		switch(ch)
		{
			case '1': student_menu();
				break;
			case '2': teacher_menu();
				break;
			case '3':
				break;
			default :cout<<"\a";
		}

		}while(ch!='3');
    return 0;
}
//**************************************************************
//    	function to display student result menu
//***************************************************************
void student_menu()
{
	char ch;
	int rno;
	
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>ch;
	
	switch(ch)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
				display_single(rno); break;
	case '3' :	break;
	default:	cout<<"\a";
	}
}
//**************************************************************
//    	TEACHERS'S MENU FUNCTION
//***************************************************************

void teacher_menu()//menu for the teachers to enter options of their choice and perform various operations
{
	char ch;
	int num;
	
	cout<<"\n\n\n\tTEACHER MENU";
	cout<<"\n\n\t1.CREATE A NEW STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH FOR A STUDENT RECORD BY ROLL NUMBER ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
	cin>>ch;
	
	switch(ch)
	{
	case '1':	add_student();
				 break;
	case '2':	 display_class(); 	
				break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; 
				cin>>num;
				display_single(num); 
				break;
	
	case '4':	cout<<"\n\n\tPlease Enter The roll number ";
				 cin>>num;
				modify_student(num);
					break;
	case '5':	cout<<"\n\n\tPlease Enter The roll number "; 	
				cin>>num;
				delete_student(num);	
				break;
	case '6':	break;
	default:	cout<<"\a"; teacher_menu();
	}
}
//*************************************************************
//    	function to add the record of a student
//**************************************************************
void add_student()
{

	result r1;
	ofstream filout("marks.dat",ios::binary|ios::app);
	r1.getdata();
	filout.write((char *)&r1,sizeof(r1));
	filout.close();
	cout<<"\nRECORD HAS BEEN CREATED";
	cin.ignore();
	cin.get();
}
//**************************************************************
//    	function to read the records and contents of the given file
//***************************************************************

void display_class()
{
	result r2;
	ifstream filein;
	filein.open("marks.dat",ios::binary);
	if(!filein)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(filein.read((char*)&r2,sizeof(r2)))
	{
		r2.showdata();
		cout<<"\n\n====================================\n";
	}
	filein.close();
	cin.ignore();
	cin.get();
}
////////////////////////////////////////////////////////////////////////////////
//**************************************************************
//    	function to read record of a student with the help of roll number
//*****************************************************
void display_single(int n)
{	int flag=0;
	result r2;
	ifstream filein("marks.dat",ios::binary);
	if(!filein)
	{
		cout<<"\nFILE COULD NOT BE OPENED ...PRESS ANY KEY";
	}
	
	while (!filein.eof())
	
	
	{	
		filein.read((char*)&r2,sizeof(r2));

		if(r2.getroll()==n)
		{
	  		 r2.showdata();
			 flag=1;
		}
	}
		filein.close();
		if(flag==0)
		{
			cout<<"\n\nRECORD DOES NOT EXIST";
		}
		
		cin.get();
		cin.ignore();
	}
/////////////////////////////////////////////////////////////////////////////////////////
//**************************************************************
//    	function to change the  record of a student
//***************************************************************
	void modify_student
	(int n)
	{
		result r4;
		int found=0;
		long pos;
		fstream Filein;
	Filein.open("marks.dat",ios::binary|ios::in|ios::out);
	if(!Filein)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return ;
	}
	while(!Filein.eof())
	{
		pos=Filein.tellg();
		Filein.read((char*)&r4,sizeof(r4));
		if(r4.getroll()==n)
		{
		cout<<"\n\n\tENTER THE NEW DETAILS OF STUDENT";
			r4.getdata();
			Filein.seekg(pos);
			Filein.write((char*)&r4,sizeof(r4));
			cout<<"\nRECORD UPDATED";
			found=1;


		}
	}	Filein.close();
	if(found==0)
	{
		cout<<"\nrecord not found";
	}
	
	cin.ignore();
	cin.get();



	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**************************************************************
//    	function to delete the record of a particular student 
//***************************************************************
	void delete_student(int n)
	{
		result r5;
	ifstream filein;
	filein.open("marks.dat",ios::binary);
	if(!filein)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream fileout;
	fileout.open("Temp.dat",ios::out);
	filein.seekg(0,ios::beg);
	while(filein.read((char*)&r5, sizeof(r5)))
	{
		if(r5.getroll()!=n)
		{
			fileout.write((char*)&r5, sizeof(r5));
		}
	}
	fileout.close();
	filein.close();
	remove("marks.dat");
	rename("Temp.dat","marks.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//**************************************************************
//    	function to display all students grade report in tabular form
//***************************************************************
void class_result()
{
	result st;
	ifstream inFile;
	inFile.open("marks.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"==========================================================\n";
	cout<<"R.No       Name        P   C   M   E   CS   %age   Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read((char*) (&st), sizeof(st)))
	{
		st.showtable();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}




//**************************************************************
//    		THE END OF PROJECT
//***********************************************************
