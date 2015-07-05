/*
 * File: NTPServer.h
 * Description:
 *   NTP server implementation.
 * Authors: Mooneer Salem <mooneer@gmail.com>
 *			Dan Quigley <danq@quigleys.us>
 * License: New BSD License
 */
 
#ifndef NTP_SERVER_H
#define NTP_SERVER_H

#define NTP_PORT 123

#include "ITimeSource.h"

class NtpServer
{
public:
    NtpServer(ITimeSource &source)
        : timeSource_(source)
    {
        // empty
    }
    
     // Begins listening for NTP requests.
    void beginListening(void);
    
     // Processes a single NTP request.
    bool processOneRequest(void);

	// Returns last NTP client IP address.
	IPAddress getLastClientIP();

private:
    ITimeSource &timeSource_;
    EthernetUDP timeServerPort_;
	IPAddress lastClient_;
};

#endif // NTP_SERVER_H
