#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/EmployeesClass.h"

// Implements
void Employees::ViewMainMenu() { // <-- A function that shows the main menu
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

void Employees::ViewUpdatingOptions() { // <-- A function that shows the updating options
	std::cout << "--- Updating Uncomplete Employee Info ---\n\n";
	std::cout << "1- Update Employee Number (ID)\n";
	std::cout << "2- Update Employee Full Name\n";
	std::cout << "3- Update Employee Age\n";
	std::cout << "4- Update Employee Phone Number\n";
	std::cout << "5- Update Employee Managment Number\n";
	std::cout << "6- Update Employee Address\n";
	std::cout << "7- Return to the main menu\n\n";
	std::cout << "Enter your choice -> ";
}

void Employees::ViewSearchingOptions() { // <-- A function that shows the searching options
	std::cout << "--- Search For Employee By Filters ---\n\n";
	std::cout << "1- Search By Employee Number (ID)\n";
	std::cout << "2- Search By Employee Full Name\n";
	std::cout << "3- Search By Employee Managment Number\n";
	std::cout << "4- Search By Employee Address\n";
	std::cout << "5- Return to the main menu\n\n";
	std::cout << "Enter your choice -> ";
}

void Employees::ViewAboutProgramMenu() {
	std::cout << "      --- About the program ---\n\n\n";
	std::cout << "*************************************\n";
	std::cout << "*                                   *\n";
	std::cout << "*  developed by : Tomino(@tomino47) *\n";
	std::cout << "*                                   *\n";
	std::cout << "*************************************\n\n\n";
}

template<class T>
int Employees::InputAndErrorHanlder(T var) { // <-- A function that take and check the input

	// Taking input from user
	std::cin >> var;

	// Checking for input fail
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "\nWrong input, please try again ...\n";
	}
	return var;
}

bool Employees::isEmpty() { // <-- A function that returns true if the vector is empty
	return EmployeeNumber.empty();
}

void Employees::HireNewEmployee() { // <-- A function that let user add an employee info

	std::cout << "--- Hire New Employee ---\n\n";

	std::cout << "Enter Employee Id Number or 0 to return : ";
	var.EmployeeNumber = InputAndErrorHanlder(var.EmployeeNumber);

	if (var.EmployeeNumber == 0) return; // <-- If user input (0), return one step back

	std::cout << "Enter Employee Full Name : ";
	std::getline(std::cin >> std::ws, var.EmployeeFullName);

	std::cout << "Enter Employee Age : ";
	var.EmployeeAge = InputAndErrorHanlder(var.EmployeeAge);

	std::cout << "Enter Employee Phone Number : ";
	var.EmployeePhoneNumber = InputAndErrorHanlder(var.EmployeePhoneNumber);

	std::cout << "Enter Employee Managment Number : ";
	var.EmployeeManagmentNumber = InputAndErrorHanlder(var.EmployeeManagmentNumber);

	std::cout << "Enter Employee Address : ";
	std::getline(std::cin >> std::ws, var.EmployeeAddress);

	std::cout << "\nAre you sure to add this info ? (Y/N) : ";
	var.conform = InputAndErrorHanlder(var.conform);

	if (var.conform == 'y' || var.conform == 'Y') {
		this->EmployeeNumber.push_back(var.EmployeeNumber); // <-- Push Back the entered values
		this->EmployeeFullName.push_back(var.EmployeeFullName);
		this->EmployeeAge.push_back(var.EmployeeAge);
		this->EmployeePhoneNumber.push_back(var.EmployeePhoneNumber);
		this->EmployeeManagmentNumber.push_back(var.EmployeeManagmentNumber);
		this->EmployeeAddress.push_back(var.EmployeeAddress);
	}

	else if (var.conform == 'n' || var.conform == 'N') {
		std::cout << "The operation has been cancelled ...\n";
		return;
	}

	else {
		std::cout << "\nWrong input, please try again ...\n";
		return;
	}
}

void Employees::UpdatingEmployeesInfo() { // <-- A function that let user unpdate an employee info

	int UncompletedOption{};
	while (UncompletedOption != 7) {

		ViewUpdatingOptions(); // <-- Display the updating options
		std::cin >> UncompletedOption; // <-- Take the user input

		if (UncompletedOption == 0) return;

		switch (UncompletedOption) {
		case 1:
			system("cls");
			// Take the employee id as input
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0) return; // <-- If user input (0), return one step back

			// Check if the id is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber[i]) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << this->EmployeeFullName[i] << "\" ? (Y/N) : ";
					var.conform = InputAndErrorHanlder(var.conform);
				}
				else if (var.IdNumber != this->EmployeeNumber[i]) {
					std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
					return;
				}
			}

			// Check if the user agree for the changes or not
			if (var.conform == 'y' || var.conform == 'Y') {
				// If it agrees let him entered the new info
				std::cout << "Enter Employee New Id Number or 0 to return : ";
				var.EmployeeNumber = InputAndErrorHanlder(var.EmployeeNumber);
			}

			// If it didn't cancelle it
			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nWrong input, please try again ...\n";
				return;
			}

			// Delete the old info and replace it with the new one
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber[i])
					&& (var.conform == 'y' || var.conform == 'Y')) {

					this->EmployeeNumber.erase(this->EmployeeNumber.begin() + i);
					this->EmployeeNumber.push_back(var.EmployeeNumber);
					std::cout << "The info has been updated ...\n";
				}
			}
			break;

		case 2:
			system("cls");
			// Take the employee id as input
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0) return; // <-- If user input (0), return one step back

			// Check if the id is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber[i]) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << this->EmployeeFullName[i] << "\" ? (Y/N) : ";
					var.conform = InputAndErrorHanlder(var.conform);
				}
				else if (var.IdNumber != this->EmployeeNumber[i]) {
					std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
					return;
				}
			}

			// Check if the user agree for the changes or not
			if (var.conform == 'y' || var.conform == 'Y') {
				// If it agrees let him entered the new info
				std::cout << "Enter Employee Full Name or 0 to return : ";
				std::getline(std::cin >> std::ws, var.EmployeeFullName);
			}

			// If it didn't cancelle it
			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nWrong input, please try again ...\n";
				return;
			}

			// Delete the old info and replace it with the new one
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber[i])
					&& (var.conform == 'y' || var.conform == 'Y')) {

					this->EmployeeFullName.erase(this->EmployeeFullName.begin() + i);
					this->EmployeeFullName.push_back(var.EmployeeFullName);
					std::cout << "The info has been updated ...\n";
				}
			}
			break;

		case 3:
			system("cls");
			// Take the employee id as input
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0) return; // <-- If user input (0), return one step back

			// Check if the id is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber[i]) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << this->EmployeeFullName[i] << "\" ? (Y/N) : ";
					var.conform = InputAndErrorHanlder(var.conform);
				}
				else if (var.IdNumber != this->EmployeeNumber[i]) {
					std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
					return;
				}
			}

			// Check if the user agree for the changes or not
			if (var.conform == 'y' || var.conform == 'Y') {
				// If it agrees let him entered the new info
				std::cout << "Enter Employee Age or 0 to return : ";
				var.EmployeeAge = InputAndErrorHanlder(var.EmployeeAge);
			}

			// If it didn't cancelle it
			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nWrong input, please try again ...\n";
				return;
			}

			// Delete the old info and replace it with the new one
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber[i])
					&& (var.conform == 'y' || var.conform == 'Y')) {

					this->EmployeeAge.erase(this->EmployeeAge.begin() + i);
					this->EmployeeAge.push_back(var.EmployeeAge);
					std::cout << "The info has been updated ...\n";
				}
			}
			break;

		case 4:
			system("cls");
			// Take the employee id as input
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0) return; // <-- If user input (0), return one step back

			// Check if the id is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber[i]) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << this->EmployeeFullName[i] << "\" ? (Y/N) : ";
					var.conform = InputAndErrorHanlder(var.conform);
				}
				else if (var.IdNumber != this->EmployeeNumber[i]) {
					std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
					return;
				}
			}

			// Check if the user agree for the changes or not
			if (var.conform == 'y' || var.conform == 'Y') {
				// If it agrees let him entered the new info
				std::cout << "Enter Employee Phone Number or 0 to return : ";
				var.EmployeePhoneNumber = InputAndErrorHanlder(var.EmployeePhoneNumber);
			}

			// If it didn't cancelle it
			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nWrong input, please try again ...\n";
				return;
			}

			// Delete the old info and replace it with the new one
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber[i])
					&& (var.conform == 'y' || var.conform == 'Y')) {

					this->EmployeePhoneNumber.erase(this->EmployeePhoneNumber.begin() + i);
					this->EmployeePhoneNumber.push_back(var.EmployeePhoneNumber);
					std::cout << "The info has been updated ...\n";
				}
			}
			break;

		case 5:
			system("cls");
			// Take the employee id as input
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0) return; // <-- If user input (0), return one step back

			// Check if the id is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber[i]) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << this->EmployeeFullName[i] << "\" ? (Y/N) : ";
					var.conform = InputAndErrorHanlder(var.conform);
				}
				else if (var.IdNumber != this->EmployeeNumber[i]) {
					std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
					return;
				}
			}

			// Check if the user agree for the changes or not
			if (var.conform == 'y' || var.conform == 'Y') {
				// If it agrees let him entered the new info
				std::cout << "Enter Employee Managment Number or 0 to return : ";
				var.EmployeeManagmentNumber = InputAndErrorHanlder(var.EmployeeManagmentNumber);
			}

			// If it didn't cancelle it
			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nWrong input, please try again ...\n";
				return;
			}

			// Delete the old info and replace it with the new one
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber[i])
					&& (var.conform == 'y' || var.conform == 'Y')) {

					this->EmployeeManagmentNumber.erase(this->EmployeeManagmentNumber.begin() + i);
					this->EmployeeManagmentNumber.push_back(var.EmployeeManagmentNumber);
					std::cout << "The info has been updated ...\n";
				}
			}
			break;

		case 6:
			system("cls");
			// Take the employee id as input
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0) return; // <-- If user input (0), return one step back

			// Check if the id is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.IdNumber == this->EmployeeNumber[i]) {
					std::cout << "\nAre You sure to update this employee info \"";
					std::cout << this->EmployeeFullName[i] << "\" ? (Y/N) : ";
					var.conform = InputAndErrorHanlder(var.conform);
				}
				else if (var.IdNumber != this->EmployeeNumber[i]) {
					std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
					return;
				}
			}

			// Check if the user agree for the changes or not
			if (var.conform == 'y' || var.conform == 'Y') {
				// If it agrees let him entered the new info
				std::cout << "Enter Employee Address or 0 to return : ";
				std::getline(std::cin >> std::ws, var.EmployeeAddress);
			}

			// If it didn't cancelle it
			else if (var.conform == 'n' || var.conform == 'N') {
				std::cout << "The operation has been cancelled ...\n";
				return;
			}

			else {
				std::cout << "\nWrong input, please try again ...\n";
				return;
			}

			// Delete the old info and replace it with the new one
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if ((var.IdNumber == this->EmployeeNumber[i])
					&& (var.conform == 'y' || var.conform == 'Y')) {

					this->EmployeeAddress.erase(this->EmployeeAddress.begin() + i);
					this->EmployeeAddress.push_back(var.EmployeeAddress);
					std::cout << "The info has been updated ...\n";
				}
			}
			break;

		case 7: // <-- If the user choose return, then exit this function
			return; 
		}

		if (UncompletedOption > 7) { // <-- If input larger than 7 print error massege
			std::cout << "Wrong input, please try again ...\n";
		}

		system("pause");
		system("cls");
	}
}

void Employees::SearchForEmployeeByFiltring() { // <-- A function that let user search for employee info

	var.choice = 0;
	while (var.choice != 5) {

		ViewSearchingOptions(); // <-- Display the searching options
		var.choice = InputAndErrorHanlder(var.choice); // <-- Take the user input

		switch (var.choice) {
		case 1:
			system("cls");
			// Take the employee id as input
			std::cout << "Enter Employee Id Number or 0 to return : ";
			var.IdNumber = InputAndErrorHanlder(var.IdNumber);

			if (var.IdNumber == 0) return; // <-- If user input (0), return one step back

			// Check if the id is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.IdNumber == EmployeeNumber[i]) {
					std::cout << "\nId : " << EmployeeNumber[i] << "\n";
					std::cout << "Name : " << EmployeeFullName[i] << "\n";
					std::cout << "Age : " << EmployeeAge[i] << "\n";
					std::cout << "Phone : " << EmployeePhoneNumber[i] << "\n";
					std::cout << "ManagmentNo. : " << EmployeeManagmentNumber[i] << "\n";
					std::cout << "Address : " << EmployeeAddress[i] << "\n\n";
				}
				else if (var.IdNumber != this->EmployeeNumber[i]) {
					std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
					return;
				}
			}
			break;

		case 2:
			system("cls");
			// Take the employee full name as input
			std::cout << "Enter Employee Full Name or 0 to return : ";
			std::getline(std::cin >> std::ws, var.EmployeeFullName);

			if (var.EmployeeFullName == "0") return; // <-- If user input (0), return one step back

			// Check if the full name is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.EmployeeFullName == this->EmployeeFullName[i]) {
					std::cout << "\nId : " << EmployeeNumber[i] << "\n";
					std::cout << "Name : " << EmployeeFullName[i] << "\n";
					std::cout << "Age : " << EmployeeAge[i] << "\n";
					std::cout << "Phone : " << EmployeePhoneNumber[i] << "\n";
					std::cout << "ManagmentNo. : " << EmployeeManagmentNumber[i] << "\n";
					std::cout << "Address : " << EmployeeAddress[i] << "\n\n";
				}
				else if (var.EmployeeFullName != this->EmployeeFullName[i]) {
					std::cout << "\nThe entered name isn't a valid name, please try again ...\n";
					return;
				}
			}
			break;

		case 3:
			system("cls");
			// Take the employee managment number as input
			std::cout << "Enter Employee Managment Number or 0 to return : ";
			var.EmployeeManagmentNumber = InputAndErrorHanlder(var.EmployeeManagmentNumber);

			if (var.EmployeeManagmentNumber == 0) return; // <-- If user input (0), return one step back

			// Check if the managment number is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.EmployeeManagmentNumber == this->EmployeeManagmentNumber[i]) {
					std::cout << "\nId : " << EmployeeNumber[i] << "\n";
					std::cout << "Name : " << EmployeeFullName[i] << "\n";
					std::cout << "Age : " << EmployeeAge[i] << "\n";
					std::cout << "Phone : " << EmployeePhoneNumber[i] << "\n";
					std::cout << "ManagmentNo. : " << EmployeeManagmentNumber[i] << "\n";
					std::cout << "Address : " << EmployeeAddress[i] << "\n\n";
				}
				else if (var.EmployeeManagmentNumber != this->EmployeeManagmentNumber[i]) {
					std::cout << "\nThe entered managment number\n";
					std::cout << "isn't a valid managment number, please try again ...\n";
					return;
				}
			}
			break;

		case 4:
			system("cls");
			// Take the employee address as input
			std::cout << "Enter Employee Address or 0 to return : ";
			std::getline(std::cin >> std::ws, var.EmployeeAddress);

			if (var.EmployeeAddress == "0") return; // <-- If user input (0), return one step back

			// Check if the address is valid or not
			for (int i = 0; i < this->EmployeeNumber.size(); i++) {
				if (var.EmployeeAddress == this->EmployeeAddress[i]) {
					std::cout << "\nId : " << EmployeeNumber[i] << "\n";
					std::cout << "Name : " << EmployeeFullName[i] << "\n";
					std::cout << "Age : " << EmployeeAge[i] << "\n";
					std::cout << "Phone : " << EmployeePhoneNumber[i] << "\n";
					std::cout << "ManagmentNo. : " << EmployeeManagmentNumber[i] << "\n";
					std::cout << "Address : " << EmployeeAddress[i] << "\n\n";
				}
				else if (var.EmployeeAddress != this->EmployeeAddress[i]) {
					std::cout << "\nThe entered address isn't a valid address, please try again ...\n";
					return;
				}
			}
			break;

		case 5: // <-- If the user choose return, then exit this function
			return;
		}

		if (var.choice > 5) { // <-- If input larger than 5 print error massege
			std::cout << "Wrong input, please try again ...\n";
		}

		system("pause");
		system("cls");
	}
}

void Employees::ViewAllEmployeesInfo() { // <-- A function that show all employee's info

	std::cout << "--- View All Employees Info ---\n\n";

	if (isEmpty()) { // <-- Check if the vector empty or not
		std::cout << "It's empty you didn't add anything ...\n";
	}

	else {

		for (int i = 0; i < this->EmployeeNumber.size(); i++) { // <-- Print all employee's info
			std::cout << "Id : " << EmployeeNumber[i] << "\n";
			std::cout << "Name : " << EmployeeFullName[i] << "\n";
			std::cout << "Age : " << EmployeeAge[i] << "\n";
			std::cout << "Phone : " << EmployeePhoneNumber[i] << "\n";
			std::cout << "ManagmentNo. : " << EmployeeManagmentNumber[i] << "\n";
			std::cout << "Address : " << EmployeeAddress[i] << "\n\n";
		}
	}
}

void Employees::DeletingEmployeeInfo() { // <-- A function that let user delete an employee info

	std::cout << "      --- Deleting Employee Info ---\n\n";

	std::cout << "Enter Employee Id Number or 0 to return : ";
	var.IdNumber = InputAndErrorHanlder(var.IdNumber);

	if (var.IdNumber == 0) return; // <-- If user input (0), return one step back

	// Check if the id is valid or not
	for (int i = 0; i < this->EmployeeNumber.size(); i++) {
		if (var.IdNumber == this->EmployeeNumber[i]) {
			// Take the conformation to delete or not from the user as input
			std::cout << "\nAre You sure to delete this employee info \"";
			std::cout << this->EmployeeFullName[i] << "\" ? (Y/N) : ";
			var.conform = InputAndErrorHanlder(var.conform);
		}
		else {
			std::cout << "\nThe entered id isn't a valid id, please try again ...\n";
			return;
		}
	}

	// If user choose 'Y' then delete all the employee's info
	for (int i = 0; i < this->EmployeeNumber.size(); i++) {

		if (var.conform == 'y' || var.conform == 'Y') {
			if (var.IdNumber == EmployeeNumber[i]) {
				this->EmployeeNumber.erase(this->EmployeeNumber.begin() + i);
				this->EmployeeFullName.erase(this->EmployeeFullName.begin() + i);
				this->EmployeeAge.erase(this->EmployeeAge.begin() + i);
				this->EmployeePhoneNumber.erase(this->EmployeePhoneNumber.begin() + i);
				this->EmployeeAddress.erase(this->EmployeeAddress.begin() + i);
				this->EmployeeManagmentNumber.erase(this->EmployeeManagmentNumber.begin() + i);
			}
		}

		else if (var.conform == 'n' || var.conform == 'N') {
			std::cout << "The operation has been cancelled ...\n";
			return;
		}

		else {
			std::cout << "\nWrong input, please try again ...\n";
			return;
		}
	}
}
