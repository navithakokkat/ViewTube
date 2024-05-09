#ifndef VIEWTUBE_H
#define VIEWTUBE_H

#include "ChannelList.h"

class ViewTube {

    public:
        // Constructor
        ViewTube();

        // Destructor
        ~ViewTube();

        // Channel Functions
        void addChannel(const string& title, const string& owner);
        void deleteChannel(int index);
        int getNumChannels() const;

        // Video Functions
        void addVideo(const string& channel, const string& title, const string& content, const Date& date);
        void deleteVideo(int channel, int video);

        // Client Functions
        bool download(int index, Channel** channel);

        // Print Functions
        void printChannels() const;
        void printChannel(int index) const;
        void playVideo(int channelIndex, int videoIndex) const;

    private:
        ChannelList* channelList;

};

#endif