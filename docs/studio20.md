# Studio 20
1. Aranna, Andy, Luke
2. It is necessary to delete the pointer to the actual file in the destructor 
so we can avoid a memory leak, since the protectedFile was allocated in the heap.

4. describe what tests you performed and what results you
   observed.
We tested simple commands such as creating the password to be written as "i love CS332", writing with a "hi" vector
string, calling write and read functions, and testing the output of getName and getSize functions. 

Enter a password
i love CS332
Enter a password
thing
0

when entered the correct password CS332, the code returned the correct getName output "thing" and 
correct size 0. 
5. We fortunately passed 37 of 37 results at once and did not require any debugging or failed test issue.
