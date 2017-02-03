CC = gcc -g -Wall
#
# -g debug flag
#

shell: driver.o helpers.o string.o
	$(CC) -o shell driver.o helpers.o string.o
driver.o: driver.c driver.h
	$(CC) -c driver.c -o driver.o
helpers.o: helpers.c helpers.h
	$(CC) -c helpers.c -o helpers.o
string.o: string.c string.h
	$(CC) -c string.c -o string.o
clean:
	rm shell *.o
