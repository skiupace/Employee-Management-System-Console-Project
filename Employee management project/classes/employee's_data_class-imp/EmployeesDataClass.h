#pragma once
#include "../employee's_class_attributes/EmployeesClass.h"

class EmployeesData : public Employees {
public:
	const bool isEmpty() const;
	void HireNewEmployee();
	void UpdatingEmployeesInfo();
	void DeletingEmployeeInfo();

	class TakeInput {
	public:
		template<class T>
		T InputAndErrorHanlder(T& var);
	} input;

private:
	friend class PrintInfo;
	friend class SearchForData;
};