# mongoosecpp
C++11 wrapper for Mongoose library, which is an HTTP server.

Mongoose server is wrapped into Mongo::Server class. Request and Response are also wrapped.
There is also a Dispatcher class that wraps the Server to match URI resources into files, directories or functions.
There is a Template class that aids on page generation.

# COMPILE
Sorry! No makefile yet, so you need to set your favorite C++ compiler to C++11 and create a library with all files under src folder. 
Library clients should #include <mongoosecpp.h>, which includes all necessary header files from src subdirectories. 

# TEST
The directory mongotest has the sources for an application which has some usage for mongoosecpp.

# TODO
- add a makefile (compile and install)
- examples which have Dispatcher and Template usage
- verify static dispatching function to make sure there is no way to access resouces outside of resource tree
- improve getPostData function to retrieve data in chunks
