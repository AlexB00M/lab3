@Echo off
gcc -c main.c -o main.o
gcc -c data_base.c -o data_base.o
gcc -c start_params.c -o start_params.o
gcc -c publication.c -o publication.o
gcc -c file.c -o file.o
gcc -c random.c -o random.o
gcc -c sort.c -o sort.o
gcc main.o data_base.o start_params.o publication.o file.o random.o sort.o -o main.exe
del main.o data_base.o start_params.o publication.o file.o sort.o