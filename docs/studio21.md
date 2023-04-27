# Studio 21
1.Aranna, Luke, Andy


2. We need to declare a virtual destructor in the base class because we want to make sure that class slicing doesn't 
occur and that destruction sytarts from the derived class and then goes up to the base class.


3. It supports loosing coupling, which helps lose dependency on the file system, file factory, and command objects.


4. For our test, after setting up the main, we added two commands to see whether the addCommand() function works. Then,
we ran the program. When prompted to type, we tested with different input: "help touch", "touch", " random touch", "q".
Because we added another command through addCommand(), entering "help touch" and "help visitor" both called the displayIfo()
method and printed out it's information on the Touch file.
We ran into some errors that using the debugger, we traced back to the SimpleFileFactory.cpp createFile() method. After fixing
that, the program continued to run correctly.