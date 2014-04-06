##
## Makefile for  in /home/aubert_n/qt
##
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
##
## Started on  Fri Mar 21 14:07:56 2014 Nathan AUBERT
## Last update Sun Apr  6 15:34:43 2014 Nathan AUBERT
##

CXX	= g++ -g3

RM	= rm -f

QT	= "./lib_nibbler_Qt/"
SFML	= "./lib_nibbler_SFML/"
OPENGL	= "./lib_nibbler_OpenGL/"

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

all:	$(NAME)

$(MY_LIBS):
	$(MAKE) -C $@;

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)
	$(MAKE) -C $(QT);
	$(MAKE) -C $(SFML);
#	$(MAKE) -C $(OPENGL);

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(QT) clean;
	$(MAKE) -C $(SFML) clean;
#	$(MAKE) -C $(OPENGL) clean;

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(QT) fclean;
	$(MAKE) -C $(SFML) fclean;
#	$(MAKE) -C $(OPENGL) fclean;

re:	fclean all
	$(MAKE) -C $(QT) re;
	$(MAKE) -C $(SFML) re;
#	$(MAKE) -C $(OPENGL) re;

.PHONY: all clean fclean re
