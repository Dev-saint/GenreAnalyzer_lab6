#include "Audio.h"

class IAnalyzeResulting
{
public:
	virtual string getGenre() = 0;
	virtual string getInfo() = 0;
};

class GenreAnalyzer : public IAnalyzeResulting
{
protected:
	IAnalyzeResulting* song;
public:
	virtual string getGenre() = 0;
	virtual string getInfo() = 0;
	GenreAnalyzer(IAnalyzeResulting* iar) { song = iar; }
	~GenreAnalyzer() {}
};

class AnalyzingDB : public IAnalyzeResulting
{
public:
	virtual string getGenre()
	{
		return "Альтернатива ";
	}
	virtual string getInfo()
	{
		return string("\nAnalyzing, ");
	}

};

class TonalityAnalyzer : public GenreAnalyzer
{
public:
	virtual string getGenre()
	{
		return "Рок " + song->getGenre();
	}
	virtual string getInfo()
	{
		return song->getInfo() + string("TonalityAnalyzer, ");
	}
	TonalityAnalyzer(IAnalyzeResulting* iar) :GenreAnalyzer(iar) {}
};

class LoudnessAnalyzer : public GenreAnalyzer
{
public:
	virtual string getGenre()
	{
		return "Рок " + song->getGenre();
	}
	virtual string getInfo()
	{
		return song->getInfo() + string("LoudnessAnalyzer, ");
	}
	LoudnessAnalyzer(IAnalyzeResulting* iar) :GenreAnalyzer(iar) {}
};

class DurationAnalyzer : public GenreAnalyzer
{
public:
	virtual string getGenre()
	{
		return "Альтернатива " + song->getGenre();
	}
	virtual string getInfo()
	{
		return song->getInfo() + string("DurationAnalyzer, ");
	}
	DurationAnalyzer(IAnalyzeResulting* iar) :GenreAnalyzer(iar) {}
};

class TempoAnalyzer : public GenreAnalyzer
{
public:
	virtual string getGenre()
	{
		return "Альтернатива " + song->getGenre();
	}
	virtual string getInfo()
	{
		return song->getInfo() + string("TempoAnalyzer, ");
	}
	TempoAnalyzer(IAnalyzeResulting* iar) :GenreAnalyzer(iar) {}
};
