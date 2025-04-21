SRCS =	main.cpp \
		Animal.cpp \
		Cat.cpp \
        Dog.cpp \
		Brain.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = brains
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

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