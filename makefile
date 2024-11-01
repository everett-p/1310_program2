All				:		DRIVER

DRIVER			:		Driver.o LinkedList.o ListNode.o InvItem.o
						g++ -o Driver.exe Driver.o LinkedList.o ListNode.o InvItem.o

Driver.o		:		Driver.cpp
						g++ -I ./ -c Driver.cpp

LinkedList.o	:		LinkedList.cpp LinkedList.h
						g++ -I ./ -c LinkedList.cpp

ListNode.o		:		ListNode.cpp ListNode.h
						g++ -I ./ -c ListNode.cpp

InvItem.o		:		InvItem.cpp InvItem.h
						g++ -I ./ -c InvItem.cpp

clean			:		Dirver.exe	
						rm *.o *.exe
						del *.o *.exe