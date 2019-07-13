# BookDataBase

Currently the code is work-in-progress, but can be compiled.

This code written to learn following concepts.

__STL Map__
* STL Map is used with STL Vector to store book data list.
* ISBN-13 code is used as a first element - 'key' - of Map container
* Vector container used as a second element of Map container.
* Vector container contains the following data
* Title of the book
* Author of the book
* Publisher of the book
* Date of Publication of the book
* Genre of the Book

__STL Multi-Map__
* STL Multi-Map is used to sort the book list by keywords.
* The original book data list made by STL Map will not be sorted, only print out the stored data based on the print order ginven by the container made with STL Multi-Map.
* The given keyword will be used as a first element - key - of the multimap container, 
* and ISBN-13 code will be used as a second element of the multimap container.

__STL Vector__
* STL Vector is used to store the following data
* input book data
* collection of the book data
* list of genre


The code provides the follwoing options.
* Add a book data
* Updata a book data
* Remove a book data
* Display book data in the database
* Display book data sorted by keyword
* Display book data collected by keyword.
* Displat a specific book data
* Save the current book data list into File
* Load the book data list from the File
