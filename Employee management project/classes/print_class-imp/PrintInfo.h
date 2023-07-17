#pragma once
#include "../employee's_data_class-imp/EmployeesDataClass.h"

class PrintInfo {
public:
	void ViewMainMenu() const;
	void ViewAboutProgramMenu() const;
	void ViewUpdatingOptions() const;
	void ViewSearchingOptions() const;
	void ViewAllEmployeesInfo(EmployeesData& obj) const;
};