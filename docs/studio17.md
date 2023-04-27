# Studio 17
1) Aranna, Andy, Luke


2) Test the functionality of your ImageFile class. Describe the tests you ran as the answer
to this question.
we ran cout<<"test"<<endl; for the two different cases of error and ran write and read for the
{'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'} vector to see which cases the vector may fall into.
Every time the test fell into one of the two errors, whe analyzed why it well into that case and modified each
case so that we do not fall into any errors when inputing this example. We also tested for cases when we put
random characters that are not 'X' or ' ' and it returned the correct error output. We also tested the append function
and it returned the correct error.


3) An interface allows for abstraction: Defining methods and properties that a class needs to implement without  
providing their specific implementations. We thus can have classes extending from the same interface 
that behave and are implemented differently. Most notably, concrete classes requires an unnecessarily rigid 
approach to coding. 


4) To create objects of arbitrary file types, we would need to make the file extension customizable:
We would need to add a member variable to map file extensions to file types, the create method would
check the file extension of the string passed in and determine the corresponding file type using the map.
If the file extension of the string passed in doesn't exist in the map, a new file type will be created 
in that map. 
