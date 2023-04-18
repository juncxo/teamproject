# Studio 19
1. Aranna, Luke, Andy
2. In our main, as of now, where we have commeneted out all the code content from the read() function,
we created a text file and write content and append content into the file. Those work until we try to read 
the file, then we get an error because we don't have an return statement yet for the read() function even 
though we changed it to be returning a vector of characters.
3. We start with the visitor where we include the Image and Text files. From there, we go to Abstract File where
we forward declare AbstractFileVisitor class so then we can use it in the function decleration for accept(). This 
connects the visitor class to our concrete classes. And then in our header file, since it includes our abstract file, 
we can connect the function in there. During the definition in the source file, we include the visitor class that 
enables us to call member functions from the visitor class.