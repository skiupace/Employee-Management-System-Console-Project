#include <iostream>
#include <string>
#include "../search_class-imp/SearchForData.hpp"
#include "../app_variables-struct/VariablesStruct.hpp"
#include "../input_handler_class-imp/InputHandlerClass.hpp"
#include "../employee's_data_class-imp/EmployeesDataClass.hpp"

void SearchForData::search_by_employees_number(const EmployeesData& employee_info) noexcept {

	std::cout << "Enter Employee Id Number or 0 to return : ";
	InputHandler::InputAndErrorHanlder(var.IdNumber);

	if (var.IdNumber == 0)
		return;

	for (int i = 0; i < employee_info.EmployeeNumber.size(); ++i) {
		if (employee_info.EmployeeNumber.at(i) == var.IdNumber) {
			std::cout << "\n==== Work Info ====\n\n";
			std::cout << "Id : " << employee_info.EmployeeNumber.at(i) << '\n';
			std::cout << "ManagementNo. : " << employee_info.EmployeeManagementNumber.at(i) << "\n\n";

			std::cout << "==== Personal Info ====\n\n";
			std::cout << "Name : " << employee_info.EmployeeFullName.at(i) << '\n';
			std::cout << "Age : " << employee_info.EmployeeAge.at(i) << "\n";
			std::cout << "Address : " << employee_info.EmployeeAddress.at(i) << "\n\n";

			std::cout << "==== Contact Info ====\n\n";
			std::cout << "Phone Number : " << employee_info.EmployeePhoneNumber.at(i) << "\n\n";
			std::cout << std::string(34, '-') << '\n';
			var.InfoExist = true;
		}
	} employee_info.CheckIfDataExist(var.InfoExist);
}

void SearchForData::search_by_employees_name(const EmployeesData& employee_info) noexcept {

	std::cout << "Enter Employee Full Name or 0 to return : ";
	std::getline(std::cin >> std::ws, var.EmployeeFullName);

	if (var.EmployeeFullName == "0")
		return;

	for (int i = 0; i < employee_info.EmployeeNumber.size(); ++i) {
		if (employee_info.EmployeeFullName.at(i) == var.EmployeeFullName) {
			std::cout << "\n==== Work Info ====\n\n";
			std::cout << "Id : " << employee_info.EmployeeNumber.at(i) << '\n';
			std::cout << "ManagementNo. : " << employee_info.EmployeeManagementNumber.at(i) << "\n\n";

			std::cout << "==== Personal Info ====\n\n";
			std::cout << "Name : " << employee_info.EmployeeFullName.at(i) << '\n';
			std::cout << "Age : " << employee_info.EmployeeAge.at(i) << "\n";
			std::cout << "Address : " << employee_info.EmployeeAddress.at(i) << "\n\n";

			std::cout << "==== Contact Info ====\n\n";
			std::cout << "Phone Number : " << employee_info.EmployeePhoneNumber.at(i) << "\n\n";
			std::cout << std::string(34, '-') << '\n';
			var.InfoExist = true;
		}
	} employee_info.CheckIfDataExist(var.InfoExist);
}

void SearchForData::search_by_employees_management_number(const EmployeesData& employee_info) noexcept {

	std::cout << "Enter Employee Managment Number or 0 to return : ";
	InputHandler::InputAndErrorHanlder(var.EmployeeManagementNumber);

	if (var.EmployeeManagementNumber == 0)
		return;

	for (int i = 0; i < employee_info.EmployeeNumber.size(); ++i) {
		if (employee_info.EmployeeManagementNumber.at(i) == var.EmployeeManagementNumber) {
			std::cout << "\n==== Work Info ====\n\n";
			std::cout << "Id : " << employee_info.EmployeeNumber.at(i) << '\n';
			std::cout << "ManagementNo. : " << employee_info.EmployeeManagementNumber.at(i) << "\n\n";

			std::cout << "==== Personal Info ====\n\n";
			std::cout << "Name : " << employee_info.EmployeeFullName.at(i) << '\n';
			std::cout << "Age : " << employee_info.EmployeeAge.at(i) << "\n";
			std::cout << "Address : " << employee_info.EmployeeAddress.at(i) << "\n\n";

			std::cout << "==== Contact Info ====\n\n";
			std::cout << "Phone Number : " << employee_info.EmployeePhoneNumber.at(i) << "\n\n";
			std::cout << std::string(34, '-') << '\n';
			var.InfoExist = true;
		}
	} employee_info.CheckIfDataExist(var.InfoExist);
}

void SearchForData::search_by_employees_address(const EmployeesData& employee_info) noexcept {

	std::cout << "Enter Employee Address or 0 to return : ";
	std::getline(std::cin >> std::ws, var.EmployeeAddress);

	if (var.EmployeeAddress == "0")
		return;

	for (int i = 0; i < employee_info.EmployeeNumber.size(); ++i) {
		if (employee_info.EmployeeAddress.at(i) == var.EmployeeAddress) {
			std::cout << "\n==== Work Info ====\n\n";
			std::cout << "Id : " << employee_info.EmployeeNumber.at(i) << '\n';
			std::cout << "ManagementNo. : " << employee_info.EmployeeManagementNumber.at(i) << "\n\n";

			std::cout << "==== Personal Info ====\n\n";
			std::cout << "Name : " << employee_info.EmployeeFullName.at(i) << '\n';
			std::cout << "Age : " << employee_info.EmployeeAge.at(i) << "\n";
			std::cout << "Address : " << employee_info.EmployeeAddress.at(i) << "\n\n";

			std::cout << "==== Contact Info ====\n\n";
			std::cout << "Phone Number : " << employee_info.EmployeePhoneNumber.at(i) << "\n\n";
			std::cout << std::string(34, '-') << '\n';
			var.InfoExist = true;
		}
	} employee_info.CheckIfDataExist(var.InfoExist);
}

void SearchForData::search_for_employees_info(const EmployeesData& employee_info) noexcept {

	do {
		var.InfoExist = false;
		PrintInfo::ViewSearchingOptions();
		InputHandler::InputAndErrorHanlder(var.choice);

		switch (var.choice) {
		case 1:
			system("cls");
			SearchForData::search_by_employees_number(employee_info);
			break;

		case 2:
			system("cls");
			SearchForData::search_by_employees_name(employee_info);
			break;

		case 3:
			system("cls");
			SearchForData::search_by_employees_management_number(employee_info);
			break;

		case 4:
			system("cls");
			SearchForData::search_by_employees_address(employee_info);
			break;

		case 5:
			return;

		default:
			PrintInfo::PrintErrorMessage();
		}

		system("pause");
		system("cls");

	} while (var.choice != 5);
}