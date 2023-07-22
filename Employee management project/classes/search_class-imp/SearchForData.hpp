#pragma once
#include <string>
#include "../app_variables-struct/VariablesStruct.hpp"
#include "../employee's_data_class-imp/EmployeesDataClass.hpp"

class SearchForData {
public:
	void search_for_employees_info(const EmployeesData& employee_info) {
		
		do {
			var.InfoExist = false;
			var.print.ViewSearchingOptions();
			employee_info.input.InputAndErrorHanlder(var.choice);

			switch (var.choice) {
			case 1:
				system("cls");
				std::cout << "Enter Employee Id Number or 0 to return : ";
				employee_info.input.InputAndErrorHanlder(var.IdNumber);

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
				break;

			case 2:
				system("cls");
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
				break;

			case 3:
				system("cls");
				std::cout << "Enter Employee Managment Number or 0 to return : ";
				employee_info.input.InputAndErrorHanlder(var.EmployeeManagementNumber);

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
				break;

			case 4:
				system("cls");
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
				break;

			case 5:
				return;
			}

			if (var.choice > 5)
				var.print.PrintErrorMessage();

			system("pause");
			system("cls");

		} while (var.choice != 5);
	}
};