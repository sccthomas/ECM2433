CC = gcc

#demo_shuffle: demo_shuffle.o shuffle.o
#	gcc -o demo_shuffle demo_shuffle.o shuffle.o  -lgsl -lgslcblas -lm


demo_shuffle:
	gcc demo_shuffle.c riffle.c -o demo_shuffle -lm

quality:
	gcc quality.c riffle.c -o quality -lm
