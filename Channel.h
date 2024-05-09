#ifndef CHANNEL_H
#define CHANNEL_H


#include <iostream>
#include <string>
#include <iomanip>
#include "VideoList.h"
#include "Video.h"
#include "defs.h"

using namespace std;

class Channel{
    public:
        // Constructor
        Channel(const string& title, const string& owner);

        // Copy Constructor
        Channel(const Channel& other);
        
        // Destructor
        ~Channel();

        // Getters
        string getTitle() const;
        string getOwner() const;
        int getNumVideos() const;

        // Other
        bool lessThan(const Channel& other) const;
        bool addVideo(const string& title, const string& content, const Date& date);
        bool removeVideo(int index);
        void print() const;
        void printVideos() const;
        void playVideo(int index) const;

        
    private:
        string title;
        string owner;
        VideoList* videoList;
};

#endif 