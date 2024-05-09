#ifndef CHANNELLIST_H
#define CHANNELLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Channel.h"
#include "defs.h"

using namespace std;

class ChannelList {
		
	public:
		//constructor
		ChannelList();
		ChannelList( const ChannelList&);
		
		//destructor
		~ChannelList();
		
		//other
		bool addChannel(Channel*);
		Channel* getChannel(const string& title) const;
		Channel* getChannel(int) const;
		Channel* removeChannel(const string& title);
		Channel* removeChannel(int);
		int size();
		void print();
        bool isFull();
	
	private:
		int numPods;
		Channel** channels;
};


#endif