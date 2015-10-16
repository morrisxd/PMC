<<<<<<< HEAD
#
# xxx.l and xxx.o MUST have the idential 'xxx' filename, and the same, 
# xxx.y and xxx.o MUST have the idential 'xxx' filename.

# We use sample file cah_126e1.i

################################################################
# We cannot use 'bison' because bison would not generate y.tab.c file. 
# Standard YACC will do. And make program will execute mv -f y.tab.c 
# filename.c
# YACC   = bison
YFLAGS = -d -v
OBJS = expr.o
expr:	$(OBJS)
	cc $(OBJS) -ll -o expr
clean:
	rm -f *.o y.tab.h cl *.core *.BAK y.output
=======
#
# xxx.l and xxx.o MUST have the idential 'xxx' filename, and the same, 
# xxx.y and xxx.o MUST have the idential 'xxx' filename.

# We use sample file cah_126e1.i

################################################################
# We cannot use 'bison' because bison would not generate y.tab.c file. 
# Standard YACC will do. And make program will execute mv -f y.tab.c 
# filename.c
YACC   = bison
YFLAGS = -d -v -y
OBJS = expr.o
expr:	$(OBJS)
	cc $(OBJS) -ll -o expr
clean:
	rm -f *.o y.tab.h cl *.core *.BAK y.output
>>>>>>> 26367c5e5efc49e0321b0abfa018e3da71d41acf
