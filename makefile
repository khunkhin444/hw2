all: main.c arr.c bs.c not_bs.c ll.c hash.c arr.h bs.h not_bs.h ll.h hash.h
	gcc main.c arr.c arr.h bs.c bs.h not_bs.c not_bs.h ll.c ll.h hash.c hash.h -o execute
clean: 
	rm -f execute
