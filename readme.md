## DURING DEVELOPMENT, README MAY OR MAY NOT BE UP TO DATE ##

## Technologies ##
 - Used Visual Studio Code as my editor
 - Ubuntu as the OS
 - Make sure you have **CMake** on your computer
    - On Ubuntu, the command is **sudo apt-get install cmake**

## Building the Project ##
 - Using CMake for builds. Create a builds folder by executing **mkdir build** at the root of the project. Then the file structure should look like the following:
 ```text
BusyBiscuits_Database
    +---src
    +---build               <------ New Folder
    +---.gitignore
    +---CMkakesList.txt
    +---readme.md
    +---run.sh
    +---build.sh
    +---buildandrun.sh
    +---LICENSE
```
 - There are bash scripts used to utilize the CMake files. Then you can execute the GenerateMakeFiles.sh file to use CMake to generate the make files for both the main program and for the tests
```
./GenerateMakeFiles.sh
```
 - If you want to run the main program, execute the following command
```
./ExecuteMainMakeFiles.sh
```
 - If you want to run the tests, execute the following command
```
./ExecuteTestMakeFiles.sh
```
