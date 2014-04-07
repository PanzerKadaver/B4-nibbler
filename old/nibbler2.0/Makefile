##
## Makefile for  in /home/aubert_n/qt
## 
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
## 
## Started on  Fri Mar 21 14:07:56 2014 Nathan AUBERT
## Last update Fri Mar 21 20:24:30 2014 Nathan AUBERT
##

CC = clang++ -g3

RM = rm -f

CXXFLAGS += -W -Wextra -Wall
CXXFLAGS += #-ansi -pedantic
CXXFLAGS += -I/usr/local/Trolltech/Qt-4.8.5/include

LDFLAGS += -L/usr/local/Trolltech/Qt-4.8.5/lib/
LDFLAGS += -lQtGui
LDFLAGS += -lQtCore
LDFLAGS += -ldl

NAME = snqkePourLesNuls

SRCS =	GameManager.cpp \
	Land.cpp \
	main.cpp \
	Point.cpp \
	Traductor.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
