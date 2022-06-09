#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main() {
	std::system("Color 0A");

	std::cout << "\n\t\t\t\t\t-------------------------------------------\n";
	std::cout << "\t\t\t\t\t|\tLogin & Registration System\t  |\n";
	std::cout << "\t\t\t\t\t-------------------------------------------\n";

	std::cout << "\n\t\t\t\t\tDo you want to Register ? : [1]\n";
	std::cout << "\n\t\t\t\t\tor do you want to Login ? : [2]\n";

	std::cout << "\n\t\t\t\t\tYour choice : ";

	int option_chosen;

	std::cin >> option_chosen;

	std::ofstream file;

	std::ifstream fin;

	std::string user_name, user_password, user_confirm_password;

	std::hash<std::string> hash_string;

	switch (option_chosen) {
	case 1:

		std::cout << "\n\t\t\t\t\t-----------------------------------\n";
		std::cout << "\t\t\t\t\t|\tRegistration Process\t  |\n";
		std::cout << "\t\t\t\t\t-----------------------------------\n";

		std::cout << "\n\t\t\t\t\tEnter your username: ";

		std::cin >> user_name;

		fin.open(user_name + ".txt");

		if (fin) {
			system("Color 04");
			std::cout << "\n\t\t\t\t\tUser with name '" + user_name + "' already exists!!\n\n";
			exit(0);
		}

		file.open(user_name + ".txt", std::ios::out);

		if (!file) {
			system("Color 04");
			std::cout << "\n\t\t\t\t\tAn error occurred. Please try again later!!";
			return 0;
		}

		while (file) {
			std::cout << "\n\t\t\t\t\tEnter a password: ";
			std::cin >> user_password;

			std::cout << "\n\t\t\t\t\tConfirm your password: ";
			std::cin >> user_confirm_password;

			if (user_password != user_confirm_password) {
				system("Color 04");
				std::cout << "\n\t\t\t\t\tERROR! Both the passwords don't match. Try again!!\n\n";
				file.close();
				std::filesystem::remove(user_name + ".txt");
				exit(0);
			}
			else {
				file << hash_string(user_password);
				std::cout << "\n\t\t\t\t\tSUCCESS! You're Successfully registered as a user!!\n\n";
			}

			break;
		}

		file.close();

		break;

	case 2:

		std::cout << "\n\t\t\t\t\t----------------------------\n";
		std::cout << "\t\t\t\t\t|\tLogin Process\t   |\n";
		std::cout << "\t\t\t\t\t----------------------------\n";

		std::cout << "\n\t\t\t\t\tEnter your username: ";

		std::cin >> user_name;

		fin.open(user_name + ".txt");

		if (!fin) {
			system("Color 04");
			std::cout << "\n\t\t\t\t\tERROR! There's no user with the username '" + user_name + "' in the database\n\n";
			exit(0);
		}

		std::cout << "\n\t\t\t\t\tEnter your password: ";

		std::cin >> user_confirm_password;

		while (fin) {
			getline(fin, user_password);
			break;
		}

		fin.close();

		if (hash_string(user_password) != hash_string(user_confirm_password)) {
			system("Color 04");
			std::cout << "\n\t\t\t\t\tERROR! Your password was incorrect. Try again!!\n\n";
		}
		else {
			std::cout << "\n\t\t\t\t\tSUCCESS! You've successfully logged in !!\n\n";
		}

		break;

	default:
		system("Color 04");
		std::cout << "\n\t\t\t\t\tERROR! Please try again later !!\n\n";
		break;
	}

	return 0;
}