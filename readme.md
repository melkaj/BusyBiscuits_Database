## DURING DEVELOPMENT, README MAY OR MAY NOT BE UP TO DATE ##

## Building the Project ##
 - Using CMake for builds. Create a builds folder at the root so that the file structure looks like the following:
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
 - There are bash scripts used utilize the CMake files. First, make sure you have a build folder. 
```
mkdir build
```
 - Then you can execute the GenerateMakeFiles.sh file to use CMake to generate the make files for both the main program and for the tests
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
