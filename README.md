# preload_printf

Example of a preload dynamic library that hooks printf() and puts().


<!-- mdtoc-start -->
&bull; [preload_printf](#preload_printf)  
&nbsp;&nbsp;&nbsp;&nbsp;&bull; [License](#license)  
&nbsp;&nbsp;&nbsp;&nbsp;&bull; [Introduction](#introduction)  
<!-- TOC created by '../mdtoc/mdtoc.pl README.md' (see https://github.com/fordsfords/mdtoc) -->
<!-- mdtoc-end -->

## License

I want there to be NO barriers to using this code, so I am releasing it to the public domain.  But "public domain" does not have an internationally agreed upon definition, so I use CC0:

Copyright 2020 Steven Ford http://geeky-boy.com and licensed
"public domain" style under
[CC0](http://creativecommons.org/publicdomain/zero/1.0/):
![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png "CC0")

To the extent possible under law, the contributors to this project have
waived all copyright and related or neighboring rights to this work.
In other words, you can use this code for any purpose without any
restrictions.  This work is published from: United States.  The project home
is https://github.com/fordsfords/preload_printf

To contact me, Steve Ford, project owner, you can find my email address
at http://geeky-boy.com.  Can't see it?  Keep looking.


## Introduction

It is rare, but not unheard of, that one wants to hook (intercept) function
calls normally handled by an existing dynamic library
(either one of yours, or a system library like glibc).
For example, Onload hooks socket functions and Hoard hooks memory functions.

In this example, I hook the printf() and puts() functions.
Why both?
Because gcc will convert simple calls to printf() to puts() if it can.
For example, 'printf("Hello world!\n")' will get converted to
'puts("Hello world")'.
(This is demonstrated in this repository.)
