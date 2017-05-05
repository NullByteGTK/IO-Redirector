# IO Redirector
A simple C program for redirecting a file's content, a command's output or user input to another program

Usage:<br>
  ./redirect | \<program\>
  
If you want to redirect a command's output type the command with a $ before it (ex: $echo hi => hi)<br>
If you want to redirect a file's content type the file's address starting with # (ex: #/home/null/ex.txt)<br>
If you want it to redirect what you type you don't have to do anything special just type what you want to


*If your input starts with \ or $ or # but you dont want it to be treated as a file or command put a \ before it:<br>
  ex: \\$hello => $hello<br>
  ex: \\#hello => #hello<br>
  ex: \\\hello => \hello

*the backslash will be ignored only when its the first char in the input<br>
  ex: \hi => hi<br>
  but<br>
  ex: h\i => h\i
  
If you found any bugs please report them to me<br>
Contact: nullbytegtk@gmail.com
