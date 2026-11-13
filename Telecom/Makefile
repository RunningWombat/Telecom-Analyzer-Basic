CC = gcc
CFLAGS = -Wall -std=c99

telecom_analyzer_1377739: main.o log_io.o analytics.o billing.o search.o
	$(CC) $(CFLAGS) -o telecom_analyzer_1377739 main.o log_io.o analytics.o billing.o search.o
    
main.o: main.c telecom.h 
	$(CC) $(CFLAGS) -c main.c -o main.o
    
log_io.o: log_io.c telecom.h 
	$(CC) $(CFLAGS) -c log_io.c -o log_io.o
    
analytics.o: analytics.c telecom.h 
	$(CC) $(CFLAGS) -c analytics.c -o analytics.o
    
billing.o: billing.c telecom.h 
	$(CC) $(CFLAGS) -c billing.c -o billing.o
    
search.o: search.c telecom.h 
	$(CC) $(CFLAGS) -c search.c -o search.o
    
clean:
	rm -f *.o telecom_analyzer_1377739 success.csv dropped.csv
