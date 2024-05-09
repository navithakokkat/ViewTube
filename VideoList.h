
#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Video.h"
#include "defs.h"

using namespace std;

class VideoList {
		
	public:
		//constructor
		VideoList();
		VideoList(const VideoList&);
		
		//destructor
		~VideoList();
		
		//other
		bool addVideo(Video*);
		Video* getVideo(const string& title) const;
		Video* getVideo(int) const;
		Video* removeVideo(const string& title);
		Video* removeVideo(int);
		int size();
		void print();
	
	private:
		int numPods;
		Video** videos;
};
#endif
