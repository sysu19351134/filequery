#pragma once
#ifndef _FILEQUERY_H_
#define _FILEQUERY_H_
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <map>
class FileQuery {
private:
	std::vector<std::string>* sentences_;
	using line_no = std::vector<std::string>::size_type;
	std::map<std::string, std::set<line_no>*>kk;
	std::set<line_no>* lines;
public:
	FileQuery(std::ifstream&);
	~FileQuery();
	void PrintSentencesOrdered();
	void PrintSentencesFiltered(const std::string& str);
	void PrintWordCount();
	void ReplaceWord(const std::string& old_, const std::string& new_);
	std::string cleanup_str(const std::string& word)
	{
		std::string ret;
		for (auto it = word.begin(); it != word.end(); ++it) {
			if (!ispunct(*it))
				ret += tolower(*it);
		}
		return ret;
	}

};
#endif

