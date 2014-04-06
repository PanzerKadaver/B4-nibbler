##
## Makefile for  in /home/aubert_n/rep/nibbler/Nibbler5.0/lib_nibbler_QPaint
## 
## Made by Nathan AUBERT
## Login   <aubert_n@epitech.net>
## 
## Started on  Sat Apr  5 21:00:53 2014 Nathan AUBERT
## Last update Sun Apr  6 17:12:38 2014 Nathan AUBERT
##

CXX	=	g++
RM	=	rm -f
BIN	=	lib_nibbler_Qt_$(HOSTTYPE).so
LN	=	../lib_nibbler_Qt.so
I_DIR	=	include

CXXFLAGS +=	-W -Wall -Wextra
CXXFLAGS +=	-fPIC
CXXFLAGS +=	-I. -I../
CXXFLAGS +=	-I/usr/local/Trolltech/Qt-4.8.5/include                                          

LDFLAGS	+=	-L/usr/local/Trolltech/Qt-4.8.5/lib/
LDFLAGS +=	-lQtGui
LDFLAGS +=	-lQtCore
LDFLAGS +=	-ldl

SRCS	=	extern.cpp \
		Canvas.cpp \
		QtCanvas.cpp

OBJS	=	$(SRCS:.cpp=.o)

$(BIN):	$(OBJS)
	@echo -e "\E[33;33mCompiling Qt library...\E[33;37m"
	$(CXX) -shared -o $(BIN) $(OBJS) $(LDFLAGS) 
	@echo -e "\E[33;33mLinking Qt library...\E[33;37m"
	ln -sf ./lib_nibbler_Qt/$(BIN) $(LN)

all:	$(BIN)

clean:
	@echo -e "\E[33;33mCleaning Qt object files...\E[33;37m"
	$(RM) $(OBJS)

fclean:	clean
	@echo -e "\E[33;33mCleaning Qt binaries, links...\E[33;37m"
	$(RM) $(BIN)
	$(RM) $(LN)

re:	fclean all

.PHONY:	all clean fclean re
