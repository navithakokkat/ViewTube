#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Video {

    public:
        // Constructor
        Video(const string& title, const string& content, const Date& date);

        // Getter
        string getTitle() const;

        // Other
        bool lessThan(const Video&) const;
        void print() const;
        void play() const;


    private:
        string title;
        string content;
        Date uploadDate;


};

#endif