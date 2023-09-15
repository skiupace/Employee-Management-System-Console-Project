#pragma once

class InputHandler {
public:
	template<class T>
	static void InputAndErrorHanlder(T& variable) noexcept {
		std::cin >> variable;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << '\a';
		}
	}
};