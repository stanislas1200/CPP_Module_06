#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
#define _GLIBCXX_USE_C99 1
# include <iostream>
# include <sstream>
# include <cmath>
# include <string>
# include <limits>

# define MB "\x1b[1m\x1b[38;2;25;25;599m"
# define C "\x1b[0m"

class ScalarConverter {
	public:
		// ScalarConverter(void);
		// ScalarConverter(ScalarConverter const & src);
		// ~ScalarConverter(void);
		// ScalarConverter & operator=(ScalarConverter const & rhs);

		static void convert(std::string const & str) {
			std::cout << "Input str: " << str << std::endl;

			if (str.length() == 1 && !isdigit(str[0])) { // char
				if (std::isprint(str[0]))
					std::cout << "char: " << MB << "'" << (std::isprint(str[0]) ? std::string(1, str[0]) : ":Non displayable") << "'" << C << std::endl;
				std::cout << C "int: " MB << static_cast<int>(str[0]) << std::endl;
				std::cout << C "float: " MB << static_cast<float>(str[0]) << "f" << std::endl;
				std::cout << C "double: " MB << static_cast<double>(str[0]) << std::endl;
				return;
			}
			else if (str.length() == 1 && isdigit(str[0])) { // digit
				if (std::isprint(str[0]))
					std::cout << "char: " << MB << "'" << (std::isprint(str[0] -48) ? std::string(1, str[0]) : "Non displayable") << "'" << C << std::endl;
				std::cout << C "int: " MB << str[0] << std::endl;
				std::cout << C "float: " MB << str[0] << ".0f" << std::endl;
				std::cout << C "double: " MB << str[0] << ".0" << std::endl;
				return;
			}
			else if (str == "nan" || str == "nanf") {
				std::cout << C "char: " MB << "impossible" << std::endl;
				std::cout << C "int: " MB << "impossible" << std::endl;
				std::cout << C "float: " MB << "nanf" << std::endl;
				std::cout << C "double: " MB << "nan" << std::endl;
				return;
			}
			else if (str == "inf" || str == "inff") {
				std::cout << C "char: " MB << "impossible" << std::endl;
				std::cout << C "int: " MB << "impossible" << std::endl;
				std::cout << C "float: " MB << "inff" << std::endl;
				std::cout << C "double: " MB << "inf" << std::endl;
				return;
			}
			else if (str == "-inf" || str == "-inff") {
				std::cout << C "char: " MB << "impossible" << std::endl;
				std::cout << C "int: " MB << "impossible" << std::endl;
				std::cout << C "float: " MB << "-inff" << std::endl;
				std::cout << C "double: " MB << "-inf" << std::endl;
				return;
			}
			else if (str == "+inf" || str == "+inff") {
				std::cout << C "char: " MB << "impossible" << std::endl;
				std::cout << C "int: " MB << "impossible" << std::endl;
				std::cout << C "float: " MB << "+inff" << std::endl;
				std::cout << C "double: " MB << "+inf" << std::endl;
				return;
			}
			else {
			try {
				if (std::isprint(str[0]))
					std::cout << "char: " << MB << "'" << (std::isprint(convertTo<int>(str)) ? std::string(1, str[0]) : "Non displayable") << "'" << C << std::endl;
			} catch (std::exception & e) {
				std::cout << C "char: " MB << "impossible" << std::endl;
			}
			try {
				int i = convertTo<int>(str);
				std::cout << C "int: " MB << i << std::endl;
			} catch (std::exception & e) {
				std::cout << C "int: " MB << "impossible" << std::endl;
			}
			try {
				float f = convertTo<float>(str);
				std::cout << C "float: " MB << f << "f" << std::endl;
			} catch (std::exception & e) {
				std::cout << C "float: " MB << "impossible" << std::endl;
			}
			try {
				double d = convertTo<double>(str);
				std::cout << C "double: " MB << d << std::endl;
			} catch (std::exception & e) {
				std::cout << C "double: " MB << "impossible" << std::endl;
			}

			}


			
			
		}
		private:
			template <typename T>
			static T convertTo(std::string const & str) {
				std::stringstream ss(str);
				T result;
				if (!(ss >> result))
					throw std::exception();
				
				if (result == std::numeric_limits<T>::infinity() || result == -std::numeric_limits<T>::infinity())
					throw std::exception();
				
				return result;
			}
};

#endif