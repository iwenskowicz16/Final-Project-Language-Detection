# Final-Project-Language-Detection
Our Final Project


###Milestone2###
#Problems:
	1. Implementing the similarity function
	2. Calling the similarity function on the files
	3. Checking for valid command line arguments
#Problem 1
	To implement the similarity function we write a function that takes two frequency objects as parameters.
	The function would then compute the similarity of the two vectors and return it as a double.
	We could write this as a method of the frequency class that we are writing
#Problem 2
	Calling the similarity function on the files given from the command line would give us our programs desired output
	We would call the similarity function on the test data and every training data that was passed to our program
	We would use a loop to loop through calling the similarity function on the test data and every training data
	Whichever training data had the highest frequency would be the file name that we output
#Problem 3
	In the main function, we will have an if statement that checks if argc is greater then 1 if it is then the program will proceed as normal, else it will exit
	It will then try to open all of the files that were passed to it and if it can't it will exit
	If the program can do both of these then it will continue as normal
	
##Libraries Needed
	string
	vector
	iostream
	ifstream
	ofstream
	cstdlib
