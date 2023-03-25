CC = gcc


single: single.o beggar.o shuffle.o
	gcc single.o shuffle.o beggar.o -lgsl -lgslcblas -o single -lm

byn: byn.o shuffle.o beggar.o
	gcc byn.o shuffle.o beggar.o -lgsl -lgslcblas -o byn -lm
