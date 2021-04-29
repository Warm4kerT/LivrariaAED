CC=cc
FLAGS=-c -Wall 
LIBS=-lm
OBS=main.o livro.o livrotree.o files.o menus.o

#Alvo por defeito é o primeiro
all :  livraria

main.o : livraria.h main.c
	$(CC) $(FLAGS) main.c -lpthread
livro.o : livraria.h livro.c
	$(CC) $(FLAGS) livro.c
livrotree.o : livraria.h livroTree.c
	$(CC) $(FLAGS) livroTree.c
files.o : livraria.h files.c
	$(CC) $(FLAGS) files.c
menus.o : livraria.h menus.c
	$(CC) $(FLAGS) menus.c
livraria : $(OBS)
	$(CC)  -o livraria  $(OBS) $(LIBS) -lpthread
clean limpar:
	rm -f livraria *.o
	rm -f *~
	echo "Limpeza dos ficheiros exectuaveis, objectos e gedit tralha" 