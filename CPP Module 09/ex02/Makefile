SRCS =	main.cpp \
		PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = PmergeMe
CXX = c++
CXXFLAGS = -g -std=c++98 -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all