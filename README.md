# Zoo table viewer
A C++ app that allows users to create and view lists of objects.
 
This is my university project in software engineering. The original task was to make a C++ Windows application that can create, edit and view certain class objects. Now I'm looking forward to rewrite this app in C# and add more functions.  

Programm uses std::map to store objects of class Zoo and functionality of <algorythm.h> to perform some actions with this data.

Class Zoo.h

This class is just an example and theoreticaly any other class with simillar structure can be used here. Zoo.h contains information about zoo's name, total amount of spicies and amount of rare spicies that live in zoo. Also class have some technical info that used inside the programm and cannot be seen by user.

GUI

This programm was made in RAD Studio using VCL. Application has several windows to interact with user, the most important of them are start/table viewer window (aka TmainForm) that prints all objects at one place. TEditForm is used to edit existing objects or create new ones. TResultForm displays results of user requests (search requests for example), it should have been inherited from TmainForm. 

Search algorythm

App can search for certain items in collection using SQL-like system. Search request is constructed from parameters of Zoo class, if one of the fields of some item in collection matches one of the parameters than it will be stored in one of the three temporary collections, each storing items with same priority. Item's search priority is amount of matches with search request. Only items with max priority will be displayed as the result in TResultForm.
Algorythm has another mode that shows only items with all fields matching request.
