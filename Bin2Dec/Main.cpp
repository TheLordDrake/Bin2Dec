#include "Main.h"

#include <typeinfo>


int main(int argc, char* argv[])
{
	// TODO: If no args provided, wait for input
	const vector<string> arguments(argv + 1, argv + argc);
	
	for (auto i = 0; i < argc; i++)
	{	
		if (!is_valid_binary(arguments))
		{
			cout << std::string(80, '-') << endl;
			cerr << "Input not valid binary!\nEnsure arguments are valid binary only: Leading 0s may be omitted" << endl;
			exit(EXIT_FAILURE);
		}
	}
	
	return EXIT_SUCCESS;
}

bool is_valid_binary(const vector<string>& bin_arr)
{
	for (const auto& bin_string : bin_arr)
	{
		if (bin_string.size() > 8)
		{
			cerr << "\nInput too long! Input must be <= 8 characters.\nInput provided was " << bin_string.size() << " characters." << endl;
			return false;
		}

		const int invalid_char = bin_string.find_first_not_of("01");
		if (invalid_char >= 0)
		{
			cerr << "\nInvalid character detected: '" << bin_string[invalid_char] << "' at index: " << invalid_char << " of " << bin_string <<endl;
			return false;
		}
	}
	
	return true;
}
