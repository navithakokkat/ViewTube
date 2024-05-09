#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Channel.h"
#include "ViewTube.h"
#include "defs.h"

class Client{
    public:
        // Constructor
        Client(const string& name);
        // Destructor
        ~Client();

        // Other
        bool download(ViewTube& viewTube, int index);
        void print() const;
        void printChannel() const;
        void play(int index) const;


    private:
        string name;
        Channel* channel;
    
};


#endif