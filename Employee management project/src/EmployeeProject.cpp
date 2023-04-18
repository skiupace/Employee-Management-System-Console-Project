#include <iostream>
#include "../Header Files/EmployeesClass.h"

int main() {

	int choice = 0;
	Employees employee;

	while (choice != 7) { // <-- The main while loop

		employee.ViewMainMenu(); // <-- Display the main menu
		choice = employee.InputAndErrorHanlder(choice); // <-- Take the user input

		switch (choice) {
		case 1:
			system("cls");
			employee.HireNewEmployee(); // <-- Call the add function
			break;

		case 2:
			system("cls");
			employee.UpdatingEmployeesInfo(); // <-- Call the update function
			break;

		case 3:
			system("cls");
			employee.SearchForEmployeeByFiltring(); // <-- Call the search function
			break;

		case 4:
			system("cls");
			employee.ViewAllEmployeesInfo(); // <-- Call the view function
			break;

		case 5:
			system("cls");
			employee.DeletingEmployeeInfo(); // <-- Call the delete function
			break;

		case 6:
			system("cls");
			employee.ViewAboutProgramMenu(); // <-- Call the about function
			break;

		case 7: // <-- If the user choose return, then exit the program
			return 0;
		}

		if (choice > 7) { // <-- If input larger than 7 print error massege
			std::cout << "Wrong input, please try again ...\n";
		}

		system("pause");
		system("cls");
	}

	std::cin.get();
	return EXIT_SUCCESS;
}