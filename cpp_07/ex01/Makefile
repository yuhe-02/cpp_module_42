CPP = c++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

PROGRAM_NAME = iter

SRCDIR := .
INCDIR := ./includes

SRC := $(wildcard $(SRCDIR)/*.cpp) 
INCLUDES := $(addprefix -I, $(INCDIR))

OBJDIR := objs
OBJS := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/$(SRCDIR)/%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re
