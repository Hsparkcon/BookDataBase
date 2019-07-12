#include "bookDatabase.h"

bookDatabase::bookDatabase() {
	mBookDataRequest = { "Title", "Author", "Publisher", "Date of Publication", "Genre" };
	mFlagSort = false;
	mFlagCollect = false;
}

bookDatabase::~bookDatabase() {

}

void bookDatabase::methodSelection() {

	int localSelection = NULL;

	std::cout << "Please Select the Operation" << std::endl;
	std::cout << "1 - Add a new book data" << std::endl;
	std::cout << "2 - Remove a book data" << std::endl;
	std::cout << "3 - Modify a book data" << std::endl;
	std::cout << "4 - Search a book" << std::endl;
	std::cout << "5 - Sort a book list" << std::endl;
	std::cout << "0 - Exit" << std::endl;

	std::cin >> localSelection;

	switch (localSelection)
	{
	case 1:
		bookDatabase::addData();
		break;

	case 2:
		bookDatabase::removeData();
		break;

	case 3:
		bookDatabase::setData();
		break;

	case 4:
		bookDatabase::searchData();
		break;

	case 5:
		bookDatabase::sortData();
		break;

	case 0:
		std::cout << "Exit the database." << std::endl;
		break;

	default:
		std::cout << "Please select the option from the list." << std::endl;
		break;
	}


}

void bookDatabase::getData() const {

}

void bookDatabase::addData() {

	std::pair<std::map<std::string, std::vector<std::string>>::iterator, bool> ckeckInsert;
	std::pair<std::string, std::vector<std::string>> instData;
	std::string bookISBN;

	bookISBN = bookDatabase::InputBookdata();
	
	instData = std::make_pair(bookISBN, mBookData);

	ckeckInsert = mBookList.insert(instData);

	if (true == ckeckInsert.second) {
		std::cout << "Book data is added." << std::endl;
	}
	else {
		std::cout << "Book data is not added, the book is alreay exist in the database." << std:: endl;
	}

}

bool bookDatabase::setData() {
	int localSelection = 0;
	bool flagOperation = true;
	std::string localBookIdentifier;
	std::string dataTobeModified;
	std::cout << "Please Search the book to modify the data of the book." << std::endl;

	localBookIdentifier = bookDatabase::searchData();

	while (flagOperation == true) {
		std::cout << "Please Select the info to be updated" << std::endl;

		std::cout
			<< "1 - Title" << '\n'
			<< "2 - Author" << '\n'
			<< "3 - Publisher" << '\n'
			<< "4 - Genre" << '\n'
			<< "0 - Exit"
			<< std::endl;

		std::cin >> localSelection;

		switch (localSelection) {
		case 1:
			std::cout << "Please update the title" << std::endl;
			std::cin >> dataTobeModified;
			mBookList[localBookIdentifier][0] = dataTobeModified;
			break;
		case 2:
			std::cout << "Please update the author" << std::endl;
			std::cin >> dataTobeModified;
			mBookList[localBookIdentifier][1] = dataTobeModified;
			break;
		case 3:
			std::cout << "Please update the publisher" << std::endl;
			std::cin >> dataTobeModified;
			mBookList[localBookIdentifier][2] = dataTobeModified;
			break;
		case 4:
			std::cout << "Please update the genre" << std::endl;
			std::cin >> dataTobeModified;
			mBookList[localBookIdentifier][3] = dataTobeModified;
			break;
		case 0:
			std::cout << "Exit" << std::endl;
			flagOperation = false;
			break;
		default:
			std::cout << "Please select the option from the list." << std::endl;
			break;
		}
	}

}

bool bookDatabase::removeData() {

}

std::string bookDatabase::searchData() const {

	int localSelection = NULL;
	std::string searchKeyword;
	std::string searchResult;

	std::cout << "Search the book by" << std::endl;
	std::cout 
			<< "1 - Title" << '\n'
			<< "2 - Author" << '\n'
			<< "3 - ISBN" << '\n'
			<< "0 - Exit"
			<< std::endl;

	std::cin >> localSelection;

	switch (localSelection)
	{
	case 1:
		std::cout << "Search By Title" << std::endl;
		for (auto i : mBookList) {
			if (searchKeyword == i.second[0]) {
				searchResult = i.first;
			}
			else {
				std::cout << "No match" << std::endl;
			}	
		}
		break;

	case 2:
		std::cout << "Search By Author" << std::endl;
		for (auto i : mBookList) {
			if (searchKeyword == i.second[1]) {
				searchResult = i.first;
			}
			else {
				std::cout << "No match" << std::endl;
			}
		}
		break;

	case 3:
		std::cout << "Search By ISBN-13" << std::endl;
		for (auto i : mBookList) {
			if (searchKeyword == i.first) {
				searchResult = i.first;
			}
			else {
				std::cout << "No match" << std::endl;
			}
		}
		break;

	case 0:
		searchResult = "Operation Cancelled";
		break;

	default:
		break;
	}
	
	return searchResult;
}

void bookDatabase::displayData() const {

	int localOperation;

	std::cout << "Display Book list" << std::endl;
	std::cout << "Please Select Display Option"
		<< "1 - Entire List" << '\n'
		<< "2 - Sorted by Keyword" << '\n'
		<< "3 - Collected by Keywordk" << '\n'
		<< "4 - Exit" << std::endl;

	std::cin >> localOperation;

	switch (localOperation) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}

}







bool bookDatabase::checkISBN() {

}

void bookDatabase::loadData() {

}

void bookDatabase::saveData() {

}

void bookDatabase::sortData() {
	std::pair<std::string, std::string> insertData;
	int localOperation = 1;
	int sortOption = 1;

	std::cout << "Sort by" << std::endl;
	std::cout
		<< "1 - Title" << '\n'
		<< "2 - Author" << '\n'
		<< "3 - Publisher" << '\n'
		<< "4 - Genre" << '\n'
		<< "0 - Exit" << std::endl;

	std::cin >> localOperation;

	switch (localOperation) {
	case 1:
		std::cout << "Sort by Title" << std::endl;
		sortOption = static_cast<int>(bookOptionParameters::Title);
		break;
	case 2:
		std::cout << "Sort by Author" << std::endl;
		sortOption = static_cast<int>(bookOptionParameters::Author);
		break;
	case 3:
		std::cout << "Sort by Publisher" << std::endl;
		sortOption = static_cast<int>(bookOptionParameters::Publisher);
		break;
	case 4:
		std::cout << "Sort by Genre" << std::endl;
		sortOption = static_cast<int>(bookOptionParameters::Genre);
		break;
	case 0:
		std::cout << "Exit" << std::endl;
		mFlagSort = false;
		break;
	}

	if (localOperation == 0) {
		return;
	}

	mBookSort.clear();
	for (auto i : mBookList) {
		insertData = std::make_pair(i.second[sortOption], i.first);
		mBookSort.insert(insertData);
	}

	mFlagSort = true;

}

void bookDatabase::collectData() {
	std::string userInput;
	int localOperation = 1;
	int collectOption = 1;
	
	std::cout << "Collect Data by" << std::endl;
	std::cout
		<< "1 - Title" << '\n'
		<< "2 - Author" << '\n'
		<< "3 - Publisher" << '\n'
		<< "4 - Genre" << '\n'
		<< "0 - Exit" << std::endl;

	std::cin >> localOperation;

	switch (localOperation) {
	case 1:
		std::cout << "Collect by Title" << std::endl;
		collectOption = static_cast<int>(bookOptionParameters::Title);
		break;
	case 2:
		std::cout << "Collect by Author" << std::endl;
		collectOption = static_cast<int>(bookOptionParameters::Author);
		break;
	case 3:
		std::cout << "Collect by Publisher" << std::endl;
		collectOption = static_cast<int>(bookOptionParameters::Publisher);
		break;
	case 4:
		std::cout << "Collect by Genre" << std::endl;
		collectOption = static_cast<int>(bookOptionParameters::Genre);
		break;
	case 0:
		std::cout << "Exit" << std::endl;
		mFlagCollect = false;
		break;
	}

	if (localOperation == 0) {
		return;
	}

	std::cout << "Please, Enter the Keyword." << std::endl;
	std::cin >> userInput;

	mBookCollect.clear();
	for (auto i : mBookList) {
		if (i.second[collectOption] == userInput) {
			mBookCollect.push_back(i.first);
		}
	}

	mFlagSort = true;

}

std::string bookDatabase::InputBookdata() {

	std::string localISBN;
	std::string localBookData;
	
	std::cout << "Please enter an ISBN-13 code of the book." << std::endl;
	std::cin >> localISBN;

	mBookData.clear();
	
	for (auto i : mBookDataRequest) {
		std::cout << "Please enter a(an) " << i << " of the book." << std::endl;
		std::cin >> localBookData;
		mBookData.push_back(localBookData);
		localBookData.clear();
	}

	return localISBN;

}