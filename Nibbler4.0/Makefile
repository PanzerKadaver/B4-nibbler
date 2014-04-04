##
## Makefile for  in /home/aubert_n/qt
##
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
##
## Started on  Fri Mar 21 14:07:56 2014 Nathan AUBERT
## Last update Fri Apr  4 19:58:53 2014 Nathan AUBERT
##

CXX = clang++ -g3

RM = rm -f

CXXFLAGS += -W -Wextra -Wall
CXXFLAGS += #-ansi -pedantic
CXXFLAGS += -I/usr/local/SFML-2.1/include
CXXFLAGS += -I/usr/local/Trolltech/Qt-4.8.5/include

#LDFLAGS += -L/usr/local/Trolltech/QtEmbedded-4.8.5/lib/
LDFLAGS += -L/usr/local/Trolltech/Qt-4.8.5/lib/
LDFLAGS += -L/usr/local/SFML-2.1/lib/
LDFLAGS += -lQtGui
LDFLAGS += -lQtCore
LDFLAGS += -ldl

NAME = nibbler

SRCS =	main.cpp \
	GameManager.cpp \
	Cell.cpp \
	Land.cpp \
	Snake.cpp \
	Canvas.cpp \
	Event.moc.cpp \
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
