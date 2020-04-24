#include "filequery.h"
#include <memory>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
#include <iostream>
#include <map>
#include"filequery.h"
using namespace std;
FileQuery::FileQuery(std::ifstream& is) :sentences_(new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text)) {
		sentences_->push_back(text);
		std::istringstream line(text);
		int n = sentences_->size() - 1;
		std::string word;
		while (line >> word) {
			word = cleanup_str(word);
			auto& lines = kk[word];
			if (!lines)
				lines = new std::set<line_no>;
			lines->insert(n);
		}
	}
}

FileQuery::~FileQuery()
{

}

bool cmp(string a, string b)
{
	return a + b < b + a;
}

void FileQuery::PrintSentencesOrdered() {
	auto tmp_sentences = (*sentences_);
	sort(tmp_sentences.begin(), tmp_sentences.end(), cmp);
	int i;
	for (i = 0; i < tmp_sentences.size(); ++i)
	{
		std::cout << tmp_sentences[i] <<std::endl;
	}
}
void FileQuery::PrintSentencesFiltered(const std::string& str)
{
	auto loc = kk.find(cleanup_str(str));
	if (loc == kk.end())
		cout << "nodata" << endl;
	else {
		auto s = loc->first;
		for (auto it = loc->second->begin(); it != loc->second->end(); it++) {
			cout << sentences_->at(*it) << endl;
		}
	}


}
void FileQuery::PrintWordCount() {
	for (auto it = kk.begin(); it != kk.end(); it++) {
		string sought = it->first;
		cout << sought << ":" ;
		auto loc = kk.find(cleanup_str(sought));
		cout << (loc->second)->size() << endl;
	}
}
void FileQuery::ReplaceWord(const std::string& old_, const std::string& new_) {
	for (int i = 0; i < sentences_->size(); i++) {
		line_no pos = 0;
		while ((pos = (*sentences_)[i].find(old_)) != string::npos) {
			(*sentences_)[i].replace(pos, old_.length(), new_);
		}
	}
	kk[new_] = kk[old_];
	auto key = kk.find(old_);
	if (key != kk.end())
		kk.erase(key);
}