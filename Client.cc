#include "Client.h"

// Constructor
Client::Client(const string& name){
    this->name = name;
    this->channel = nullptr;
}

// Destructor
Client::~Client(){
    if (channel){
        delete channel;
    }
}

// Downloads a channel from ViewTube
bool Client::download(ViewTube& viewTube, int index){
    // If channel already exists, deletes it
    if (channel != nullptr) {
        delete channel;
        channel = nullptr;
    }

    bool value = viewTube.download(index, &channel);
    if (value){
        channel = new Channel(*channel);
        return true;
    } else {
        cout << "Error downloading the Channel" << endl;
        channel = nullptr;
        return false;
    }
}

// Prints out the channel
void Client::print() const{
    cout << "Client Name: " << name << endl;
    if (channel != nullptr) {
        channel->print();
    } else {
        cout << "No channel downloaded." << endl;
    }
}

// Prints out all Videos in the Channel
void Client::printChannel() const{
    if (channel != nullptr) {
        channel->printVideos();
    } else {
        cout << "No channel downloaded." << endl;
    }
}

// Plays the Video at the given index of the Channel
void Client::play(int index) const{
    if (channel != nullptr) {
        channel->playVideo(index);
    } else {
        cout << "No channel downloaded." << endl;
    }
}