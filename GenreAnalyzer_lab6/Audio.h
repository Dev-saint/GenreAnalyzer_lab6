#include "Albume.h"

class IAudio
{
public:
	IAudio() {}
	virtual void about() = 0;
};

class Attribute : public IAudio
{
protected:
	string attrib;
public:
	Attribute(string _attrib)
	{
		this->attrib = _attrib;
	}
	virtual void about()
	{
		cout << "\n" << this->attrib;
	}
};

class Composite : public IAudio
{
private:
	list <IAudio*> audio;
public:
	void addAttribute(IAudio* attrib)
	{
		audio.push_back(attrib);
	}
	void delAttribute(IAudio* attrib)
	{
		audio.remove(attrib);
		attrib->about();
		cout << " удаление атрибута из аудио\n";
	}
	virtual void about()
	{
		cout << "\nИзменение содержимого набора аттрибутов аудио";
	}
};