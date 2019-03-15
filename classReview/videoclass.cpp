#include <iostream>
#include <cstring>
using namespace std;

//constants
const int MAXCHAR = 101;

//class Video
class Video
{
	//private data members
	private:
		char title[MAXCHAR];
		int qty;
		double rating;
	public:
		//default constructor
		Video();
		//constructor with parameters
		Video(char tempTitle[], int tempQty, double tempRating);
		//member functions
		//accessor function
		void getTitle(char returnTitle[]);
		int getQty();
		void getRating(double &returnRating);
		//mutator functions
		void setTitle(char newTitle[]);
		void setQty(int newQty);
		void setRating(double newRating);
		//print function
		void printVideo() const;
};

//implementation for the Video Class
Video::Video()
{
	strcpy(title, "No title");
    qty = 0;
    rating = 0;
}

Video::Video(char tempTitle[], int tempQty, double tempRating)
{
	strcpy(title, tempTitle);
	qty = tempQty;
	rating = tempRating;
}

void Video::getTitle(char returnTitle[])
{
	strcpy(returnTitle, title);
}

int Video::getQty()
{
	return qty;
}

void Video::getRating(double &returnRating)
{
	returnRating = rating;
}

//mutator functions
void Video::setTitle(char newTitle[])
{
	strcpy(title, newTitle);
}

void Video::setQty(int newQty)
{
	qty = newQty;
}
void Video::setRating(double newRating)
{
	rating = newRating;
}

//print function
void Video::printVideo() const
{
	cout << title << ';' << qty << ';' << rating << endl;
}

//main
int main()
{
	Video aVideo("The Lion King", 23, 5.0);
	aVideo.setTitle("Happy Feet");
	aVideo.setQty(45);
	aVideo.setRating(3.5);
	Video myVideo;
	//array of videos
	Video list[10];
	aVideo.printVideo();
	myVideo.printVideo();
	for(int i = 0; i < 10; i++)
	{
		list[i].printVideo();
	}

	return 0;
}














		
