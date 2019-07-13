#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

class bookDatabase
{
	public:
		bookDatabase();
		~bookDatabase();

		void methodSelection();
		void getData() const;
		void addData();
		bool setData();
		bool removeData();
		std::string searchData();
		void displayData();
		

	private:
		std::map<std::string, std::vector<std::string>> mBookList;
		std::multimap<std::string, std::string> mBookSort;
		std::vector<std::string> mBookCollect;
		std::vector<std::string> mBookDataRequest;
		std::vector<std::string> mBookData;
		std::vector<std::string> mSearchKeyword;
		std::vector<std::string> mGenreList;
		enum class bookOptionParameters
		{
			Title = 0,
			Author = 1,
			Publisher = 2,
			DatePublication = 3,
			Genre = 4
		};
		bool mFlagSort;
		bool mFlagCollect;

		bool checkISBN();
		void loadData();
		void saveData();
		void sortData();
		void collectData();
		std::string InputBookdata();
};

