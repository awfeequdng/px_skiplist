
skiplist: skiplist_test.c skiplist.h
	gcc -o skiplist $^

clean:
	rm *.o skiplist