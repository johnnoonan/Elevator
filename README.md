# Elevator
Elevator program that tracks a users time spent in an elevator and which floors were visited.

**Build Details:**

This project was written in C++ and compiled using MinGW. 
I used VScode to write the program, and the g++ VScode extension to compile it. 

**How to use:**
Once ran, this program will then prompt the user to enter a list of comma separated floor values that they wish to visit in the elevator.

The program will return how much time was spent in the elevator and which floors were visited, in order.

**Assumptions:**

-This code is operating off the assumption that the input list is a string of comma separated floors that the user wishes to visit in order.

-This code assumes that only Integer values entered into the list are valid. Anything else, including doubles, invalid chars etc, will be ignored.
	For example, if "10, 2.5, #, abc, 5", is entered as the list.  The program will remove 2.5, #, and abc.  Then continue to run using the valid 
integers 10 and 5.

-This code assumes that the valid floor range is 0 up to the 163rd floor. This is the height of the Burj Khalif which has the record for most 	elevator floors in the world.

-This code assumes that duplicate entries are a miss click by the user and will be ignored.
	For example, if "10, 10, 5, 5, 5", is entered as the list.  The code will ignore the duplicates and continue to run using the list of 10, 5 
and count these as the only 2 valid floors visited, since we never left these floors.

