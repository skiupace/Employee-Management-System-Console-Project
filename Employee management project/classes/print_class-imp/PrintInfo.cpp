#include <iostream>
#include <vector>
#include "../print_class-imp/PrintInfo.hpp"
#include "../employee's_data_class-imp/EmployeesDataClass.hpp"

void PrintInfo::ViewMainMenu() {
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

void PrintInfo::ViewUpdatingOptions() {
	std::cout << "--- Updating Uncomplete Employee Info ---\n\n";
	std::cout << "1- Update Employee Full Name\n";
	std::cout << "2- Update Employee Age\n";
	std::cout << "3- Update Employee Phone Number\n";
	std::cout << "4- Update Employee Managment Number\n";
	std::cout << "5- Update Employee Address\n";
	std::cout << "6- Return to the main menu\n\n";
	std::cout << "Enter your choice -> ";
}

void PrintInfo::ViewSearchingOptions() {
	std::cout << "--- Search For Employee By Filters ---\n\n";
	std::cout << "1- Search By Employee Number (ID)\n";
	std::cout << "2- Search By Employee Full Name\n";
	std::cout << "3- Search By Employee Managment Number\n";
	std::cout << "4- Search By Employee Address\n";
	std::cout << "5- Return to the main menu\n\n";
	std::cout << "Enter your choice -> ";
}

void PrintInfo::ViewAboutProgramMenu() {
	std::cout << "      --- About the program ---\n\n\n";
	std::cout << "*************************************\n";
	std::cout << "*                                   *\n";
	std::cout << "* developed by : Tomino(@tomino47)  *\n";
	std::cout << "*                                   *\n";
	std::cout << "*************************************\n\n\n";
}

void PrintInfo::PrintErrorMessage() {
	std::cout << "Error: invalid input, please try again ...\n";
}

void PrintInfo::ViewAllEmployeesInfo(const EmployeesData& employee_info) noexcept {

	std::cout << "--- View All Employees Info ---\n\n";
	if (employee_info.isEmpty()) // <-- Check if the vector empty or not
		std::cout << "It's empty you didn't add anything ...\n";

	else {
		for (int i = 0; i < employee_info.EmployeeNumber.size(); i++) {
			std::cout << "==== Work Info ====\n\n";
			std::cout << "Id : " << employee_info.EmployeeNumber.at(i) << '\n';
			std::cout << "ManagmentNo. : " << employee_info.EmployeeManagementNumber.at(i) << "\n\n";

			std::cout << "==== Personal Info ====\n\n";
			std::cout << "Name : " << employee_info.EmployeeFullName.at(i) << '\n';
			std::cout << "Age : " << employee_info.EmployeeAge.at(i) << "\n";
			std::cout << "Address : " << employee_info.EmployeeAddress.at(i) << "\n\n";

			std::cout << "==== Contact Info ====\n\n";
			std::cout << "Phone Number : " << employee_info.EmployeePhoneNumber.at(i) << "\n\n";
			std::cout << std::string(34, '-') << "\n\n";
		}
	}
}