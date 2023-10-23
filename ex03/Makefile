CXX      := c++
CXXFLAGS := -g -MMD -MP -Wall -Wextra -Werror -std=c++98
DFLAGS   := -fsanitize=address -fsanitize=undefined -fsanitize=bounds
INCLUDE  :=
NAME     := a.out
SRCS     := main.cpp Fixed.cpp Point.cpp
OBJS     := $(SRCS:.cpp=.o)
DEPENDS  := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CXX) -o $@ $^ $(INCLUDE) $(CXXFLAGS) $(if $(DEBUG),$(DFLAGS),)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(if $(DEBUG),$(DFLAGS),) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) -r $(OBJS) $(DEPENDS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	make DEBUG=1

-include $(DEPENDS)

.PHONY: all clean fclean re
