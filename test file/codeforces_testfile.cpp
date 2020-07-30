/* Credits to Ansh Agrawal for program */

/* --- Standard C++ Includes--- */
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// @macro defines CHOCO_BANANA to value 0
#define CHOCO_BANANA	0

// @macro defines VANILLA to 1
#define VANILLA			1

// @macro defines DARK_CHOCO to 2
#define DARK_CHOCO		2

// @macro defines TROPICAL 3
#define TROPICAL 		3

using namespace std;

/* Data structure representing a cookie */

// @brief    This is a structure storing customerId and CookieType in 16bytes and 8bytes respecrively
struct cookie {

        /* Customer ID's*/
        int16_t customerId;

        /* Cookie Type */
        int8_t cookieType;
};

/* Data Structure representing a Tray */
// @brief  This is a structing containing a tray in which each contains 6 cookies
struct tray {
        /* Each tray can contain only 6 cookies */
        struct cookie cookies[6];
};
/* Total 64 trays */
struct tray trays[64];

/* @brief:



*/
int main()
{
    // declaration of variables of  string datatypes
    string s,a,b,c;

    // take input s from user
    cin>>s;

    int a1,b1,c1;

    vector<pair<int,pair<int,int>>> v;

    while(true){

        cin>>a;

        if(a=="EOF")
              break;
        cin>>b;
        cin>>c;

        // Convert all the strings to integers
        a1 = stoi(a);
        b1 = stoi(b);
        c1 = stoi(c);

        v.push_back({a1,{b1,c1}});

        }

    int i,len = v.size(),ans=0;

    int d,t;

    cin>>d>>t;

    for( i=0;i<len;i++){


        if(v[i].second.first==d && v[i].second.second == t)
        {
            ans = v[i].first;
            break;

        }
    }


    if(i<len)

    cout<<ans;

    else

    cout<<"EINVAL";

}
