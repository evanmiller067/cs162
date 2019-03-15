#ifndef VIDEOLIST_H
#define VIDEOLIST_H
//class object for a list of videos
#include "video.h"


//define class VideoList for linked list of videos

class VideoList
{
	private:
		//struct for each Node
		struct Node
		{
			Video data;
			Node *next;
		};
		Node *head;
		Node *tail;
		int size;
	
	public:
		//constructors
		VideoList();
		VideoList(char []);
		//destructor
		~VideoList();
		//database functions
		void addVideo(Video &);
		void searchByTitle();
		void searchByGenre();
		void showList();
		int getSize();
		void removeVideo();
		void writeData(char []);
		bool isLessThan(char [], char[]);
};

#endif
