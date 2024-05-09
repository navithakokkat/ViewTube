#include "Channel.h"

// Constructor
Channel::Channel(const string& title, const string& owner){
    this->title = title;
    this->owner = owner;
    this->videoList = new VideoList();
}

// Copy Constructor
Channel::Channel(const Channel& oldChannel) {
    title = oldChannel.title;
    owner = oldChannel.owner;
    this->videoList = new VideoList(*oldChannel.videoList);
}
        
// Destructor
Channel::~Channel(){
    delete videoList;
}

// Getters
string Channel::getTitle() const{
    return title;
}
string Channel::getOwner() const{
    return owner;
}
int Channel::getNumVideos() const{
    return videoList->size();
}

// Other
bool Channel::lessThan(const Channel& other) const{
    return title < other.title;
}

// Adds video to the channel
bool Channel::addVideo(const string& title, const string& content, const Date& date){
    Video* newVid = new Video(title, content, date);
    if (videoList->addVideo(newVid)) {
        return true;
    } else {
        delete newVid;
        cout << "Unable to add video, channel is full." << endl;
        return false;
    }
}

// Removes video from the channel
bool Channel::removeVideo(int index){
    Video* removed = videoList->removeVideo(index);
    if (removed != nullptr) {
        delete removed;
        return true;
    } else {
        cout << "Invalid index, unable to remove video." << endl;
        return false;
    }
}

// Prints Channel's metadata
void Channel::print() const{
    cout << "Channel Title: " << title << endl;
    cout << "Channel Owner: " << owner << endl;
}

// Prints Channel's metadata and contents of its VideoList
void Channel::printVideos() const{
    print();
    videoList->print();
}

// Plays the Video at the given index in the Channel
void Channel::playVideo(int index) const{
    if (videoList->getVideo(index) == nullptr) {
        cout << "Index is not valid" << endl;
    } else {
        videoList->getVideo(index)->play();
    }
}
