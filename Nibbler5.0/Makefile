##
## Makefile for  in /home/aubert_n/qt
##
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
##
## Started on  Fri Mar 21 14:07:56 2014 Nathan AUBERT
## Last update Sun Apr  6 16:42:37 2014 Nathan AUBERT
##

NO_COLOR	= \x1b[0m
OK_COLOR	= \x1b[32;01m
ERROR_COLOR	= \x1b[31;01m
WARN_COLOR	= \x1b[33;01m

OK_STRING	= $(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	= $(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING	= $(WARN_COLOR)[WARNINGS]$(NO_COLOR)

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

OBJS = 	$(SRCS:.cpp=.o)

all:	$(ECHO) $(NAME)

$(NAME):$(OBJS)
	@echo -e "\n\E[33;32mCOMPILING NIBBLER...\n\E[33;37m"
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo -e "\n\E[33;32mCOMPILING Qt LIBRARY...\n\E[33;37m"
	$(MAKE) -C $(QT);
	@echo -e "\n\E[33;32mCOMPILING SFML LIBRARY...\n\E[33;37m"
	$(MAKE) -C $(SFML);
	@echo -e "\n\E[33;32mCOMPILING OpenGL LIBRARY...\n\E[33;37m"
#	$(MAKE) -C $(OPENGL);

clean:
	@echo -e "\n\E[33;32mCLEANING OBJECTS FILES IN ALL DIRECTORIES...\n\E[33;37m"
	$(RM) $(OBJS)
	$(MAKE) -C $(QT) clean;
	$(MAKE) -C $(SFML) clean;
#	$(MAKE) -C $(OPENGL) clean;

fclean: clean
	@echo -e "\n\E[33;32mCLEANING OBJECTS FILES AND BINARIES, LINKS IN ALL DIRECTORIES...\n\E[33;37m"
	$(RM) $(NAME)
	$(MAKE) -C $(QT) fclean;
	$(MAKE) -C $(SFML) fclean;
#	$(MAKE) -C $(OPENGL) fclean;

re:	fclean all
	$(MAKE) -C $(QT) re;
	$(MAKE) -C $(SFML) re;
#	$(MAKE) -C $(OPENGL) re;

.PHONY: all clean fclean re
