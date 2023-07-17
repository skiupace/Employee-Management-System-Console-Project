#include <iostream>
#include <string>
#include <vector>
#include "../app_variables-struct/VariablesStruct.h"
#include "../employee's_data_class-imp/EmployeesDataClass.h"

template<class T>
T EmployeesData::TakeInput::InputAndErrorHanlder(T& var) { // <-- A function that take and check the input
	std::cin >> var;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Error: Invalid input, please try again ...\n";
	} return var;
}

const bool EmployeesData::isEmpty() const {
	return EmployeeNumber.empty();
}

void EmployeesData::HireNewEmployee() {

	std::cout << "--- Hire New Employee ---\n\n";

	std::cout << "Enter Employee Full Name or 0 to return : ";
	std::getline(std::cin >> std::ws, var.EmployeeFullName);
	if (var.EmployeeFullName == "0") return; // <-- If user input (0), return one step back

	std::cout << "Enter Employee Age : ";
	var.EmployeeAge = input.InputAndErrorHanlder(var.EmployeeAge);

	std::cout << "Enter Employee Phone Number : ";
	var.EmployeePhoneNumber = input.InputAndErrorHanlder(var.EmployeePhoneNumber);

	std::cout << "Enter Employee Managment Number : ";
	var.EmployeeManagmentNumber = input.InputAndErrorHanlder(var.EmployeeManagmentNumber);

	std::cout << "Enter Employee Address : ";
	std::getline(std::cin >> std::ws, var.EmployeeAddress);

	std::cout << "\nAre you sure to add this info ? (Y/N) : ";
	var.conform = input.InputAndErrorHanlder(var.conform);

	if (var.conform == 'y' || var.conform == 'Y') {
		this->EmployeeNumber.push_back(++var.EmployeeNumber);
		this->EmployeeFullName.push_back(var.EmployeeFullName);
		this->EmployeeAge.push_back(var.EmployeeAge);
		this->EmployeePhoneNumber.push_back(var.EmployeePhoneNumber);
		this->EmployeeManagmentNumber.push_back(var.EmployeeManagmentNumber);
		this->EmployeeAddress.push_back(var.EmployeeAddress);
		std::cout << "The operation has been completed ...\n";
	}

	else if (var.conform == 'n' || var.conform == 'N')
		std::cout << "The operation has been cancelled ...\n";

	else
		std::cout << "\nError: Invalid input, please try again ...\n";
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
			var.IdNumber = input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;
			
			// Check if the id is valid or not
			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber.at(i)) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					var.conform = input.InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!var.InfoExist) {
				std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
				return;
			}

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Full Name or 0 to return : ";
				std::getline(std::cin >> std::ws, var.EmployeeFullName);
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nError: Invalid input, please try again ...\n";
				return;
			}

			// Delete the old info and replace it with the new one
			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber.at(i)) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeeFullName.erase(EmployeeFullName.begin() + i);
					this->EmployeeFullName.push_back(var.EmployeeFullName);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 2:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber.at(i)) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					var.conform = input.InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!var.InfoExist) {
				std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
				return;
			}

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Age or 0 to return : ";
				var.EmployeeAge = input.InputAndErrorHanlder(var.EmployeeAge);
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nError: Invalid input, please try again ...\n";
				return;
			}

			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber.at(i)) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeeAge.erase(EmployeeAge.begin() + i);
					this->EmployeeAge.push_back(var.EmployeeAge);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 3:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber.at(i)) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					var.conform = input.InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!var.InfoExist) {
				std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
				return;
			}

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Phone Number or 0 to return : ";
				var.EmployeePhoneNumber = input.InputAndErrorHanlder(var.EmployeePhoneNumber);
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nError: Invalid input, please try again ...\n";
				return;
			}

			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber.at(i)) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeePhoneNumber.erase(EmployeePhoneNumber.begin() + i);
					this->EmployeePhoneNumber.push_back(var.EmployeePhoneNumber);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 4:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber.at(i)) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					var.conform = input.InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!var.InfoExist) {
				std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
				return;
			}

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Managment Number or 0 to return : ";
				var.EmployeeManagmentNumber = input.InputAndErrorHanlder(var.EmployeeManagmentNumber);
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nError: Invalid input, please try again ...\n";
				return;
			}

			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber.at(i)) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeeManagmentNumber.erase(EmployeeManagmentNumber.begin() + i);
					this->EmployeeManagmentNumber.push_back(var.EmployeeManagmentNumber);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 5:
			system("cls");
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = input.InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0)
				return;

			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber.at(i)) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
					var.conform = input.InputAndErrorHanlder(var.conform);
					var.InfoExist = true;
				}
			}

			if (!var.InfoExist) {
				std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
				return;
			}

			if (var.conform == 'y' || var.conform == 'Y') {
				std::cout << "Enter Employee Address or 0 to return : ";
				std::getline(std::cin >> std::ws, var.EmployeeAddress);
			}

			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nError: Invalid input, please try again ...\n";
				return;
			}

			for (int i = 0; i < EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber.at(i)) && (var.conform == 'y' || var.conform == 'Y')) {
					EmployeeAddress.erase(EmployeeAddress.begin() + i);
					this->EmployeeAddress.push_back(var.EmployeeAddress);
					std::cout << "The info has been updated ...\n";
				}
			} break;

		case 6:
			return; 
		}

		if (var.choice > 6)
			std::cout << "Error: Invalid input, please try again ...\n";

		system("pause");
		system("cls");
	}
}

void EmployeesData::DeletingEmployeeInfo() {

	std::cout << "      --- Deleting Employee Info ---\n\n";

	std::cout << "Enter Employee Id Number or 0 to return : ";
	var.IdNumber = input.InputAndErrorHanlder(var.IdNumber);

	var.InfoExist = false;
	if (var.IdNumber == 0)
		return;

	for (int i = 0; i < EmployeeNumber.size(); i++) {
		if (var.IdNumber == EmployeeNumber.at(i)) {
			std::cout << "\nAre You sure to delete this employee info \"";
			std::cout << EmployeeFullName.at(i) << "\" ? (Y/N) : ";
			var.conform = input.InputAndErrorHanlder(var.conform);
			var.InfoExist = true;
			var.index = i;
		}
	}

	if (!var.InfoExist)
		std::cout << "\nThe entered id isn't a valid id, please try again ...\n";

	// If user choose 'Y' then delete all the employee's info
	if (var.conform == 'y' || var.conform == 'Y') {
		EmployeeNumber.erase(EmployeeNumber.begin() + var.index);
		EmployeeFullName.erase(EmployeeFullName.begin() + var.index);
		EmployeeAge.erase(EmployeeAge.begin() + var.index);
		EmployeePhoneNumber.erase(EmployeePhoneNumber.begin() + var.index);
		EmployeeAddress.erase(EmployeeAddress.begin() + var.index);
		EmployeeManagmentNumber.erase(EmployeeManagmentNumber.begin() + var.index);

		std::cout << "The operation has been completed ...\n";
		for (int i = 0; i < EmployeeNumber.size(); i++)
			EmployeeNumber.at(i) = i + 1;
	}

	else if (var.conform == 'n' || var.conform == 'N')
		std::cout << "The operation has been cancelled ...\n";

	else
		std::cout << "\nError: Invalid input, please try again ...\n";
}
