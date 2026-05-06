#include "stdafx.h"
#include "Student.h"
#include <vector>

using namespace std;

int main()
{
	vector<CStudent> students;
	int choice = 0;
	char YesOrNo;
	char strFileName[25];

	cout << "*************Student Database***************\n";
	int n;
	cout << "Enter Number of students :";
	cin >> n;

	// Data Input
	for (int i = 0; i < n; i++)
	{
		char strName[25];
		CStudent Student;

		cout << "\nPlease Enter the student Name:- ";
		cin >> strName;
		Student.m_strName = strName;

		cout << "Please Enter the student Age:- ";
		cin >> Student.m_iAge;

		students.push_back(Student);
	}

	do
	{
		cout << "\n\n************* MENU *************\n";
		cout << "1. Show Students\n";
		cout << "2. Delete Student\n";
		cout << "3. Save to File\n";
		cout << "4.Load all Students\n";
		cout << "5. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nIndex\tName\tAge\n";
			cout << "----------------------\n";

			for (int i = 0; i < students.size(); i++)
			{
				cout << i << "\t"
					<< (LPCTSTR)students[i].m_strName << "\t"
					<< students[i].m_iAge << endl;
			}
			break;

		case 2:
		{
			int index;

			cout << "\nCurrent Students:\n";
			for (int i = 0; i < students.size(); i++)
			{
				cout << i << " - " << (LPCTSTR)students[i].m_strName << endl;
			}

			cout << "\nEnter index to delete: ";
			cin >> index;

			if (index >= 0 && index < students.size())
			{
				students.erase(students.begin() + index);
				cout << "\nStudent deleted successfully\n";
			}
			else
			{
				cout << "\nInvalid index\n";
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

				for (int i = 0; i < students.size(); i++)
				{
					CString data;
					data.Format("%s,%d\n", students[i].m_strName,
						students[i].m_iAge);

					file.WriteString(data);
				}

				file.Close();
				cout << "\nData saved successfully!\n";
			}
			break;
		case 4:
		{
			cout << "\n Enter file name to load :-";
			cin >> strFileName;
			CStdioFile file;
			if (!file.Open(strFileName, CFile::modeRead))
			{
				cout << "\nUnable to open file\n";
				break;
			}
			students.clear();
			CString line;
			while (file.ReadString(line))
			{
				int pos = line.Find(',');
				if (pos != -1)
				{
					CStudent Student;
					Student.m_strName = line.Left(pos);
					Student.m_iAge = _ttoi(line.Mid(pos + 1));
					students.push_back(Student);
				}
			}
			file.Close();
			cout << "\nAll students loaded successfully\n";
			break;
		}

		case 5:
			cout << "\nExiting...\n";
			break;

		default:
			cout << "\nInvalid choice!\n";
			break;
		}

	} while (choice != 5);

	_getch();
	return 0;
}