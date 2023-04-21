# Studio 19
1. Aranna, Luke, Andy
2. In our main, as of now, where we have commented out all the code content from the read() function,
we created a text file and write a vector content and append content into the file. The program finishes successfully with
a return value 0 as it doesn't run into any error. Since the read() function is no longer printing anything, the main
doesn't print anything either.
3. We start with the visitor where we include the Image and Text files. From there, we go to Abstract File where
we forward declare AbstractFileVisitor class so then we can use it in the function declaration for accept(). This 
connects the visitor class to our concrete classes. And then in our header file, since it includes our abstract file, 
we can connect the function in there. During the definition in the source file, we include the visitor class that 
enables us to call member functions from the visitor class.
4. Delegation in general refers to assigning the power of performing a task, for example, to somewhere else. Now, in terms
of what we are trying to accomplish here, we are letting the visitor have the power to perform a desired functionality
instead of using inheritance. So we connect the different classes by making a relationship between those through
forward calling the class. This way, the original family of classes is not being clutered while we are still able to add
further functionality to our program.
5. A negative consequence of visitor pattern is the code for are all spread apart in different files of the visitor objects
which can make the code difficult to read and understand because you have to follow the logic through the different files.