CC=cc
FLAGS=-c -Wall 
LIBS=-lm
OBS=main.o livro.o livrotree.o files.o menus.o operacoes.o encomenda.o filaEnc.o

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
operacoes.o : livraria.h operacoes.c
	$(CC) $(FLAGS) operacoes.c
encomenda.o : livraria.h encomenda.c
	$(CC) $(FLAGS) encomenda.c
filaEnc.o : livraria.h filaEnc.c
	$(CC) $(FLAGS) filaEnc.c
livraria : $(OBS)
	$(CC)  -o livraria  $(OBS) $(LIBS) -lpthread
clean limpar:
	rm -f livraria *.o
	rm -f *~
	echo "Limpeza dos ficheiros exectuaveis, objectos e gedit tralha" 