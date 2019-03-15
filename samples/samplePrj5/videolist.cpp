//This is the implementation file for VideoList class
#include "videolist.h"
#include "tools.h"

//constructors
VideoList::VideoList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

//constructor from file
VideoList::VideoList(char fileName[])
{
	head = NULL;
	tail = NULL;
	size = 0;
	ifstream inFile;
	Video aVideo;
	char tempTitle[MAXCHAR], genreDesc[MAXCHAR];
	int tempQty;
	Genre tempGenre;
	double tempRating;

	inFile.open(fileName);
	if(!inFile)
	{
		cout << "cannot open file! Exiting!!" << endl;
		exit(0);
	}

	inFile.getline(tempTitle, MAXCHAR, ';');
	while(!inFile.eof())
	{
		inFile.getline(genreDesc, MAXCHAR, ';');
		tempGenre = readGenre(genreDesc[0]);
		inFile >> tempQty;
		inFile.ignore(5, ';');
		inFile >> tempRating;
		inFile.ignore(5, '\n');
		//populate aVideo;
		aVideo.setTitle(tempTitle);
		aVideo.setGenre(tempGenre);
		aVideo.setQty(tempQty);
		aVideo.setRating(tempRating);
		addVideo(aVideo);
		inFile.getline(tempTitle, MAXCHAR, ';');
	}
	inFile.close();
}

//destructor
VideoList::~VideoList()
{
	//delete list
	Node *curr = head;
	while(curr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
	tail = NULL;
}

//Add a video to the store
void VideoList::addVideo(Video &aVideo)
{
	Node *newNode = NULL, *curr = NULL, *prev = NULL;
	char str1[MAXCHAR], str2[MAXCHAR], tempTitle[MAXCHAR];
	Genre tempGenre;
	int tempQty;
	double tempRating;
	//populate newNode
	newNode = new Node;
	newNode->data = aVideo;
	newNode->next = NULL;
	//check to see if list is empty
	if(!head)
	{
		head = newNode;
		tail = newNode;
	}
	//if list is not empty, then insert sorted by title
	else
	{
		curr = head;
		curr->data.getTitle(str1);
		newNode->data.getTitle(str2);
		while(curr && isLessThan(str1, str2))
		{
			prev = curr;
			curr = curr->next;
			if(curr)
			{
				curr->data.getTitle(str1);
			}
		}
		//check to see if we are at the end of our list
		if(!curr)
        {
        	tail->next = newNode;
            tail = newNode;
        }
        //insert in between
        else if(prev)
        {
            newNode->next = curr;
            prev->next = newNode;
        }
        //insert at the beginning
        else
        {
            newNode->next = curr;
            head = newNode;
        }
	}
	size++;
}

//Returns the size of the list
int VideoList::getSize(){
	return size;
}

//search by Title
void VideoList::searchByTitle()
{
	char searchTitle[MAXCHAR];
	char tempTitle[MAXCHAR];
	bool flag = false;
	cout << "Please enter title to search for:";
	cin.get(searchTitle, MAXCHAR);
	convertCase(searchTitle);
	
	for(Node *curr = head; curr; curr  = curr->next)
	{
		curr->data.getTitle(tempTitle);
		convertCase(tempTitle);
		if(strstr(tempTitle, searchTitle) != NULL)
		{
			curr->data.printVideo();
			flag = true;
		}
	}
	
	if(!flag)
		cout << "No videos for that title found!" << endl;
}

//search by Genre
void VideoList::searchByGenre()
{
	char letter;
	Genre srchGenre;
	Genre tempGenre;
	bool flag = false; 
    cout << "Please enter the genre to search for (A-ACTION, F-FAMILY, C-COMEDY, H-HORROR):";
    cin >> letter;
    srchGenre = readGenre(letter);
    for(Node *curr = head; curr; curr = curr->next)
    {
		tempGenre = curr->data.getGenre();
        if(srchGenre == tempGenre)
        {
			curr->data.printVideo();
			flag = true;
        }
    }

	if(!flag)
	{
		cout << "Did not find any videos of that genre!" << endl;
	}
}

//writes the data to the file
void VideoList::writeData(char fileName[])
{
	ofstream outFile;
	outFile.open(fileName);
	Node *curr;
	for(curr = head; curr; curr = curr->next)
	{
		curr->data.printVideo(outFile);
	}
}
	
//displays the list
void VideoList::showList()
{
	int count = 1;
	Node *curr;
	for(curr = head; curr; curr = curr->next)
	{
		cout << count << ".";
		curr->data.printVideo();
		count++;
	}
	cout << endl;
}

//removes a video from the list
void VideoList::removeVideo()
{
	int count = 1;
	int toRemove = 0;
	if(!size){
		cout << "Nothing to remove! Terminating..." << endl;
		return;
	}
	toRemove = readInt("Select number for video to remove:");
	Node *curr = head, *prev = NULL;
	while(toRemove < 1 || toRemove > size){
		toRemove = readInt("Bad Index, please re-enter:");
	}
	while(curr && count < toRemove){
		prev = curr;
		curr = curr->next;
		count++;
	}
	if(!prev){
		head = curr->next;
	} else if(curr == tail){
		prev->next = curr->next;
		tail = prev;
	} else {
		prev->next = curr->next;
	}
	delete curr;
	curr = NULL;
	prev = NULL;
	size--;
}

//function to compare 2 strings
bool VideoList::isLessThan(char str1[], char str2[])
{
	if(strcmp(str1, str2) < 0)
		return true;
	return false;
}
	






	
	































	
