#include "ViewTube.h"

// Constructor
ViewTube::ViewTube(){
    this->channelList = new ChannelList();
}

// Destructor
ViewTube::~ViewTube(){
    delete channelList;
}

/* Channel Functions */

// Adds a new Channel to ViewTube
void ViewTube::addChannel(const string& title, const string& owner){
    Channel* newChannel = new Channel(title, owner);

    if (!channelList->addChannel(newChannel)) {
        delete newChannel;
        cout << "Unable to add channel, ChannelList is full." << endl;
    }
}

// Deletes Channel at the given index from ViewTube
void ViewTube::deleteChannel(int index){
    Channel* removed = channelList->removeChannel(index);
    if (removed != nullptr){
        delete removed;
    } else {
        cout << "Invalid index, could not delete channel." << endl;
    }
}

// Getter for size of the ChannelList
int ViewTube::getNumChannels() const{
    return channelList->size();
}

/* Video Functions */

// Adds a new Video to a Channel with the given channel name
void ViewTube::addVideo(const string& channel, const string& title, const string& content, const Date& date){
    if (!channelList->getChannel(channel)) {
        cout << "Channel with this title does not exist." << endl;
        return;
    }

    channelList->getChannel(channel)->addVideo(title, content, date);
}

// Deletes a Video at the given index from the ChannelList
void ViewTube::deleteVideo(int channel, int video){
    if (!channelList->getChannel(channel)) {
        cout << "Channel does not exist." << endl;
        return;
    }

    channelList->getChannel(channel)->removeVideo(video);
}

/* Client Functions */

// Downloads the Channel at the given index into the channel output parameter
bool ViewTube::download(int index, Channel** channel){
    if (!channelList->getChannel(index)) {
        cout << "Channel does not exist." << endl;
        return false;
    }

    *channel = channelList->getChannel(index);
    return true;
}

// Print Functions
void ViewTube::printChannels() const{
    cout << "ViewTube" << endl;
    cout << "========" << endl;
    channelList->print();
}
void ViewTube::printChannel(int index) const{
    if (!channelList->getChannel(index)) {
        cout << "Channel does not exist." << endl;
        return;
    }
    channelList->getChannel(index)->printVideos();
}
void ViewTube::playVideo(int channelIndex, int videoIndex) const{
    if (!channelList->getChannel(channelIndex)) {
        cout << "Channel does not exist." << endl;
        return;
    }
    channelList->getChannel(channelIndex)->playVideo(videoIndex);
}