Purpose of software:
	Reads unsigned numbers from binary files, and determines which numbers are prime. This assignment has different parts
	based around prime numbers, and each program has it's own functionality.

Developer:
	Iqra McIlveen

Development Date:
	April 11, 2018

Software Organization:
	- createBinary.c
	- isPrime.c, isPrime.o
	- singlePrime.c, singlePrime.o
	- singleSpawn.c, singleSpawn.o
	- multiSpawn.c, multiSpawn.o
	- bonus1.c, bonus1.o
	- multiSpawnSignal.c (not complete)
	- Makefile0, Makefile1, Makefile2, Makefile3, Makefilebonussection, Makefile4
	- prime.bin
	- prime.txt

Compilation Instructions:
				
	isPrime.c:
		Compilation:
			make -f Makefile0
		To run program:
			./isPrime (followed by a number of your choice)

	Task 1:
		Compilation: 
			make -f Makefile1
		To run program:
			./singleMorph prime.bin

	Task 2:
		Compilation: 
			make -f Makefile2
		To run program
			./singleSpawn prime.bin

	Task 3:
		Compilation:  
			make -f Makefile3
		To run program
			./multiSpawn prime.bin

	Bonus Section (Task 3):
		Compilation: 
			make -f Makefilebonussection
		To run program
			./bonus1 prime.bin
	Bonus Task 4:
		//not complete, no need to compile as of today


Issues:
	- No known issues
Notes:
	- Be paitent while spawning multiple children, time varies by system. (It may be slower on school computers.)
	- Since this a step by step program, Makefile0 must be compiled (isPrime executable required)
	- Bonus Task 4 is not complete as of now

Usage Instructions:		
	- Compile and run each program with the file you would like to read. In this case, prime.bin is the provided file.
