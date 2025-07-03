#include "pch.h"
#include "MessageHookee.h"

int main()
{
	int nChoice = 0;
	while (true) {
		std::cout << "============================" << std::endl;
		std::cout << "1. Show MessageBox Hookee" << std::endl;
		std::cout << "2. Exit program" << std::endl;
		std::cout << "============================" << std::endl;
		std::cout << "Select: ";
		std::cin >> nChoice;

		if (nChoice == 1) {
			g_bMessageHookee = MessageBoxHookee();
		} else if (nChoice == 2) {
			std::cout << "Exiting program." << std::endl;
			break;
		} else {
			std::cout << "Invalid input. Please try again." << std::endl;
		}
	}
	return 0;
}