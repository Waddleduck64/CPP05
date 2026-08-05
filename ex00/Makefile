NAME := bureaucracy
CXX := c++
CFLAGS := -Wall -Wextra -Werror -std=c++20 $(if $(DEBUG), -g) $(if $(FSAN), -fsanitize=address -fsanitize=leak)
SRCS := main.cpp Bureaucrat.cpp
ODIR := obj
OBJS := $(SRCS:%.cpp=$(ODIR)/%.o)
DEPS := $(OBJS:.o=.d)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(ODIR)/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -MP -MMD -c $< -o $@

clean :
	rm -rf $(ODIR)

fclean : clean
	rm -rf $(NAME) a.out

re : fclean all

debug :
	$(MAKE) re DEBUG=1

fsan :
	$(MAKE) re DEBUG=1 FSAN=1

-include $(DEPS)

.PHONY : all clean fclean re debug fsan