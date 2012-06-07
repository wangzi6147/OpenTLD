 Introduction
==============

This is a C++ implementation of OpenTLD that was originally published in MATLAB by Zdenek Kalal. It builds Georg Nebehay's fork as a library that you can use in your programs. OpenTLD is used for tracking objects in video streams. What makes this algorithm outstanding is that it does not make use of any training data. This implementation is based solely on open source libraries, meaning that you do not need any commercial products to compile or run it.

The easiest way to get started is to download the precompiled binaries that are available for Windows and Ubuntu 10.04. You can get a .deb package here:
http://dl.dropbox.com/u/8715460/tld.deb
and a windows installer file here:
http://dl.dropbox.com/u/8715460/tld.zip

 Building
=========

Dependencies
------------

* OpenCV & OpenCV highgui >= 2.0
* CMake >= 2.6

Compiling
---------

Use CMake to build the project. You can use "cmake-gui", if you need a graphical user interface.

* CMake
	* Specify the source path (root path of the dictionary) and the binary path (where to build the program, out
	  of source build recommended)
	* Configure
	* Select compiler
	* Define the install path and other options
	* Generate
* Windows: go to the binary directory and build the solutions you want (You have to compile in RELEASE mode):
	* opentld: build the project
	* INSTALL: install the project
* Linux: go with the terminal to the build directory
	* make: build the project
* Mac
	* brew install python
	* brew install gfortran
	* easy_install numpy
	* brew install cmake
	* brew install opencv
	* mkdir build
	* cd build
	* cmake ..
	* cd ..
	* make
	* ./opentld

Generate Package
----------------

* Debian package
	* Navigate with the terminal into the root dictionary of OpenTLD (OpenTLD/)
	* Type `debuild -us -uc`
	* Delete the temporary files in the source tree with `debuild clean`

