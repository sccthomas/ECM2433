CC = gcc

#demo_shuffle: demo_shuffle.o shuffle.o
#	gcc -o demo_shuffle demo_shuffle.o shuffle.o  -lgsl -lgslcblas -lm


single:
	gcc single.c shuffle.c beggar.c -lgsl -lgslcblas -o single -lm

byn:
	gcc byn.c shuffle.c beggar.c -lgsl -lgslcblas -o byn -lm
