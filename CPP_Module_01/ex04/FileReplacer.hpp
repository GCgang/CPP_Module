#pragma once
#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

#include <iostream>
#include <string>
#include <fstream>

enum eErrorCode
{
	ERROR_ARGC,
	ERROR_FILE_OPEN,
	ERROR_EMPTY_FILE,
	ERROR_EMPTY_STRING_TO_REPLACE,
	ERROR_EMPTY_REPLACEMENT_STRING
};

std::string	GetError(eErrorCode errorCode);

class	FileReplacer
{
	public:
		FileReplacer();
		~FileReplacer();
		bool	IsValidFileName(const std::string fileName);
		bool	IsValidStrings(const std::string targetString, const std::string replaceString);
		bool	ReplaceFile(void);
		void	ReplaceLine(std::string& line);
		void	GetError(eErrorCode errorCode);
	private:
		std::ifstream	mInFileStream;
		std::ofstream	mOutFileStream;
		std::string		mFileName;
		std::string		mTargetString;
		std::string		mReplaceString;
};

#endif // FILEREPLACER_HPP