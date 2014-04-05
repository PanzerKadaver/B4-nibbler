##
## Makefile for  in /home/aubert_n/rep/nibbler/Nibbler5.0/lib_nibbler_QPaint
## 
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
## 
## Started on  Sat Apr  5 21:00:53 2014 Nathan AUBERT
## Last update Sat Apr  5 22:50:34 2014 Nathan AUBERT
##

CXX	=	g++
RM	=	rm -f
BIN	=	lib_nibbler_QPaint_$(HOSTTYPE).so
LN	=	lib_nibbler_QPaint.so
I_DIR	=	include

CXXFLAGS	+=	-W -Wall -Wextra #-Werror
#CXXFLAGS	+=	-ansi -pedantic
CXXFLAGS	+=	-fPIC #-Wpadded
CXXFLAGS  +=  -I. -I../
CXXFLAGS	+=	-I/usr/local/Trolltech/Qt-4.8.5/include                                          

LDFLAGS	+=	-L/usr/local/Trolltech/Qt-4.8.5/lib/
LDFLAGS +=	-lQtGui
LDFLAGS +=	-lQtCore
LDFLAGS +=	-ldl

SRCS	=	extern.cpp \
		Canvas.cpp \
		QtCanvas.cpp

OBJS	=	$(SRCS:.cpp=.o)

$(BIN):	$(OBJS)
	$(CXX) -shared -o $(BIN) $(OBJS) $(LDFLAGS) 
	ln -sf $(BIN) $(LN)

all:	$(BIN)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(BIN)
	$(RM) $(LN)

re:	fclean all

.PHONY:	all clean fclean re
