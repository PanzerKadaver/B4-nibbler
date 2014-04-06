##
## Makefile for  in /home/aubert_n/qt
##
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
##
## Started on  Fri Mar 21 14:07:56 2014 Nathan AUBERT
## Last update Sun Apr  6 11:16:36 2014 Nathan AUBERT
##

CXX = clang++ -g3

RM = rm -f

CXXFLAGS += -W -Wextra -Wall
CXXFLAGS += -I/usr/local/SFML-2.1/include/SFML
CXXFLAGS += -I/usr/local/Trolltech/Qt-4.8.5/include

LDFLAGS += '-Wl,-rpath=/usr/local/GLEW/lib'
LDFLAGS += '-Wl,-rpath=/usr/local/SFML-2.1/lib'
LDFLAGS += -L/usr/local/Trolltech/Qt-4.8.5/lib/
LDFLAGS += -L/usr/local/SFML-2.1/lib/
LDFLAGS += -L/usr/local/GLEW/lib
LDFLAGS += -L/usr/lib64
LDFLAGS += -lsfml-graphics
LDFLAGS += -lsfml-window
LDFLAGS += -lsfml-system
LDFLAGS += -lQtGui
LDFLAGS += -lQtCore
LDFLAGS += -lGLU
LDFLAGS += -lGLEW
LDFLAGS += -lGL
LDFLAGS += -ljpeg
LDFLAGS += -ldl


NAME = nibbler

SRCS =	EventManager.moc.cpp \
	GameManager.cpp \
	Land.cpp \
	main.cpp \
	Snake.cpp

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
