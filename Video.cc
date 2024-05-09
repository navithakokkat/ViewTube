#include "Video.h"

// Constructor
Video::Video(const string& title, const string& content, const Date& date){
    this->title = title;
    this->content = content;
    this->uploadDate = date;
}

// Getter for title
string Video::getTitle() const{
    return title;
}

// Compares Videos based on their Date of being uploaded
bool Video::lessThan(const Video& other) const{
    return uploadDate.lessThan(other.uploadDate);
}

// Prints Video information
void Video::print() const{
    cout << "Video Title: " << title << endl;
    cout << "Video Upload Date: ";
    uploadDate.print();
    cout << endl;
}

// Plays Video by printing contents of Video
void Video::play() const{
    print();
    cout << "Content: " << content << endl;
}