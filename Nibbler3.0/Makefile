##
## Makefile for  in /home/aubert_n/qt
## 
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
## 
## Started on  Fri Mar 21 14:07:56 2014 Nathan AUBERT
## Last update Tue Apr  1 18:37:21 2014 Nathan AUBERT
##

CXX = clang++ -g3

RM = rm -f

CXXFLAGS += -W -Wextra -Wall
CXXFLAGS += #-ansi -pedantic
CXXFLAGS += -I/usr/local/Trolltech/Qt-4.8.5/include

LDFLAGS += -L/usr/local/Trolltech/Qt-4.8.5/lib/
LDFLAGS += -lQtGui
LDFLAGS += -lQtCore
LDFLAGS += -ldl

NAME = snqkePourLesNuls

SRCS =	main.cpp \
	Canvas.cpp \
	Event.cpp \
	Point.cpp \
	GameManager.cpp \
	QtCanvas.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
