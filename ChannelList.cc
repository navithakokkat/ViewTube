
#include "ChannelList.h"

// Constructor
ChannelList::ChannelList(){
	numPods = 0;
	channels = new Channel*[MAX_VIDS];
}

// Destructor
ChannelList::~ChannelList(){
	for (int i = 0; i < numPods; ++i) {
		if (channels[i]){
			delete channels[i]; 
		}
        
    }
	delete [] channels;
}

// Copy Constructor
ChannelList::ChannelList(const ChannelList& oldChannelList){
	numPods = oldChannelList.numPods;
	channels = new Channel*[MAX_CHANNELS];
	for (int i=0; i < numPods; i++) {
		channels[i] = new Channel(*oldChannelList.channels[i]);
	}
}

// Adds Channel to ChannelList
bool ChannelList::addChannel(Channel* p){
    if (numPods >= MAX_CHANNELS){
        return false;
    }

    channels[numPods] = p;
    numPods++;
    return true;
}

// Removes Channel with given title from ChannelList
Channel* ChannelList::removeChannel(const string& title){
	Channel* goner = nullptr;
	bool found = false;
	for (int i = 0; i < numPods; ++i){
		if (title == channels[i]->getTitle()){
			goner = channels[i];
			found = true;
		}
		if (found && i < numPods-1){
			channels[i]=channels[i+1];
		}
	}
	if (found) --numPods; 
	return goner;
}

// Removes Channel at given index from ChannelList
Channel* ChannelList::removeChannel(int index){
	if (index < 0 || index >= numPods) return nullptr;
	Channel* goner = channels[index];
	for (int i = index; i < numPods-1; ++i){
		channels[i] = channels[i+1];
	}
	--numPods;
	return goner;
}

// Getters
Channel* ChannelList::getChannel(const string& title)const {
	for (int i = 0; i < numPods; ++i){
		if (title == channels[i]->getTitle()){
			return channels[i];
		}
	}
	return nullptr;
}
Channel* ChannelList::getChannel(int index)const {
	if (index < 0 || index >= numPods) return nullptr;
	return channels[index];
}
int ChannelList::size(){
	return numPods;
}

// Prints all channels
void ChannelList::print(){
	for (int i=0; i < numPods; i++) {
        cout << i << ") ";
        channels[i]->print();
        cout << endl;
    } 
}

// Checks if ChannelList is full
bool ChannelList::isFull(){
    return numPods >= MAX_CHANNELS;
}