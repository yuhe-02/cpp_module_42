# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <map>
// #include "./includes/BitcoinExchange.hpp"

bool isDigit(const char c)
{
	return ('0' <= c && c <= '9');
}

// TODO ファイル読み込み追加(upper, lower boundをしようする)
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// if (argc <= 1)
	// {
	// 	std::cerr << "Error: could not open file" << std::endl;
	// 	return (0);
	// }
	// if (argc != 2)
	// {
	// 	std::cerr << "Error: too much arguments" << std::endl;
	// 	return (0);
	// }
	std::string rate_file_path = "./const/data.csv";
	// std::string input_file_path(argv[1]);
	std::fstream rate_file;

	try 
	{
		rate_file.open(rate_file_path.c_str(), std::ios::in);
		std::string line;
		std::string date_str;
		std::string rate_str;
		float rate;
		const char delim = ',';
		std::map<std::string, float> result;
	
		std::getline(rate_file, line);
		while (std::getline(rate_file, line)) 
		{
			std::stringstream ss(line);
			std::getline(ss, date_str, delim);
			std::getline(ss, rate_str); 
			std::stringstream(rate_str) >> rate;
			result[date_str] = rate;
		}
		for (std::map<std::string, float>::iterator it = result.begin(); it != result.end(); ++it) {
			std::cout << "key: \'" << it->first << "\', value: \'" << it->second << "\'" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}