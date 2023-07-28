#pragma once
#include "../employee's_data_class-imp/EmployeesDataClass.hpp"

class PrintInfo {
public:
	static void ViewMainMenu();
	static void ViewAboutProgramMenu();
	static void ViewUpdatingOptions();
	static void ViewSearchingOptions();
	static void PrintErrorMessage();
	static void ViewAllEmployeesInfo(const EmployeesData& obj);
};