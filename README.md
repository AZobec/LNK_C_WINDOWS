## Main Goal ##
My main goal by doing this is to understand how does it really work, what is a COM Object, what is a Shell Link, what is really a LNK file, etc..

I have seen a propagation technique used by vjw0rm to propagate himself, by creating LNK file in VBS, by executing a command when clicking on LNK.

So I decided to see if it was possible in C, create a LNK and modify the attributes of this kind of file.

I coded this POC under Visual Studio, and debugging in x64.

For understanding that, I invite you to read the article about Shell Links (below). A shortcurt is a Shell Link (in forensics, you may used to Jumplist. It's a quite similar technique). 

Now we just have to understand how to manipulate this object and how to modify it's structure by reading several documentations.

#### Links ####
Thanks to [https://www.codeproject.com/Articles/11467/How-to-create-short-cuts-link-files] . I modified and debugged his sourcecode for C

#### Research ####
[http://forensicswiki.org/wiki/LNK]

[http://forensicswiki.org/wiki/Shell_Item]

[https://msdn.microsoft.com/en-us/library/windows/desktop/ms680573(v=vs.85).aspx]


#### Functions and docs ####
[https://msdn.microsoft.com/en-us/library/bb776891(VS.85).aspx] ==> Shell Links

[https://msdn.microsoft.com/en-us/library/ms678543(v=vs.85).aspx] ==> CoInitialise Function
	
[https://msdn.microsoft.com/fr-fr/library/windows/desktop/bb774950(v=vs.85).aspx] ==> IShellLink Interface

[https://msdn.microsoft.com/fr-fr/library/windows/desktop/ms687223(v=vs.85).aspx] ==> IPersistFile Interface

[https://msdn.microsoft.com/en-us/library/ms886232.aspx] ==> CoCreateInstance to Create the object

[https://doxygen.reactos.org/d0/d95/shlguid_8h.html] ==> to know all

[https://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx] ==> Windows Types

