# include "Replace.hpp"

int    replace( char *av, std::string s1, std::string s2 )
{
    std::string buf;
    std::string tinyBuf;
    std::ifstream file( av );
    if ( file.fail() )
    {
        std::cerr << "Error: could not open the file" << std::endl;
        return (1);
    }
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "The file is empty" << std::endl;
    }
    std::ofstream newFile( (std::string(av) + ".replace").c_str() );
    if ( !newFile.is_open() )
    {
        std::cerr << "Error: could not create the file" << std::endl;
        return ( 1 );
    }
    while (getline(file, buf))
        if (file.peek() != std::ifstream::traits_type::eof())
            replaceStrings(newFile, s1, s2, buf + '\n');  // Add newline for intermediate lines
        else
            replaceStrings(newFile, s1, s2, buf);  // No newline for the last line
    return ( 0 );
}

void	replaceStrings(std::ofstream &newFile, std::string s1, std::string s2, std::string buf)
{
	std::size_t	index;
	std::size_t	skip;

	index = buf.find(s1);
	if (index == std::string::npos)
	{
		newFile << buf;
		return ;
	}
	else
	{
		newFile << buf.substr(0, index);
		newFile << s2;
		skip = index + s1.length();
		replaceStrings(newFile, s1, s2, buf.substr(skip));
	}
}