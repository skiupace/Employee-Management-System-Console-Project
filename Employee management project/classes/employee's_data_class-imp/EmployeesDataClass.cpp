#include <iostream>
#include <string>
#include <vector>
#include "../app_variables-struct/VariablesStruct.hpp"
#include "../employee's_data_class-imp/EmployeesDataClass.hpp"

template<class T>
void EmployeesData::TakeInput::InputAndErrorHanlder(T& variable) const { // <-- A function that take and check the input
	std::cin >> variable;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		var.print.PrintErrorMessage();
	}
}

const bool EmployeesData::isEmpty() const {
	return EmployeeNumber.empty();
}

bool EmployeesData::CheckIfDataExist(bool isExist) const {
	if (!isExist) {
		std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
		return false;
	} else
		return true;
}

void EmployeesData::HireNewEmployee() {

	std::cout << "--- Hire New Employee ---\n\n";
	std::cout << "Enter Employee Full Name or 0 to return : ";
	std::getline(std::cin >> std::ws, var.EmployeeFullName);

	if (var.EmployeeFullName == "0")
		return;

	std::cout << "Enter Employee Age : ";
	input.InputAndErrorHanlder(var.EmployeeAge);

	std::cout << "Enter Employee Phone Number : ";
	input.InputAndErrorHanlder(var.EmployeePhoneNumber);

	std::cout << "Enter Employee Managment Number : ";
	input.InputAndErrorHanlder(var.EmployeeManagementNumber);

	std::cout << "Enter Employee Address : ";
	std::getline(std::cin >> std::ws, var.EmployeeAddress);

	std::cout << "\nAre you sure to add this info ? (Y/N) : ";
	input.InputAndErrorHanlder(var.conform);

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
		var.print.PrintErrorMessage();
}

void EmployeesData::UpdatingEmployeesInfo() {

	while (var.choice != 7) {

		var.print.ViewUpdatingOptions();
		std::cin >> var.choice;

		var.InfoExist = false;
		if (var.choice == 0)
			return;

		switch (var.choice) {
		case 1:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			// Check if the id is valid or not
			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					input.InputAndErrorHanlder(var.conform);
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
				var.print.PrintErrorMessage();
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
			input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					input.InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!CheckIfDataExist(var.InfoExist))
				return;

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Age or 0 to return : ";
				input.InputAndErrorHanlder(var.EmployeeAge);

				if (var.EmployeeAge == 0)
					return;
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				var.print.PrintErrorMessage();
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
			input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					input.InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!CheckIfDataExist(var.InfoExist))
				return;

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Phone Number or 0 to return : ";
				input.InputAndErrorHanlder(var.EmployeePhoneNumber);

				if (var.EmployeePhoneNumber == 0)
					return;
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				var.print.PrintErrorMessage();
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
			input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					input.InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!CheckIfDataExist(var.InfoExist))
				return;

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Managment Number or 0 to return : ";
				input.InputAndErrorHanlder(var.EmployeeManagementNumber);

				if (var.EmployeeManagementNumber == 0)
					return;
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				var.print.PrintErrorMessage();
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
			input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); ++i) {
				if (EmployeeNumber.at(i) == var.IdNumber) {
					std::cout << "\nAre you sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					input.InputAndErrorHanlder(var.conform);
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
				var.print.PrintErrorMessage();
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
		}

		if (var.choice > 6)
			var.print.PrintErrorMessage();

		system("pause");
		system("cls");
	}
}

void EmployeesData::DeletingEmployeeInfo() {

	std::cout << "      --- Deleting Employee Info ---\n\n";

	std::cout << "Enter Employee Id Number or 0 to return : ";
	input.InputAndErrorHanlder(var.IdNumber);

	var.InfoExist = false;
	if (var.IdNumber == 0)
		return;

	for (int i = 0; i < EmployeeNumber.size(); ++i) {
		if (EmployeeNumber.at(i) == var.IdNumber) {
			std::cout << "\nAre you sure to delete this employee info \"";
			std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
			input.InputAndErrorHanlder(var.conform);
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
		for (int i = 0; i < EmployeeNumber.size(); i++)
			EmployeeNumber.at(i) = i + 1;
	}

	else if (var.conform == 'n' || var.conform == 'N')
		std::cout << "The operation has been cancelled ...\n";

	else
		var.print.PrintErrorMessage();
}
