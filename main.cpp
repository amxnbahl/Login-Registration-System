#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main()
{
	std::system("Color 0A");

	std::cout << "\n\t\t\t\t\t---------------------------------------------";
	std::cout << "\n\t\t\t\t\t|\tLogin and Registration System\t    |";
	std::cout << "\n\t\t\t\t\t---------------------------------------------";

	std::cout << "\n\n\t\t\t\t\tRegister : [1]\n";
	std::cout << "\n\t\t\t\t\tLogin : [2]\n";
	std::cout << "\n\t\t\t\t\tDelete Credentials : [3]\n";

	std::cout << "\n\t\t\t\t\tYour choice : ";

	int option_chosen = 0;

	std::cin >> option_chosen;

	std::ofstream file;

	std::ifstream fin;

	std::string hashed_user_name, hashed_user_password, user_file ,user_name, user_password, hashed_user_confirm_password, user_confirm_password;

	std::hash<std::string> hash_string;

	switch (option_chosen)
	{
	case 1:

		std::cout << "\n\t\t\t\t\t-----------------------------------\n";
		std::cout << "\t\t\t\t\t|\tRegistration Process\t  |\n";
		std::cout << "\t\t\t\t\t-----------------------------------\n";

		std::cout << "\n\t\t\t\t\tEnter your username: ";

		std::cin >> user_name;

		hashed_user_name = hash_string(user_name);

		user_file = hashed_user_name;

		user_file.append(".txt");

		fin.open(user_file);

		if (fin)
		{
			system("Color 04");
			std::cout << "\n\t\t\t\t\tUser with name '" + user_name + "' already exists!!\n\n";
			exit(0);
		}

		file.open(user_file, std::ios::out);

		if (!file)
		{
			system("Color 04");
			std::cout << "\n\t\t\t\t\tAn error occurred. Please try again later!!";
			return 0;
		}

		while (file)
		{
			std::cout << "\n\t\t\t\t\tEnter a password: ";
			std::cin >> user_password;

			std::cout << "\n\t\t\t\t\tConfirm your password: ";
			std::cin >> user_confirm_password;

			if (user_password != user_confirm_password)
			{
				system("Color 04");
				std::cout << "\n\t\t\t\t\tERROR! Both the passwords don't match. Try again!!\n\n";
				file.close();
				std::filesystem::remove(user_file);
				exit(0);
			}
			else
			{
				hashed_user_password = hash_string(user_password);
				file << hashed_user_password;
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

		hashed_user_name = hash_string(user_name);

		user_file.append(hashed_user_name);
		user_file.append(".txt");

		fin.open(user_file);

		if (!fin)
		{
			system("Color 04");
			std::cout << "\n\t\t\t\t\tERROR! There's no user with the username '" + user_name + "' in the database\n\n";
			exit(0);
		}

		std::cout << "\n\t\t\t\t\tEnter your password: ";

		std::cin >> user_confirm_password;

		hashed_user_confirm_password = hash_string(user_confirm_password);

		while (fin)
		{
			getline(fin, hashed_user_password);
			break;
		}

		fin.close();

		if (hashed_user_confirm_password != hashed_user_password)
		{
			system("Color 04");
			std::cout << "\n\t\t\t\t\tERROR! Your password was incorrect. Try again!!\n\n";
		}
		else
		{
			std::cout << "\n\t\t\t\t\tSUCCESS! You've successfully logged in !!\n\n";
		}

		break;

	case 3:
		std::cout << "\n\t\t\t\t\t-----------------------------------\n";
		std::cout << "\t\t\t\t\t|\tCredentials Deletion Process\t  |\n";
		std::cout << "\t\t\t\t\t-----------------------------------\n";

		std::cout << "\n\t\t\t\t\tEnter your username: ";

		std::cin >> user_name;

		hashed_user_name = hash_string(user_name);

		user_file.append(hashed_user_name);
		user_file.append(".txt");

		fin.open(user_file);

		if (!fin)
		{
			system("Color 04");
			std::cout << "\n\t\t\t\t\tUser with name '" + user_name + "' doesn't exists!!\n\n";
			exit(0);
		}

		std::cout << "\n\t\t\t\t\tEnter your password: ";

		std::cin >> user_confirm_password;

		hashed_user_confirm_password = hash_string(user_confirm_password);

		while (fin)
		{
			getline(fin, hashed_user_password);
			break;
		}

		fin.close();

		if (hashed_user_password != hashed_user_confirm_password)
		{
			system("Color 04");
			std::cout << "\n\t\t\t\t\tERROR! Your password was incorrect. Try again!!\n\n";
		}
		else
		{
			std::filesystem::remove(user_file);
			std::cout << "\n\t\t\t\t\tSUCCESS! Your credentials have been deleted successfully !!\n\n";
		}

		break;

	default:
		system("Color 04");
		std::cout << "\n\t\t\t\t\tERROR! Please try again later !!\n\n";
		break;
	}

	return 0;
}
