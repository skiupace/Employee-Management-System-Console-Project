#include <iostream>
#include <vector>
#include "../classes/app_variables-struct/VariablesStruct.hpp"
#include "../classes/employee's_data_class-imp/EmployeesDataClass.hpp"

int main() {

	EmployeesData employee_info;
	while (var.choice != 7) {

		PrintInfo::ViewMainMenu();
		employee_info.input.InputAndErrorHanlder(var.choice);

		switch (var.choice) {
		case 1:
			system("cls");
			employee_info.HireNewEmployee();
			break;

		case 2:
			system("cls");
			employee_info.UpdatingEmployeesInfo();
			break;

		case 3:
			system("cls");
			SearchForData::search_for_employees_info(employee_info);
			break;

		case 4:
			system("cls");
			PrintInfo::ViewAllEmployeesInfo(employee_info);
			break;

		case 5:
			system("cls");
			employee_info.DeletingEmployeeInfo();
			break;

		case 6:
			system("cls");
			PrintInfo::ViewAboutProgramMenu();
			break;

		case 7:
			return 0;
		}

		if (var.choice > 7 || var.choice <= 0)
			PrintInfo::PrintErrorMessage();

		system("pause");
		system("cls");
	}

	std::cin.get();
	return EXIT_SUCCESS;
}