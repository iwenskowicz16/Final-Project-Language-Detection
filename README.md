# Final-Project-Language-Detection
Our Final Project

Final-Project-Language-Detection
Ian Wenskowicz and Jacob Turner
So for the triagram and triagram frequency I can see it being fairly simple at it's base idea. There are a few small problems that it can be broken down into.
1. Reading each set of 3 letters.
2. Incrimention each set of 3 letters. 
3. Adding all 19k options without handwriting them.
4. Comparing each set of 3 letters.

So for each individual small issue:
1. We would probably use a method similar to what was used in a4 or a3 (i dont remember which) in order to read each set of 3. 
2. Each time a string would be read, any new one would be added to a vector<string>, and a spot on a respective vector<int> would be added, with the starting value of 1. When a repeat string would be read, the respective vector<int> would be incrimented.
3. We would likely make a triple nested loop which would add each possibility to a vector<string>, then create a vector<int> with the same size.
4. All the vectors above would be sorted. They would then be compared, and every time there was a matching vector<string>, the respective vector<int> from 3 would be replaced with the one from 2.

For how many classes are involved, based off of this design i can see most likely 2, maybe 3. The 2 would be a main place that mostly everything from milestone 1 would be written, then a similarity class for milestone 2.
There could be room for other classes, like objects, and that is what the 3rd is taken into acount for. 

Please note that I just realized that the object would be absolutely be needed.

There will be many functions/methods/variables. 
There would be a vector<obj> getFreq(vector<string> input); that would return the vector<string> and vector<int> mentioned in problem 2.
There would be a creator for the object, which has vector<string> and vector<int> inside.
There would be the getString and getInt functions for the object.
There would be the getResult function that would do problem 4.

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
