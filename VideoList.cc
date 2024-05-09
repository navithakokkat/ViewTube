
#include "VideoList.h"

// Constructor
VideoList::VideoList(){
	numPods = 0;
	videos = new Video*[MAX_VIDS];
}

// Destructor
VideoList::~VideoList(){
	for (int i = 0; i < numPods; ++i) {
        delete videos[i]; 
    }
	delete [] videos;
}


// Copy Constructor
VideoList::VideoList(const VideoList& oldVideoList){
	numPods = oldVideoList.numPods;
	videos = new Video*[MAX_VIDS];
	for (int i=0; i < numPods; i++) {
		videos[i] = new Video(*oldVideoList.videos[i]);
	}
}

// Adds Video to VideoList
bool VideoList::addVideo(Video* p){
	if (numPods >= MAX_VIDS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*videos[i-1])){
			videos[i] = videos[i-1];
		}else{
			videos[i] = p;
			++numPods;
			return true;
		}
	}
	videos[0] = p;
	++numPods;
	return true;
}

// Removes Video with given title from VideoList
Video* VideoList::removeVideo(const string& title){
	Video* goner = nullptr;
	bool found = false;
	for (int i = 0; i < numPods; ++i){
		if (title == videos[i]->getTitle()){
			goner = videos[i];
			found = true;
		}
		if (found && i < numPods-1){
			videos[i]=videos[i+1];
		}
	}
	if (found) --numPods; 
	return goner;
}

// Removes Video at given index from VideoList
Video* VideoList::removeVideo(int index){
	if (index < 0 || index >= numPods) return nullptr;
	Video* goner = videos[index];
	for (int i = index; i < numPods-1; ++i){
		videos[i] = videos[i+1];
	}
	--numPods;
	return goner;
}

// Getters for videos
Video* VideoList::getVideo(const string& title)const {
	for (int i = 0; i < numPods; ++i){
		if (title == videos[i]->getTitle()){
			return videos[i];
		}
	}
	return nullptr;
}
Video* VideoList::getVideo(int index)const {
	if (index < 0 || index >= numPods) return nullptr;
	return videos[index];
}
int VideoList::size(){
	return numPods;
}

// Prints videos in the VideoList
void VideoList::print(){
	for (int i=0; i < numPods; i++) {
        cout << i << ") ";
        videos[i]->print();
        cout << endl;
    } 
}
