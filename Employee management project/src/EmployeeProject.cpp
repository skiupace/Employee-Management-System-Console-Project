#include <iostream>
#include <vector>
#include "../classes/app_variables-struct/VariablesStruct.h"
#include "../classes/employee's_data_class-imp/EmployeesDataClass.h"

int main() {

	EmployeesData employee;
	while (var.choice != 7) {

		var.print.ViewMainMenu();
		var.choice = employee.input.InputAndErrorHanlder(var.choice);

		switch (var.choice) {
		case 1:
			system("cls");
			employee.HireNewEmployee();
			break;

		case 2:
			system("cls");
			employee.UpdatingEmployeesInfo();
			break;

		case 3:
			system("cls");
			var.search->search_for_employees_info(employee);
			break;

		case 4:
			system("cls");
			var.print.ViewAllEmployeesInfo(employee);
			break;

		case 5:
			system("cls");
			employee.DeletingEmployeeInfo();
			break;

		case 6:
			system("cls");
			var.print.ViewAboutProgramMenu();
			break;

		case 7:
			return 0;
		}

		if (var.choice > 7)
			std::cout << "Wrong input, please try again ...\n";

		system("pause");
		system("cls");
	}

	std::cin.get();
	return EXIT_SUCCESS;
}