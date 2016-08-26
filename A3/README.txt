****************************************************
Vanessa        0832498
CIS2520        A3
August 1st 2014
****************************************************

************
Compilation
************
cd to WhiteVanessaA3 folder

To compile the AVL Test Program:
    type 'make binary'

To compile the C File Test Program:
    type 'make file'

To compile File Manager:
    type 'make program'

***********************
Running the program(s)
***********************
To run the AVL Test Program:
    type 'bin/search'
    The test will proceeed

To compile the C File Test Program:
    type 'bin/fileTest'
    The Test will proceed

To compile File Manager:
    type 'bin/run directoryName'

    For the directory name, if you are located in the WhiteVanessaA3 Folder, just type "src" as the argument 2
        bin/run src
    Please only open directories located in my A3.


It will then have a menu display to prompt you to choose an option in this format:

Please choose from one of the following menu options by entering the corresponding number:
1. Search
2. Delete
3. Rename
4. Move
5. Quit

Please enter your choice now: 

The user then enters their choice from 1 - 5

1. Searches the tree for the file they inputted
2. Deletes the file name that the user inputted 
3. Renames the file that the user inputted
4. Moves the file to the path that the user inputted
5. Quit the program

A design choice I made was the looping function when they put invalid input. I used this because the user may not understand the instructions and put in wrong input.


*****************
Known Limitations
*****************

- It will store all the files and directories into the tree when printing, but when searching it will not work
    this is an issue when a directory has more than 1 file...you are able to search one the the files successfully
-delete does not balance
-does not use regex'
-if the directories and subdirectories have 1 file each in them , the program will work smoothly 
    couldn't fix this bug

    -if directory is empty may seg fault
    -compatibility ons erver is weird
    -can only search and manipulate one file in directory

*******************************
Academic Integrity Pledge
*******************************

I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased.  Furthermore,
I certify that this assignment was prepared by me specifically for this course.


