


#include<iostream>
#include<fstream>
using namespace std;

class Helper
{
public:
	static int StringLength(char* str)
	{
		int count = 0;
		if (str != 0)
		{
			for (; str[count] != '\0'; count++) {}
		}
		return count;
	}
	static void StringCopy(char*& dest, char*& src) {
		//Deep Copies src into dest.
		int count = StringLength(src);
		char* temp = dest;
		dest = new char[count + 1];
		if (src != 0)
		{
			for (int i = 0; i < count; i++)
			{
				dest[i] = src[i];
			}
			dest[count] = '\0';
		}
		else
		{
			cout << "\nCan't copy a null string.\n";
		}
		delete[] temp;
		temp = 0;
	}
	static char* GetStringFromBuffer(char* str)
	{
		char* string = 0;
		string = new char[StringLength(str) + 1];
		StringCopy(string, str);
		return string;
	}
	static void lower(char* str)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}
		}
	}
	static bool Exist(char* roll, char* str)
	{
		lower(roll);
		lower(str);

		bool flag = false;
		for (int i = 0, j = 0; roll[i] != '\0' && str[j] != '\0'; i++)
		{
			j = 0;
			if (roll[i] == str[j])
			{
				i++; j++;
				for (; (roll[i] != '\0') && (str[j] != '\0'); i++, j++)
				{
					if (roll[i] == str[j] && (roll[i - 1] == str[j - 1]))
					{

						flag = true;

					}
					else
					{
						flag = false;
						break;
					}
				}
				if (j == Helper::StringLength(str))
				{
					return true;
				}
				else
				{
					flag = false;
				}
			}
		}
		return flag;
	}


	static bool* Exists(char* fname, char* lname, char* rollNo, char* str)
	{
		lower(fname);
		lower(lname);
		lower(str);

		bool* flag = new bool[3];
		flag[0] = false;
		flag[1] = false;

		for (int k = 0, j = 0; str[j] != '\0' && fname[k] != '\0'; k++)
		{
			j = 0;
			if (fname[k] == str[j])
			{
				k++, j++;
				for (; fname[k] != '\0' && str[j] != '\0'; k++, j++)
				{
					if (fname[k] == str[j] && (fname[k - 1] == str[j - 1]))
					{
						flag[0] = true;
					}
					else
					{
						flag[0] = false;
						break;
					}
				}
				if (j == Helper::StringLength(str))
				{
					flag[0] = true;
					return flag;
				}
				else
				{
					flag[0] = false;
				}
			}
		}
		for (int l = 0, j = 0; str[j] != '\0' && lname[l] != '\0'; l++)
		{
			j = 0;
			if (lname[l] == str[j])
			{
				l++, j++;
				for (; lname[l] != '\0' && str[j] != '\0'; l++, j++)
				{
					if (lname[l] == str[j] && (lname[l - 1] == str[j - 1]))
					{
						continue;
					}
					else
					{
						flag[1] = false;
						break;
					}
				}
				if (j == Helper::StringLength(str))
				{
					flag[1] = true;
					return flag;
				}
				else
				{
					flag[1] = false;
				}
			}
		}
		flag[2] = Exist(rollNo, str);
		return flag;
	}

};
class EvalReport
{
private:
	char rollNo[9];
	char* fname;
	char* lname;
	int* quizMarks;
	int* assignmentMarks;
	int total;

	static int totalStudents;
	static int totalQuiz;
	static int totalAssignments;
	static int TotalMarks;
	static int* max;
	static int* min;
	static int* avg;
	static int* totalQuizMarks;
	static int* totalAssignmentMarks;


public:
	static void SetTotalQuizMarks(int*); //Sets the total Marks of each Quiz.
	static void SetTotalAssignmentMarks(int*); //Sets the total Marks of each Assignment.
	static void SetTotalStudents(int); //Sets the total Students Count.
	static void SetTotalQuizzes(int); //Sets the total Quizzes Count.
	static void SetTotalAssignments(int); //Sets the total Assignments Count.
	static void SetMax(int*); //Sets the Max Marks of each Quiz and Assignment.
	static void SetMin(int*); //Sets the Min Marks of each Quiz and Assignment
	static void SetAvg(int*); //Sets the Avg Marks of each Quiz and Assignment
	static void SetTotalMarks(int);



	static int GetTotalStudents();//Returns The Count of Total Students.
	static int GetTotalQuizzes();//Returns The Count of Total Quizzes.
	static int GetTotalAssignments();//Return The Count of Total Assignments.
	static int* GetMax(); //Return the pointer to the Array holding the maximum marks of each quiz and assignment.
	static int* GetMin(); //Return the pointer to the Array holding the minimum marks of each quiz and assignment.
	static int* GetAvg(); //Return the pointer to the Array holding the average marks of each quiz and assignment.
	static int* GetTotalAssignmentMarks(); //Return the pointer to the Array holding the Total Marks of Each Assignment.
	static int* GetTotalQuizMarks(); //Return the pointer to the Array holding the Total Marks of Each Quiz.
	static int GetTotalMarks();




	int* GetQuizMarks(); //Return the pointer to the Array holding the Obtained Marks of Each Quiz.
	int* GetAssMarks(); //Return the pointer to the Array holding the Obtained Marks of Each Assignment.
	char* GetFirstName(); //Return the pointer to the Array holding the First Name of a Student.
	char* GetLastName(); //Return the pointer to the Array holding the Last Name of a Student.
	int GetTotal(); //Return the pointer to the Array holding the Grand Total of a Student.
	char* GetRollNo(); //Return the pointer to the Array holding the RollNO of a Student.


	static void PrintStatistics(); //Prints the Statistics including Max, Min, Avg, Total of each Quiz and Assignment.
	static void PrintDetailedView(EvalReport* Student); //Prints the Statistics in a Flex Like Manner.
	static void DeallocateStaticMembers();
	void PrintAll(); //Prints all the information of a Student.
	void QuizMarksPrint(); //Prints The Marks of A quiz of a student.
	void AssignmentMarksPrint(); //Prints The Marks of A Assignment student.


	void ReadDataFromFile(ifstream& fin);

	EvalReport(); //Default Constructor
	EvalReport(const EvalReport&); //Copy Constructor
	EvalReport& operator=(const EvalReport); //Assignment Operator
	~EvalReport();//Destructor

};


EvalReport::EvalReport()
{
	rollNo[0] = '\0';
	fname = 0;
	lname = 0;
	quizMarks = { 0 };
	assignmentMarks = { 0 };
	total = 0;
}
EvalReport& EvalReport::operator=(const EvalReport rhs)
{
	for (int i = 0; i < 9; i++)
	{
		rollNo[i] = rhs.rollNo[i];
	}
	if (fname)
		delete[] fname;
	if (lname)
		delete[] lname;

	fname = Helper::GetStringFromBuffer(rhs.fname);
	lname = Helper::GetStringFromBuffer(rhs.lname);


	quizMarks = new int[totalQuiz];
	assignmentMarks = new int[totalAssignments];
	for (int i = 0; i < totalQuiz; i++)
	{
		quizMarks[i] = rhs.quizMarks[i];
	}
	for (int i = 0; i < totalAssignments; i++)
	{
		assignmentMarks[i] = rhs.assignmentMarks[i];
	}
	total = rhs.total;

	return *this;
}
EvalReport::EvalReport(const EvalReport& rhs)
{
	for (int i = 0; i < 9; i++)
	{
		rollNo[i] = rhs.rollNo[i];
	}



	fname = Helper::GetStringFromBuffer(rhs.fname);
	lname = Helper::GetStringFromBuffer(rhs.lname);


	quizMarks = new int[totalQuiz];
	assignmentMarks = new int[totalAssignments];
	for (int i = 0; i < totalQuiz; i++)
	{
		quizMarks[i] = rhs.quizMarks[i];
	}
	for (int i = 0; i < totalAssignments; i++)
	{
		assignmentMarks[i] = rhs.assignmentMarks[i];
	}
	total = rhs.total;

}
EvalReport::~EvalReport()
{
	if (fname)
		delete[] fname;
	if (lname)
		delete[] lname;
	if (quizMarks)
		delete[] quizMarks;
	if (assignmentMarks)
		delete[] assignmentMarks;
}

//Initializing Static Members.

int EvalReport::totalStudents = 0;
int EvalReport::totalQuiz = 0;
int EvalReport::totalAssignments = 0;
int* EvalReport::totalQuizMarks = 0;
int* EvalReport::totalAssignmentMarks = 0;
int EvalReport::TotalMarks = 0;
int* EvalReport::max = 0;
int* EvalReport::min = 0;
int* EvalReport::avg = 0;


//Defining Getters.


int	EvalReport::GetTotalStudents()
{
	return totalStudents;
}
int EvalReport::GetTotalQuizzes()
{
	return totalQuiz;
}
int EvalReport::GetTotalAssignments()
{
	return totalQuiz;

}
int* EvalReport::GetTotalAssignmentMarks()
{
	return totalAssignmentMarks;
}
int* EvalReport::GetTotalQuizMarks()
{
	return totalQuizMarks;
}
int* EvalReport::GetMax()
{
	return max;
}
int* EvalReport::GetMin()
{
	return min;
}
int* EvalReport::GetAvg()
{
	return avg;
}
int* EvalReport::GetQuizMarks()
{
	return quizMarks;
}
int* EvalReport::GetAssMarks()
{
	return assignmentMarks;
}
char* EvalReport::GetFirstName()
{
	return fname;
}
char* EvalReport::GetLastName()
{
	return lname;

}
int EvalReport::GetTotal()
{
	return total;
}
char* EvalReport::GetRollNo()
{
	return rollNo;
}
int EvalReport::GetTotalMarks()
{
	return TotalMarks;
}



//Defining Setters.

void EvalReport::SetTotalStudents(int num = 0)
{
	totalStudents = num;
}
void EvalReport::SetTotalQuizzes(int num = 0)
{
	totalQuiz = num;
}
void EvalReport::SetTotalAssignments(int num = 0)
{
	totalAssignments = num;
}
void EvalReport::SetTotalQuizMarks(int* arr = 0)
{
	totalQuizMarks = new int[totalQuiz];
	if (arr != 0)
	{
		for (int i = 0; i < totalQuiz; i++)
		{
			totalQuizMarks[i] = arr[i];
		}
	}
}
void EvalReport::SetTotalAssignmentMarks(int* arr = 0)
{
	totalAssignmentMarks = new int[totalAssignments];
	if (arr != 0)
	{
		for (int i = 0; i < totalAssignments; i++)
		{
			totalAssignmentMarks[i] = arr[i];
		}
	}
}
void EvalReport::SetMax(int* arr)
{
	if (max != 0)
		delete[] max;
	max = new int[totalQuiz + totalAssignments];
	if (arr != 0)
	{
		for (int i = 0; i < totalQuiz + totalAssignments; i++)
		{
			max[i] = arr[i];
		}
	}
}
void EvalReport::SetAvg(int* arr)
{
	if (avg != 0)
		delete[] avg;
	avg = new int[totalQuiz + totalAssignments];
	if (arr != 0)
	{
		for (int i = 0; i < totalQuiz + totalAssignments; i++)
		{
			avg[i] = arr[i];
		}
	}
}
void EvalReport::SetMin(int* arr)
{
	if (min != 0)
		delete[] min;
	min = new int[totalQuiz + totalAssignments];
	if (arr != 0)
	{
		for (int i = 0; i < totalQuiz + totalAssignments; i++)
		{
			min[i] = arr[i];
		}
	}
}
void EvalReport::SetTotalMarks(int num)
{
	TotalMarks = num;
}


//Additional Helper Functions.


void EvalReport::PrintStatistics()
{
	cout << "\n\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\n";

	cout << "Total:\t\t";
	for (int i = 0, j = 0; i < totalQuiz + totalAssignments; i++)
	{
		if (i < totalQuiz)
		{
			cout << totalQuizMarks[i] << "\t";
		}
		else
		{
			cout << totalAssignmentMarks[j] << "\t"; j++;
		}
	}
	cout << endl;

	cout << "Maximum:\t";
	for (int i = 0; i < totalQuiz + totalAssignments; i++)
		cout << max[i] << "\t";
	cout << endl;

	cout << "Minimum:\t";
	for (int i = 0; i < totalQuiz + totalAssignments; i++)
		cout << min[i] << "\t";
	cout << endl;

	cout << "Average:\t";
	for (int i = 0; i < totalQuiz + totalAssignments; i++)
		cout << avg[i] << "\t";
	cout << endl;


}
void EvalReport::ReadDataFromFile(ifstream& fin)
{
	char temp[20];

	fin >> rollNo;
	fin >> temp;
	fname = Helper::GetStringFromBuffer(temp);

	fin >> temp;
	lname = Helper::GetStringFromBuffer(temp);

	quizMarks = new int[totalQuiz];
	assignmentMarks = new int[totalAssignments];


	for (int i = 0; i < totalQuiz; i++)
	{
		fin >> quizMarks[i];
		total += quizMarks[i];
	}

	for (int i = 0; i < totalAssignments; i++)
	{
		fin >> assignmentMarks[i];
		total += assignmentMarks[i];
	}


}
void EvalReport::QuizMarksPrint()
{
	for (int i = 0; i < totalQuiz; i++)
	{
		cout << quizMarks[i] << "\t";
	}
}
void EvalReport::AssignmentMarksPrint()
{
	for (int i = 0; i < totalAssignments; i++)
	{
		cout << assignmentMarks[i] << "\t";
	}
}
void EvalReport::PrintAll()
{
	if (Helper::StringLength(lname) > 6 && Helper::StringLength(fname) > 6)
	{
		cout << rollNo << "\t" << fname << " " << lname << "\t";
	}
	else
	{
		cout << rollNo << "\t" << fname << " " << lname << "\t\t";
	}
	QuizMarksPrint();
	AssignmentMarksPrint();
	cout << total << endl;

}
int GetSearchCount(EvalReport*& list, char* str)
{
	int count = 0;
	int studentCount = EvalReport::GetTotalStudents();
	for (int i = 0; i < studentCount; i++)
	{
		int j = 0;
		char* fname = Helper::GetStringFromBuffer(list[i].GetFirstName());
		char* lname = Helper::GetStringFromBuffer(list[i].GetLastName());
		char* rollNo = Helper::GetStringFromBuffer(list[i].GetRollNo());

		bool* flag = Helper::Exists(fname, lname, rollNo, str);


		if (flag[0] == true || flag[1] == true || flag[2] == true)
		{
			count++;
		}
	}
	return count;
}
int GetRollCount(EvalReport*& list, char* str)
{
	int count = 0;
	int studentCount = EvalReport::GetTotalStudents();
	for (int i = 0; i < studentCount; i++)
	{
		int j = 0;
		char* roll = Helper::GetStringFromBuffer(list[i].GetRollNo());
		bool flag = Helper::Exist(roll, str);


		if (flag == true)
		{
			count++;
		}
	}
	return count;
}


EvalReport* ReadDataFromFile(const char* filename)
{
	ifstream input(filename);
	int studentCount = 0;
	input >> studentCount;
	EvalReport::SetTotalStudents(studentCount);

	int quizCount = 0;
	input >> quizCount;
	EvalReport::SetTotalQuizzes(quizCount);

	int assCount = 0;
	input >> assCount;
	EvalReport::SetTotalAssignments(assCount);



	int* totalQuizMarks = new int[quizCount];
	int* totalAssignmentMarks = new int[assCount];
	int totalMarks = 0;
	for (int i = 0; i < quizCount; i++)
	{
		input >> totalQuizMarks[i];
		totalMarks += totalQuizMarks[i];
	}
	EvalReport::SetTotalQuizMarks(totalQuizMarks);

	for (int i = 0; i < assCount; i++)
	{
		input >> totalAssignmentMarks[i];
		totalMarks += totalAssignmentMarks[i];
	}
	EvalReport::SetTotalMarks(totalMarks);
	EvalReport::SetTotalAssignmentMarks(totalAssignmentMarks);


	EvalReport* report = new EvalReport[studentCount];

	for (int i = 0; i < studentCount; i++)
	{
		report[i].ReadDataFromFile(input);
	}

	return report;
}

void UpdateStatistics(EvalReport*& list)
{
	int totalStudents = EvalReport::GetTotalStudents();
	int totalquizzes = EvalReport::GetTotalQuizzes();
	int totalAss = EvalReport::GetTotalAssignments();

	int* max = new int[totalAss + totalquizzes];
	int* Quizmin = new int[totalquizzes];
	Quizmin = list[0].GetQuizMarks();
	int* AssMin = new int[totalAss];
	AssMin = list[0].GetAssMarks();
	int* min = new int[totalAss + totalquizzes];

	int* QuizMarks = new int[totalquizzes];
	int* AssMarks = new int[totalAss];

	int* avg = new int[totalAss + totalquizzes];


	for (int j = 0, i = 0; j < totalquizzes + totalAss; j++)
	{
		max[j] = 0; avg[j] = 0;
		if (j < totalquizzes)
		{
			min[j] = Quizmin[j];
		}
		else
		{
			min[j] = AssMin[i];
			i++;
		}

	}

	int i = 0;
	for (; i < totalStudents; i++)
	{
		QuizMarks = list[i].GetQuizMarks();
		AssMarks = list[i].GetAssMarks();

		for (int j = 0, k = 0; j < totalquizzes + totalAss; j++)
		{
			if (j < totalquizzes)
			{
				if (max[j] < QuizMarks[j])
				{
					max[j] = QuizMarks[j];
				}
				if (min[j] > QuizMarks[j])
				{
					min[j] = QuizMarks[j];
				}
				avg[j] += QuizMarks[j];
			}
			else
			{
				if (max[j] < AssMarks[k])
				{
					max[j] = AssMarks[k];
				}
				if (min[j] > AssMarks[k])
				{
					min[j] = AssMarks[k];
				}
				avg[j] += AssMarks[k];
				k++;
			}
		}
	}
	for (int j = 0; j < totalquizzes + totalAss; j++)
	{
		avg[j] = avg[j] / totalStudents;
	}
	EvalReport::SetMax(max);
	EvalReport::SetMin(min);
	EvalReport::SetAvg(avg);

}

void PrintAll(EvalReport* list)
{
	int count = EvalReport::GetTotalStudents();
	cout << "\nRoll-NO\t\tName\t\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\tTotal\n\n";
	for (int i = 0; i < count; i++)
	{
		list[i].PrintAll();
	}
	cout << "\n\n";
}

EvalReport** SearchStudentsByKeyWord(EvalReport*& list, char* str, int& count)
{
	EvalReport** searchList = 0;
	count = GetSearchCount(list, str);

	int studentCount = EvalReport::GetTotalStudents();

	if (count > 0)
		searchList = new EvalReport * [count];
	{
		count = 0;
		for (int i = 0; i < studentCount; i++)
		{
			int j = 0;
			char* fname = Helper::GetStringFromBuffer(list[i].GetFirstName());
			char* lname = Helper::GetStringFromBuffer(list[i].GetLastName());
			char* rollNo = Helper::GetStringFromBuffer(list[i].GetRollNo());
			bool* flag = Helper::Exists(fname, lname, rollNo, str);


			if (flag[0] == true || flag[1] == true || flag[2] == true)
			{
				if (searchList)
				{
					searchList[count] = &list[i];
					count++;
				}
			}
			delete[] fname;
			fname = 0;
			delete[] lname;
			lname = 0;
			delete[] rollNo;
			rollNo = 0;
		}
	}
	return searchList;

}

void PrintAll(EvalReport** list, int count)
{
	cout << "\nRoll-NO\t\tName\t\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\tTotal\n\n";
	for (int i = 0; i < count; i++)
	{
		list[i]->PrintAll();
	}

}

EvalReport* SearchStudentsByRollNo(EvalReport*& list, char* rollNo)
{
	EvalReport* StudentPtr = 0;

	int studentCount = EvalReport::GetTotalStudents();

	for (int i = 0; i < studentCount; i++)
	{
		char* roll = Helper::GetStringFromBuffer(list[i].GetRollNo());
		bool flag = Helper::Exist(roll, rollNo);


		if (flag == true)
		{
			StudentPtr = &list[i];
			return StudentPtr;
		}
	}
	return StudentPtr;
}

void SortByTotal(EvalReport*& list)
{
	int studentCount = EvalReport::GetTotalStudents();
	for (int i = 0; i < studentCount - 1; i++)
	{
		for (int j = 0; j < studentCount - i - 1; j++)
		{
			if (list[j].GetTotal() < list[j + 1].GetTotal())
			{
				EvalReport temp;
				temp = (list[j]);
				list[j] = (list[j + 1]);
				list[j + 1] = (temp);

				/*EvalReport temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;*/

			}
		}
	}
}

void EvalReport::PrintDetailedView(EvalReport* Student)
{

	cout << "Name: " << Student->GetFirstName() << " " << Student->GetLastName();
	cout << "\nRollNo: " << Student->GetRollNo();
	cout << endl;

	cout << "\nQ#\tObtMarks\tTotalMarks\tAverage\t\tMaximum\t\tMinimum\n\n";
	int i = 0;
	for (; i < totalQuiz; i++)
	{
		cout << i + 1 << "\t   " << Student->quizMarks[i] << "\t\t    " << EvalReport::totalQuizMarks[i] << "\t\t   " << EvalReport::avg[i] << "\t\t  " << EvalReport::max[i] << "\t\t   " << EvalReport::min[i] << endl;
	}

	cout << "\nA#\tObtMarks\tTotalMarks\tAverage\t\tMaximum\t\tMinimum\n\n";
	for (int j = 0; j < totalAssignments; j++, i++)
	{
		cout << j + 1 << "\t   " << Student->assignmentMarks[j] << "\t\t    " << EvalReport::totalAssignmentMarks[j] << "\t\t   " << EvalReport::avg[i] << "\t\t  " << EvalReport::max[i] << "\t\t   " << EvalReport::min[i] << endl;
	}
	cout << "\nTotal: " << Student->GetTotal() << "/" << EvalReport::TotalMarks;
}

void EvalReport::DeallocateStaticMembers()
{
	if (max)
		delete[] max;
	if (min)
		delete[] min;
	if (avg)
		delete[] avg;
	if (totalAssignmentMarks)
		delete[] totalAssignmentMarks;
	if (totalQuizMarks)
		delete[] totalQuizMarks;
}

int main()
{
	EvalReport* List = ReadDataFromFile("gradesheet.txt");
	int studentCount = EvalReport::GetTotalStudents();


	UpdateStatistics(List);

	cout << "+-------------------------------------------------------------------------------------------------------------+\n";
	cout << "|\t\t\t\t\t\tStatistics\t\t\t\t\t\t      |\n";
	cout << "+-------------------------------------------------------------------------------------------------------------+\n";

	EvalReport::PrintStatistics();

	cout << "\n\n";

	cout << "+-------------------------------------------------------------------------------------------------------------+\n";
	cout << "|\t\t\t\t\t\tStudentsList\t\t\t\t\t\t      |\n";
	cout << "+-------------------------------------------------------------------------------------------------------------+\n";



	PrintAll(List);



	cout << "+-------------------------------------------------------------------------------------------------------------+\n";
	cout << "|\t\t\t\t\t     SearchingByKeyword \t\t\t\t\t      |\n";
	cout << "+-------------------------------------------------------------------------------------------------------------+\n";

	cout << "\n\n";
	char keyWord[20] = "ham";
	int count = 0;
	EvalReport** SearchList = SearchStudentsByKeyWord(List, keyWord, count);
	PrintAll(SearchList, count);
	cout << "\n\n";

	cout << "+-------------------------------------------------------------------------------------------------------------+\n";
	cout << "|\t\t\t\t\t    SearchingByRollNO\t\t\t\t\t\t      |\n";
	cout << "+-------------------------------------------------------------------------------------------------------------+\n";

	char rollNo[] = "15L-1234";
	EvalReport* StudentPtr = SearchStudentsByRollNo(List, rollNo);
	cout << "\n\nEnter Student Roll Number: " << rollNo << endl;

	if (StudentPtr != NULL)
	{
		EvalReport::PrintDetailedView(StudentPtr);
	}
	else
	{
		cout << "Student Not Found.\n";
	}

	cout << "\n";

	char rollNo1[9] = "15L-4023";
	StudentPtr = SearchStudentsByRollNo(List, rollNo1);
	cout << "\n\nEnter Student Roll Number: " << rollNo1 << endl;
	cout << "\n";

	if (StudentPtr != NULL)
	{
		EvalReport::PrintDetailedView(StudentPtr);
	}
	else
	{
		cout << "Student Not Found.\n";
	}



	cout << "\n\n";

	cout << "+-------------------------------------------------------------------------------------------------------------+\n";
	cout << "|\t\t\t\t\t    SortingListByTotal\t\t\t\t\t\t      |\n";
	cout << "+-------------------------------------------------------------------------------------------------------------+\n";

	SortByTotal(List);
	PrintAll(List);

	cout << "+-------------------------------------------------------------------------------------------------------------+\n";

	delete[] SearchList; //Only Deleting the pointers because the objects they are pointing to are going to be deleted in List's Deallocation.
	delete[] List;
	EvalReport::DeallocateStaticMembers();//Deallocation of Static Members.

}