## Building the Project ##
 - Using CMake for builds. Create a builds folder at the root so that the file structure looks like the following:
BusyBiscuits_Database
    +---src
    +---build
    +---.gitignore
    +---CMkakesList.txt
    +---readme.md
    +---run.sh
    +---build.sh
    +---buildandrun.sh
    +---LICENSE
 - To build the project through the terminal, stay in the root of the project and execute the build shell script as follows:
    **./build.sh**
    Then execute the run script:
    **./run.sh**
    And that should run the executable in the terminal. Another script was created to do the build and run script together. Execute the build and run script:
    **./buildandrun.sh**
    to compile all the necessery files and created the executable
