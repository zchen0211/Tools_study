//
// Created by ZhuoYuan Chen on 6/30/17.
//

#include <iostream>
#include "friends.h"

using std::cout;

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    } else
        return false;
}

bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup() {
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown() {
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const {
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV ? "TV" : "VCR") << endl;
    }
}

void test_friend_class() {
    Tv s27;
    cout << "Initial settings for 27\" TV:\n";
    s27.settings();
    s27.onoff();
    s27.chanup();
    cout << "\nAdjusted settings for 27\" TV:\n";
    s27.settings();
    Remote grey;
    grey.set_chan(s27, 10);
    grey.volup(s27);
    grey.volup(s27);
    cout << "\n27\" settings after using remote:\n";
    s27.settings();
    Tv s32(Tv::On);
    s32.set_mode();
    grey.set_chan(s32,28);
    cout << "\n32\" settings:\n";
    s32.settings();
}