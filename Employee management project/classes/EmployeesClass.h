#pragma once
#include <vector>

class Employees {
public:
	const bool isEmpty() const;
	void ViewMainMenu();
	void ViewAboutProgramMenu();
	void ViewUpdatingOptions();
	void ViewSearchingOptions();
	void HireNewEmployee();
	void UpdatingEmployeesInfo();
	int TakeIdNumberAndExitFunction();
	void SearchForEmployeeByFiltring();
	void ViewAllEmployeesInfo() const;
	void DeletingEmployeeInfo();

	template<class T> // <-- A template function to take input from char and int
	T InputAndErrorHanlder(T);

private:
	std::vector<std::string> EmployeeFullName,
							 EmployeeAddress;

	std::vector<int> EmployeeNumber, 
					 EmployeeAge, 
					 EmployeePhoneNumber, 
					 EmployeeManagmentNumber;
};

#ifndef variables
#define variables

struct variables { // <-- A structure with all most used variables

	char conform{};
	bool InfoExist;

	std::string EmployeeFullName, EmployeeAddress;
	int EmployeeNumber{}, EmployeeAge{}, EmployeePhoneNumber{},
		EmployeeManagmentNumber{}, IdNumber{}, choice{}, index{};
} var;

#endif // !variables