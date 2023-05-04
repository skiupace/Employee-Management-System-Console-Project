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
	void TakeIdNumberAndExitFunction();
	void SearchForEmployeeByFiltring();
	void ViewAllEmployeesInfo();
	void DeletingEmployeeInfo();

	template<class T> // <-- A template function to take input from char and int
	T InputAndErrorHanlder(T);

private:
	// Properties
	std::vector<std::string> EmployeeFullName,
							 EmployeeAddress;

	std::vector<int> EmployeeNumber, 
					 EmployeeAge, 
					 EmployeePhoneNumber, 
					 EmployeeManagmentNumber;

	struct variables { // <-- A structure with all most used variables

		char conform{};
		bool InfoExist = false;

		std::string EmployeeFullName, EmployeeAddress;
		int EmployeeNumber{}, EmployeeAge{}, EmployeePhoneNumber{},
			EmployeeManagmentNumber{}, IdNumber{}, choice{};
	} var;
};