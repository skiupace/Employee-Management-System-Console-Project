#include <iostream>
#include <string>
#include <vector>
#include "../app_variables-struct/VariablesStruct.hpp"
#include "../input_handler_class-imp/InputHandlerClass.hpp"
#include "../employee's_data_class-imp/EmployeesDataClass.hpp"

bool EmployeesData::isEmpty() const noexcept {
	return EmployeeNumber.empty();
}

constexpr bool EmployeesData::CheckIfDataExist(bool isExist) const noexcept {
	if (!isExist) {
		std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
		return false;
	} else
		return true;
}

void EmployeesData::HireNewEmployee() noexcept {

	std::cout << "--- Hire New Employee ---\n\n";
	std::cout << "Enter Employee Full Name or 0 to return : ";
	std::getline(std::cin >> std::ws, var.EmployeeFullName);

	if (var.EmployeeFullName == "0")
		return;

	std::cout << "Enter Employee Age : ";
	InputHandler::InputAndErrorHanlder(var.EmployeeAge);

	std::cout << "Enter Employee Phone Number : ";
	InputHandler::InputAndErrorHanlder(var.EmployeePhoneNumber);

	std::cout << "Enter Employee Managment Number : ";
	InputHandler::InputAndErrorHanlder(var.EmployeeManagementNumber);

	std::cout << "Enter Employee Address : ";
	std::getline(std::cin >> std::ws, var.EmployeeAddress);

	std::cout << "\nAre you sure to add this info ? (Y/N) : ";
	InputHandler::InputAndErrorHanlder(var.conform);

	if (var.conform == 'y' || var.conform == 'Y') {
		this->EmployeeNumber.push_back(++var.EmployeeNumber);
		this->EmployeeFullName.push_back(var.EmployeeFullName);
		this->EmployeeAge.push_back(var.EmployeeAge);
		this->EmployeePhoneNumber.push_back(var.EmployeePhoneNumber);
		this->EmployeeManagementNumber.push_back(var.EmployeeManagementNumber);
		this->EmployeeAddress.push_back(var.EmployeeAddress);
		std::cout << "The operation has been completed ...\n";
	}

	else if (var.conform == 'n' || var.conform == 'N')
		std::cout << "The operation has been cancelled ...\n";

	else
		PrintInfo::PrintErrorMessage();
}

void EmployeesData::UpdatingEmployeesInfo() noexcept {

	while (var.choice != 7) {

		PrintInfo::ViewUpdatingOptions();
		std::cin >> var.choice;

		var.InfoExist = false;
		if (var.choice == 0)
			return;

		switch (var.choice) {
		case 1:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			InputHandler::InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			// Check if the id is valid or not
			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					InputHandler::InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!CheckIfDataExist(var.InfoExist))
				return;

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Full Name or 0 to return : ";
				std::getline(std::cin >> std::ws, var.EmployeeFullName);

				if (var.EmployeeFullName == "0")
					return;
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				PrintInfo::PrintErrorMessage();
				return;
			}

			// Delete the old info and replace it with the new one
			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if ((EmployeeNumber.at(i) == var.IdNumber) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeeFullName.erase(EmployeeFullName.begin() + i);
					EmployeeFullName.push_back(var.EmployeeFullName);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 2:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			InputHandler::InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					InputHandler::InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!CheckIfDataExist(var.InfoExist))
				return;

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Age or 0 to return : ";
				InputHandler::InputAndErrorHanlder(var.EmployeeAge);

				if (var.EmployeeAge == 0)
					return;
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				PrintInfo::PrintErrorMessage();
				return;
			}

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if ((EmployeeNumber.at(i) == var.IdNumber) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeeAge.erase(EmployeeAge.begin() + i);
					EmployeeAge.push_back(var.EmployeeAge);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 3:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			InputHandler::InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					InputHandler::InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!CheckIfDataExist(var.InfoExist))
				return;

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Phone Number or 0 to return : ";
				InputHandler::InputAndErrorHanlder(var.EmployeePhoneNumber);

				if (var.EmployeePhoneNumber == 0)
					return;
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				PrintInfo::PrintErrorMessage();
				return;
			}

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if ((EmployeeNumber.at(i) == var.IdNumber) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeePhoneNumber.erase(EmployeePhoneNumber.begin() + i);
					EmployeePhoneNumber.push_back(var.EmployeePhoneNumber);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 4:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			InputHandler::InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					InputHandler::InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!CheckIfDataExist(var.InfoExist))
				return;

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Managment Number or 0 to return : ";
				InputHandler::InputAndErrorHanlder(var.EmployeeManagementNumber);

				if (var.EmployeeManagementNumber == 0)
					return;
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				PrintInfo::PrintErrorMessage();
				return;
			}

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if ((EmployeeNumber.at(i) == var.IdNumber) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeeManagementNumber.erase(EmployeeManagementNumber.begin() + i);
					EmployeeManagementNumber.push_back(var.EmployeeManagementNumber);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 5:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			InputHandler::InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					InputHandler::InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!CheckIfDataExist(var.InfoExist))
				return;

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Address or 0 to return : ";
				std::getline(std::cin >> std::ws, var.EmployeeAddress);

				if (var.EmployeeAddress == "0")
					return;
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				PrintInfo::PrintErrorMessage();
				return;
			}

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if ((EmployeeNumber.at(i) == var.IdNumber) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeeAddress.erase(EmployeeAddress.begin() + i);
					EmployeeAddress.push_back(var.EmployeeAddress);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 6:
			return;

		default:
			PrintInfo::PrintErrorMessage();
		}

		system("pause");
		system("cls");
	}
}

void EmployeesData::DeletingEmployeeInfo() noexcept {

	std::cout << "      --- Deleting Employee Info ---\n\n";

	std::cout << "Enter Employee Id Number or 0 to return : ";
	InputHandler::InputAndErrorHanlder(var.IdNumber);

	var.InfoExist = false;
	if (var.IdNumber == 0)
		return;

	for (int i = 0; i < EmployeeNumber.size(); ++i) {
		if (EmployeeNumber.at(i) == var.IdNumber) {
			std::cout << "\nAre you sure to delete this employee info \"";
			std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
			InputHandler::InputAndErrorHanlder(var.conform);
			var.InfoExist = true;
			var.index = i;
		}
	}

	if (!CheckIfDataExist(var.InfoExist))
		return;

	if (var.conform == 'y' || var.conform == 'Y') {
		EmployeeNumber.erase(EmployeeNumber.begin() + var.index);
		EmployeeFullName.erase(EmployeeFullName.begin() + var.index);
		EmployeeAge.erase(EmployeeAge.begin() + var.index);
		EmployeePhoneNumber.erase(EmployeePhoneNumber.begin() + var.index);
		EmployeeAddress.erase(EmployeeAddress.begin() + var.index);
		EmployeeManagementNumber.erase(EmployeeManagementNumber.begin() + var.index);

		std::cout << "The operation has been completed ...\n";
		for (int i = 0; i < EmployeeNumber.size(); ++i)
			EmployeeNumber.at(i) = i + 1;
		var.EmployeeNumber--;
	}

	else if (var.conform == 'n' || var.conform == 'N')
		std::cout << "The operation has been cancelled ...\n";

	else
		PrintInfo::PrintErrorMessage();
}
