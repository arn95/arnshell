CC = gcc -g -Wall
#
# -g debug flag
#
shell: driver.o helpers.o string.o memwatch.o
	$(CC) -o shell driver.o helpers.o string.o memwatch.o
driver.o: driver.c driver.h
	$(CC) -c -DMEMWATCH -DMEMWATCH_STDIO driver.c -o driver.o
helpers.o: helpers.c helpers.h
	$(CC) -c -DMEMWATCH -DMEMWATCH_STDIO helpers.c -o helpers.o
memwatch.o: memwatch.c memwatch.h
	gcc -c memwatch.c -o memwatch.o
string.o: string.c string.h
	$(CC) -c -DMEMWATCH -DMEMWATCH_STDIO string.c -o string.o
clean:
	rm shell *.o