#include "stdafx.h"
#include "Student.h"

using namespace std;

int main()
{
	CStudent m_StudentArray[10];
	int iNoOfStudents = 0;
	int choice = 0;
	char YesOrNo;
	char strFileName[25];

	cout << "*************Student Database***************\n";
	cout << "Please Enter Number of students (max 10):- " << endl;
	cin >> iNoOfStudents;

	if (iNoOfStudents > 10)
	{
		cout << "Maximum limit is 10 students!\n";
		return 0;
	}

	// Data Input
	for (int i = 0; i < iNoOfStudents; i++)
	{
		char strName[25];
		CStudent Student;

		cout << "\nPlease Enter the student Name:- ";
		cin >> strName;
		Student.m_strName = strName;

		cout << "Please Enter the student Age:- ";
		cin >> Student.m_iAge;

		m_StudentArray[i] = Student;
	}


	do
	{
		cout << "\n\n************* MENU *************\n";
		cout << "1. Show Students\n";
		cout << "2. Delete Student\n";
		cout << "3. Save to File\n";
		cout << "4. Exit\n";
		cout << "Enter choice: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nIndex\tName\tAge\n";
			cout << "----------------------\n";

			for (int i = 0; i < iNoOfStudents; i++)
			{
				cout << i << "\t"
					<< (LPCTSTR)m_StudentArray[i].m_strName << "\t"
					<< m_StudentArray[i].m_iAge << endl;
			}
			break;

		case 2:
		{
			int index;

			cout << "\nCurrent Students:\n";
			for (int i = 0; i < iNoOfStudents; i++)
			{
				cout << i << " - " << (LPCTSTR)m_StudentArray[i].m_strName << endl;
			}

			cout << "\nEnter index to delete: ";
			cin >> index;

			if (index >= 0 && index < iNoOfStudents)
			{
				for (int i = index; i < iNoOfStudents - 1; i++)
				{
					m_StudentArray[i] = m_StudentArray[i + 1];
				}

				iNoOfStudents--;

				cout << "\nStudent deleted successfully!\n";
			}
			else
			{
				cout << "\nInvalid index!\n";
			}
			break;
		}

		case 3:
			cout << "\nDo you want to save (y/n):- ";
			cin >> YesOrNo;

			if (YesOrNo == 'Y' || YesOrNo == 'y')
			{
				cout << "Enter file name:- ";
				cin >> strFileName;

				CStdioFile file;

				file.Open(strFileName,
					CFile::modeCreate |
					CFile::modeWrite |
					CFile::shareExclusive);

				for (int i = 0; i < iNoOfStudents; i++)
				{

					CString data;
					data.Format("%s,%d\n", m_StudentArray[i].m_strName,
						m_StudentArray[i].m_iAge);

					file.WriteString(data);
				}

				file.Close();

				cout << "\nData saved successfully!\n";
			}
			break;

		case 4:
			cout << "\nExiting...\n";
			break;

		default:
			cout << "\nInvalid choice!\n";
			break;
		}

	} while (choice != 4);

	_getch();
	return 0;
}