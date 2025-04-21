#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./btc [input_file]" << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange;

    std::ifstream file(av[1]);
    std::string line;
    bool firstLine = true;

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "Error: empty input file." << std::endl;
    }

    //std::getline(file, line); // Skip the first line (header)
    while (std::getline(file, line))
    {
        // Check if the line is empty or if it contains only whitespace
        std::string trimmedLine = line;
        trimmedLine.erase(0, trimmedLine.find_first_not_of(" \t\n\r\f\v")); // Trim leading whitespace
        trimmedLine.erase(trimmedLine.find_last_not_of(" \t\n\r\f\v") + 1); // Trim trailing whitespace
        if (trimmedLine.empty())
            continue; // Skip empty lines
        if (line.empty())
            continue; // Skip empty lines

        if (firstLine)
        {
            std::string lowercaseLine = trimmedLine;
            std::transform(lowercaseLine.begin(), lowercaseLine.end(), lowercaseLine.begin(), ::tolower);
    
            if (lowercaseLine.find("date") != std::string::npos &&
                lowercaseLine.find("value") != std::string::npos)
            {
                firstLine = false;
                continue; // Skip header line
            }
        }
    
        firstLine = false;

        try
        {
            bitcoinExchange.checkForValue(line);
        }
        catch(const BitcoinExchange::BadDateException &e)
        {
            std::cerr << e.what() << line << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
    return 0;
}
