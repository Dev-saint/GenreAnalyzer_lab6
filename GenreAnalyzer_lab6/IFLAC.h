#include "AnalyzeResulting.h"

class IFLAC
{
public:
	virtual void getAudioFile(string) = 0;
};

class OriginAudio
{
public:
	string readAudioFile(string songName)
	{
		string file;
		file += songName;
		file.push_back('.');
		file.push_back('m');
		file.push_back('p');
		file.push_back('3');
		cout << "Оригинальный аудиофайл создан: " << file << endl;
		return file;
	}
};

class Adapter : public IFLAC
{
private:
	OriginAudio* oa;
public:
	void getAudioFile(string songName) override
	{
		string file = oa->readAudioFile(songName);
		file.erase(file.length() - 3);
		file.push_back('f');
		file.push_back('l');
		file.push_back('a');
		file.push_back('c');
		cout << "Конвертированный аудиофайл: " << file << endl;
	}
	Adapter() { oa = new OriginAudio(); }
	~Adapter() { delete oa; }
};