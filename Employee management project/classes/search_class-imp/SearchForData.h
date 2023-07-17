#pragma once
#include <string>
#include "../app_variables-struct/VariablesStruct.h"
#include "../employee's_data_class-imp/EmployeesDataClass.h"

class SearchForData {
public:
	void search_for_employees_info(EmployeesData& obj) {
		
		var.choice = 0;
		while (var.choice != 5) {

			var.InfoExist = false;
			var.print.ViewSearchingOptions();
			var.choice = employee.input.InputAndErrorHanlder(var.choice);

			switch (var.choice) {
			case 1:
				system("cls");
				std::cout << "Enter Employee Id Number or 0 to return : ";
				var.IdNumber = employee.input.InputAndErrorHanlder(var.IdNumber);

				if (var.IdNumber == 0)
					return;

				for (int i = 0; i < obj.EmployeeNumber.size(); i++) {
					if (obj.EmployeeNumber.at(i) == var.IdNumber) {
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
						var.InfoExist = true;
					}
				}
				
				if (!var.InfoExist)
					std::cout << "Error: Invalid input, please try again ...\n";
				break;

			case 2:
				system("cls");
				std::cout << "Enter Employee Full Name or 0 to return : ";
				std::getline(std::cin >> std::ws, var.EmployeeFullName);

				if (var.EmployeeFullName == "0")
					return;

				for (int i = 0; i < obj.EmployeeNumber.size(); i++) {
					if (obj.EmployeeFullName.at(i) == var.EmployeeFullName) {
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
						var.InfoExist = true;
					}
				}
				
				if (!var.InfoExist)
					std::cout << "Error: Invalid input, please try again ...\n";
				break;

			case 3:
				system("cls");
				std::cout << "Enter Employee Managment Number or 0 to return : ";
				var.EmployeeManagmentNumber = employee.input.InputAndErrorHanlder(var.EmployeeManagmentNumber);

				if (var.EmployeeManagmentNumber == 0)
					return;

				for (int i = 0; i < obj.EmployeeNumber.size(); i++) {
					if (obj.EmployeeManagmentNumber.at(i) == var.EmployeeManagmentNumber) {
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
						var.InfoExist = true;
					}
				}
				
				if (!var.InfoExist)
					std::cout << "Error: Invalid input, please try again ...\n";
				break;

			case 4:
				system("cls");
				std::cout << "Enter Employee Address or 0 to return : ";
				std::getline(std::cin >> std::ws, var.EmployeeAddress);

				if (var.EmployeeAddress == "0")
					return;

				for (int i = 0; i < obj.EmployeeNumber.size(); i++) {
					if (obj.EmployeeAddress.at(i) == var.EmployeeAddress) {
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
						var.InfoExist = true;
					}
				}
				
				if (!var.InfoExist)
					std::cout << "Error: Invalid input, please try again ...\n";
				break;

			case 5:
				return;
			}

			if (var.choice > 5)
				std::cout << "Error: Invalid input, please try again ...\n";

			system("pause");
			system("cls");
		}
	}

private:
	EmployeesData employee;
};