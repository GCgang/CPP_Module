#include "FileReplacer.hpp"

FileReplacer::FileReplacer()
{
}

FileReplacer::~FileReplacer()
{
}

bool	FileReplacer::IsValidStrings(const std::string targetString, const std::string replaceString)
{
	if (targetString.empty() == true)
	{
		std::cerr << ::GetError(ERROR_EMPTY_STRING_TO_REPLACE) << std::endl;
		return (false);
	}
	if (replaceString.empty() == true)
	{
		std::cerr << ::GetError(ERROR_EMPTY_REPLACEMENT_STRING) << std::endl;
		return (false);
	}
	mTargetString = targetString;
	mReplaceString = replaceString;
	return (true);
}

bool	FileReplacer::IsValidFileName(const std::string fileName)
{
	mInFileStream.open(fileName.c_str(), std::ios_base::in);

	if (mInFileStream.fail() == true)
	{
		std::cerr << ::GetError(ERROR_FILE_OPEN) << std::endl;
		return (false);
	}
	if (mInFileStream.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << ::GetError(ERROR_EMPTY_FILE) << std::endl;
		mInFileStream.close();
		return (false);
	}
	mFileName = fileName;
	return (true);
}

bool	FileReplacer::ReplaceFile()
{
	std::string copyFileName = mFileName + ".replace";

	mOutFileStream.open(copyFileName.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);

	if (mOutFileStream.fail() == true)
	{
		std::cerr << ::GetError(ERROR_FILE_OPEN) << std::endl;
		mInFileStream.close();
		return (false);
	}
	if (mOutFileStream.is_open() == true)
	{
		std::string line;
		while (std::getline(mInFileStream, line))
		{
			ReplaceLine(line);
			mOutFileStream << line << std::endl;
		}
	}
	mInFileStream.close();
	return (true);
}

void	FileReplacer::ReplaceLine(std::string& line)
{
    size_t position = 0;
	std::string beforeSubString;
	std::string afterSubString;
    while ((position = line.find(mTargetString, position)) != std::string::npos)
	{
		beforeSubString = line.substr(0, position);
		afterSubString = line.substr(position + mTargetString.length());
        line = beforeSubString + mReplaceString + afterSubString;
        position += mReplaceString.length();
    }
}

std::string	GetError(eErrorCode errorCode)
{
	switch (errorCode)
	{
	case ERROR_ARGC:
		return ("Error: Invalid number of arguments!\nPlease provide the following arguments: \n[EXCUTABLE FILE NAME] [FILE NAME] [STRING TO BE REPLACED] [REPLACEMENT STRING]");
	case ERROR_FILE_OPEN:
		return ("Error: Failed to open the file!");
	case ERROR_EMPTY_FILE:
		return ("Error: The file is empty!");
	case ERROR_EMPTY_STRING_TO_REPLACE:
		return ("Error: The string to be replaced cannot be empty!");
	case ERROR_EMPTY_REPLACEMENT_STRING:
		return("Error: The replacement string cannot be empty!");
	default:
		return("Unknown error occurred!");
	}
}