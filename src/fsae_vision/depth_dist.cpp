//
//  main.cpp
//  distTest
//
//  Created by Cameron Kisailus on 5/29/19.
//  Copyright © 2019 Cameron Kisailus. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

//These consts are subject to change when we run our own experiments to gather data....
const float fCoefDepth = 0.0033;
const float sCoefDepth = 1.9918;
const float tCoefDepth = 372.83;

const float fCoefRatio = 0.0004;
const float sCoefRatio = 0.1469;
const float tCoefRatio = 18.119;


//

//We can play around with this threshold as we like
const float ratioMatchThreshold = 1;



float objDepth(float pixelHeight){
    float estDepth = (fCoefDepth*pixelHeight*pixelHeight) - (sCoefDepth*pixelHeight) + tCoefDepth;
    return estDepth;
}

float objLatDist(float perDepth){
    //Again, this will change based on our own experimental data...
    map<float,int> ratioMap = {};
    
    //Find estimated ratio based off percepted depth
    float estRatio = (fCoefRatio*perDepth*perDepth) - (sCoefRatio*perDepth) + tCoefRatio;
    float estLatDist = 0.00;
    
    //Find closest match in ratioMap, still needs work!!!!!
    for (auto it = ratioMap.begin(); it != ratioMap.end(); it++)
    {
        //If difference between the experimental ratio and calculated ratio is less than our threshold, then set the estimated lateral distance to the experimental later distance
        if(estRatio - it->first <= ratioMatchThreshold)
        {
            estLatDist = it->second;
        }
            
    }
    return estLatDist;
}


int main() {
    float pixelHeights[] = {};
    //Pass in Darp's Bounding Rectangle
    //Get rectangle's height in pixels
    
    //Pass pixHeight into objDepth to get estimated object Depth
    for(float pixHeight:pixelHeights){
        float estDepth = objDepth(pixHeight);
        //pass estDepth into objLatDist to get estimated object lateral distance
        float estLatDist = objLatDist(estDepth);
        cout<<estDepth<<" "<<estLatDist<<endl;
    }
    //Go on to pass estDepth and estLatDist to Nayana for motion planning
    
    
    return 0;
}

