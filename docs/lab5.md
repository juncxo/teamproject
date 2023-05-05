# Lab 5
Name: Aranna Tasnim <a.tasnim>
Andy Cho
Luke Zhang 

Work Distribution:
Studio: Documentation writing split between Aranna and Andy. Debugging and multiple office hours attended by Aranna. 
Studio 16 typing by Andy. Rest of the typing was split between the 3 of us, taking turns in each of the studios working
on Aranna's computer, although Luke did a good amount of the typing. 

Lab: First half of the lab, Aranna and Luke focused on typing the code. Second half, Andy and Luke focused on typing. 
Although not everyone was able to be around the whole time, whole group met everyday to work, including office hours.
Andy spent most amount of time at office hours. Documentation, comments and debugging test/lab5.cpp was done by Aranna.
A significant amount of the solutions ideas for the problems was proposed by Luke. There isn't a specific method or file
that anyone specifically did alone. 

Bugs:
1. We had confusion on how to implement the LSCommand::execute() function because we didn't know how to account for the 
two different inputs of 'ls' and 'ls -m' so then we passed in the whole input to be checked in the the execute function 
without doing any modification in the run() function.
2. While doing ls command, we were opening the files and only displaying the files that were manually opened 
on Lab5.cpp so we had issues doing 'ls -m' command. Later, we changed our code to not open files manually before running 
the run() function, rather do it in the LSCommand::execute() function. Furthermore, our MetadataDisplay initially wasn't 
formatted to match the way the 'ls -m' command should print its informations. So, we went back into MetadataDisplay to 
reformat than what we had from the studio.
3. Since we had the run() function to pass in the whole input from the user, in our next function implementations, we 
had to add the functionality of finding a space in the input to separate the command from the filename. After adding this,
the command behaved as desired. 
4. In our original understanding, we were extending SimpleFileSystem only for all our commands. However, in the test 
file, we saw that the commands were accepting a SimpleFileSystem object that was declared from AbstractFileSystem. So, it
was a simple fix to go and change the parameters passed in the constructors of each of the commands.
5. Implementing the touch function, we initially had an issue because we were not truncating the input to remove ' -p' 
when that was added. However, we were able to pinpoint the issue using the debugger. The fix was to get the substring of 
the input by excluding the last 3 characters of the input.
6. Copy command was giving us an issue as the new file it created didn't include it's extension. Initially, we were manually
adding but Professor said that was not allowed. So in our TextFile.cpp and ImageFile.cpp, in the clone function, we added
the extension to the filename before returning the file back in the CopyCommand file.
7. Initially, we had issues implementing MacroCommand simply because we failed to understand what the function was supposed
to do. Once clarification was obtained, we were able to implement the method by parsing through the input and then calling
execute on the list of commands that parsing returned. 
8. There was error afterwards as the execute was being called with the files names but because our execute are all implement
in the way that the parameter's first word is the command itself followed by rest of the input. So to tackle this error, 
we passed in "command " in our execute. This then helped the functions behave as it is supposed to.
9. Implementing the additional macrocommand, the program kept failing. After running the debugger, we noticed that it was 
due to EditDisplay::parse() returning a vector of one size while it needed to return 2 because it's supposed to call execute
twice using that. So in the parse, we increased the size of the vector returned and the function behaved as desired.
10. However, our previous logic for all the method was giving issues in the testing phase. So we had to go back to all 
our methods to rework the logic for the inputs we were passing in. After reworking this, the run() function now passed in 
the input after the command and not the whole input. 


Tests ran:
As we built each of the commands, we called addcommand() to the new commands and ran it in clion. We created new objects 
for each command. Then manually added initial 4 files with content in it. During testing, we created other files using touch
and other commands. 
