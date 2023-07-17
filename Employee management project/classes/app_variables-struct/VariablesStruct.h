#include "../print_class-imp/PrintInfo.h"
#include "../search_class-imp/SearchForData.h"

#ifndef variables
#define variables

struct variables { // <-- A structure with all most used variables

	char conform{};
	bool InfoExist{};

	PrintInfo print;
	SearchForData* search;

	std::string EmployeeFullName, EmployeeAddress;
	int EmployeeNumber{}, EmployeeAge{}, EmployeePhoneNumber{},
		EmployeeManagmentNumber{}, IdNumber{}, choice{}, index{};
} var;

#endif // !variables