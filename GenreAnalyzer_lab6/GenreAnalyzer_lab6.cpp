#include "IFLAC.h";

int main()
{
	system("chcp 1251");
	system("cls");

	cout << "Adapter:" << endl;

	cout << "\nSong №1 - In_the_end" << endl;
	OriginAudio* oa = new OriginAudio();
	string n = "In_the_end";
	n = oa->readAudioFile(n);
	cout << "Song №2 - Song_2" << endl;
	n = "Song_2";
	IFLAC* conv = new Adapter();
	conv->getAudioFile(n);

	cout << "\nDecorator:" << endl;

	AnalyzingDB analyzedb;
	cout << analyzedb.getInfo() << "Genres: " << analyzedb.getGenre();
	TonalityAnalyzer tone(&analyzedb);
	cout << tone.getInfo() << "Genres: " << tone.getGenre();
	LoudnessAnalyzer loud(&tone);
	DurationAnalyzer dur(&loud);
	TempoAnalyzer tempo(&dur);
	cout << tempo.getInfo() << "Genres: " << tempo.getGenre() << endl;

	cout << "\nComposite:" << endl;

	Composite audio;
	audio.about();
	IAudio* tonality = new Attribute("тональность: D# min");
	tonality->about();
	audio.addAttribute(tonality);
	IAudio* loudness = new Attribute("громкость: 105 Дб");
	loudness->about();
	audio.addAttribute(loudness);
	audio.delAttribute(tonality);

	cout << "\nIterator:" << endl;

	typedef aggregate<string> albume;
	albume songs;
	
	cout << "\nДобавляется песня In the end" << endl;
	songs.push("In the end");
	
	cout << "Добавляется песня Gangnam Style" << endl;
	songs.push("Gangnam Style");
	
	cout << "Добавляется песня Smells like a Teen Spirit" << endl;
	songs.push("Smells like a Teen Spirit");
	
	cout << "Добавляется песня Белая ночь" << endl;
	songs.push("Белая ночь");
	
	cout << "Добавляется песня Ведьмаку заплатите чеканой монетой" << endl;
	songs.push("Ведьмаку заплатите чеканой монетой");
	
	cout << "Добавляется песня Отпускаю" << endl;
	songs.push("Отпускаю");
	
	cout << "\nАнализ итерируемых песен:" << endl << endl;
	for (albume::myIterator it = songs.begin(); it != songs.end(); ++it) {
		cout << "Анализирую: " << *(it.next()) << endl;
	}
	cout << "Анализ завершен!" << endl;
}