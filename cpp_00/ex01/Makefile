CPP = c++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98
PROGRAM_NAME = phonebook

SRCDIR := ./
CLASS_DIR := $(SRCDIR)/class

SRC = $(SRCDIR)/main.cpp \
      $(CLASS_DIR)/Contact.cpp \
      $(CLASS_DIR)/PhoneBook.cpp

INCDIR := ./includes
INCLUDES := -I$(INCDIR)

OBJDIR := objs
OBJS = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)/class

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re
