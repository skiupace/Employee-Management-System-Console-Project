#pragma once
#include <vector>

// Header
class Employees {
public:
	// Methods
	bool isEmpty();
	void ViewMainMenu();
	void ViewAboutProgramMenu();
	void ViewUpdatingOptions();
	void ViewSearchingOptions();
	void HireNewEmployee();
	void UpdatingEmployeesInfo();
	void SearchForEmployeeByFiltring();
	void ViewAllEmployeesInfo();
	void DeletingEmployeeInfo();

	template<class T> // <-- A template function to take input from char and int
	int InputAndErrorHanlder(T);

	struct variables { // <-- A structure with all most used variables
		char conform{};
		std::string EmployeeFullName, EmployeeAddress;
		int EmployeeNumber = 1, EmployeeAge{}, EmployeePhoneNumber{}, 
			EmployeeManagmentNumber{}, IdNumber{}, choice{};
	} var;

private:
	// Properties
	std::vector<std::string> EmployeeFullName,
							 EmployeeAddress;

	std::vector<int> EmployeeNumber, 
					 EmployeeAge, 
					 EmployeePhoneNumber, 
					 EmployeeManagmentNumber;
};