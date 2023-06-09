#include<iostream>
#include<fstream>
using namespace std;

class Helper
{
public:
	static bool hasDigit(char * str) {				//whether the text has any digit or not?
		if (str == nullptr) return false;
		for (int i = 0; i < strlen(str); i++)
			if (str[i] >= '0' && str[i] <= '9')
				return true;
		return false;
	}
	static char* filterStr(char* str) {				//applying filters
		if (str == nullptr) return nullptr;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '\'' || str[i] == '\"' || str[i] == '.' || str[i] == ',')
				for (int j = i--; j < strlen(str); j++)				 
					str[j] = str[j + 1]; 
			else if(str[i]>='A' && str[i]<='Z')
				str[i] = str[i] + 32;
		}
		return str;
	}
	static char* GetStringFromBuffer(char* str)	{		//my string copier
		if (str == nullptr) return nullptr;
		char *newstr = new char[strlen(str) + 1];
		strcpy(newstr, str);
		return newstr;
	}
};
class Word {
	char * text;
	int count; float probability;
public:
	Word() {	text = nullptr, count = 0, probability = 0.0;	}
	Word(char *txt, int c, float p) {
		text = nullptr; 
		setText(txt), setCount(c), setProbability(p);
	}
	Word(const Word & obj) {
		text = nullptr;
		setText(obj.text), setCount(obj.count), setProbability(obj.probability);
	}
	void assign(Word obj) {
		setText(obj.text), setCount(obj.count), setProbability(obj.probability);
	}
	void printWord() {
		if (text != nullptr)	cout<<endl << "The word is \"" << text << "\" with count = " << count << " and probability = " << probability;
	}
	void setText(char * str) {
		if (text != nullptr) delete[] text;
		text = Helper::GetStringFromBuffer(str);
	}
	//mutators
	void setCount(int c) { count = c; }
	void increamentCountByOne() { count++; }
	void setProbability(float prob) { probability = prob; }
	//accessors
	char * getText() { return text; }
	int getCount() { return count; }
	float getProbability() { return probability; }
	~Word() { if (text != nullptr) delete[] text; text = nullptr; }		//destructor
	//member functions | decide yourself
};

//check whether the list has text already?
int findWord(Word *list, char * text, int DistnctWords) {
	for (int i = 0; i < DistnctWords; i++)
		if (strcmp(list[i].getText(), text)==0)
			return i;
	return -1;
}
Word *getWordsList(char *filename, int & DistinctWords)
{
	fstream fin(filename, ios::in);
	DistinctWords = 0;
	int totalWords=0;
	if (fin.is_open() == false)	{
		cout << "Error! File not Opened.\n";		
		return nullptr;
	}
	Word * list = nullptr;
	char *temp = new char[20];
	while (fin.eof() == false)
	{
		fin >> temp;						//Whether the text has any digit? and length>1
		if (Helper::hasDigit(temp)==false && strlen(temp)>0)
		{
			totalWords++;
			Helper::filterStr(temp);
			int index = findWord(list, temp, DistinctWords);
			if (index >= 0)							//It means object is already exists
				list[index].increamentCountByOne();
			else
			{						//Extend the array
				DistinctWords++;
				Word * auxList = new Word[DistinctWords];
				for (int words = 0; words < DistinctWords - 1; words++)					
					auxList[words].assign(list[words]);
				delete[]list;
				list = auxList;
				list[DistinctWords - 1].assign(Word(temp, 1, 0));
			}
		}	 
	}
	for (int i = 0; i < DistinctWords; i++)			//find the probabilities
		list[i].setProbability(float(list[i].getCount()) / float(totalWords));
	delete[] temp;
	fin.close();
	return list;
}
void main() {

	const int filesCount = 4;					//maximum files
	int totalWords[filesCount];					//total words in each file
	Word** list = new Word*[filesCount];		//List of pointers to hold the words/file
	char fileName[filesCount][10] = { "data1.txt",	//Names of files
									"data2.txt", "data3.txt", "data4.txt" };
	for (int i = 0; i<filesCount; i++)			//For every file
		list[i] = getWordsList(fileName[i], totalWords[i]);		//compute the distinct words and probabilities
	for (int i = 0; i < filesCount; i++)			//for every file
	{
		for (int j = 0; j < totalWords[i]; j++)	 //for every word in file-i
			list[i][j].printWord();				//print the word and its probabilities
		cout << endl;		
	}
	delete[] list;
}