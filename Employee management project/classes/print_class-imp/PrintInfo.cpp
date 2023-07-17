#include <iostream>
#include <vector>
#include "../print_class-imp/PrintInfo.h"
#include "../employee's_data_class-imp/EmployeesDataClass.h"

void PrintInfo::ViewMainMenu() const {
	std::cout << "--- Employee Management System ---\n\n";
	std::cout << "1- Hire New Employee\n";
	std::cout << "2- Updating Uncomplete Employee Info\n";
	std::cout << "3- Search For Employee By Filters\n";
	std::cout << "4- View All Employees Info\n";
	std::cout << "5- Deleting Employee Info\n";
	std::cout << "6- About the program\n";
	std::cout << "7- Exit the program\n\n";
	std::cout << "Enter your choice -> ";
}

void PrintInfo::ViewUpdatingOptions() const {
	std::cout << "--- Updating Uncomplete Employee Info ---\n\n";
	std::cout << "1- Update Employee Full Name\n";
	std::cout << "2- Update Employee Age\n";
	std::cout << "3- Update Employee Phone Number\n";
	std::cout << "4- Update Employee Managment Number\n";
	std::cout << "5- Update Employee Address\n";
	std::cout << "6- Return to the main menu\n\n";
	std::cout << "Enter your choice -> ";
}

void PrintInfo::ViewSearchingOptions() const {
	std::cout << "--- Search For Employee By Filters ---\n\n";
	std::cout << "1- Search By Employee Number (ID)\n";
	std::cout << "2- Search By Employee Full Name\n";
	std::cout << "3- Search By Employee Managment Number\n";
	std::cout << "4- Search By Employee Address\n";
	std::cout << "5- Return to the main menu\n\n";
	std::cout << "Enter your choice -> ";
}

void PrintInfo::ViewAboutProgramMenu() const {
	std::cout << "      --- About the program ---\n\n\n";
	std::cout << "*************************************\n";
	std::cout << "*                                   *\n";
	std::cout << "* developed by : Tomino(@tomino47)  *\n";
	std::cout << "*                                   *\n";
	std::cout << "*************************************\n\n\n";
}

void PrintInfo::ViewAllEmployeesInfo(EmployeesData& obj) const {

	std::cout << "--- View All Employees Info ---\n\n";

	if (obj.isEmpty()) // <-- Check if the vector empty or not
		std::cout << "It's empty you didn't add anything ...\n";

	else {
		for (int i = 0; i < obj.EmployeeNumber.size(); i++) {
			std::cout << "      ==== Work Info ====\n\n";
			std::cout << "      Id : " << obj.EmployeeNumber.at(i) << '\n';
			std::cout << "      ManagmentNo. : " << obj.EmployeeManagmentNumber.at(i) << "\n\n";

			std::cout << "      ==== Personal Info ====\n\n";
			std::cout << "      Name : " << obj.EmployeeFullName.at(i) << '\n';
			std::cout << "      Age : " << obj.EmployeeAge.at(i) << "\n";
			std::cout << "      Address : " << obj.EmployeeAddress.at(i) << "\n\n";

			std::cout << "      ==== Contact Info ====\n\n";
			std::cout << "      Phone : " << obj.EmployeePhoneNumber.at(i) << '\n';
			std::cout << "__________________________________\n\n";
		}
	}
}