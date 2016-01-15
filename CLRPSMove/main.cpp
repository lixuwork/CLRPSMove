//
//  main.cpp
//  CLRPSMove
//
//  Created by vk on 16/1/15.
//  Copyright © 2016年 clover. All rights reserved.
//

#include <iostream>
#include "psmove.h"
#include "psmove_tracker.h"
#include "core.hpp"
#include "highgui.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int count = psmove_count_connected();//psmove_count_connected();
    if (count == 0) {
        std::cout<<"!!!"<<std::endl;
    }
    
    void *frame;
    
    //PSMove **move = (PSMove **)calloc(count, sizeof(PSMove *));
    PSMoveTracker *tracker = psmove_tracker_new_with_camera(0);
    psmove_tracker_set_exposure(tracker, Exposure_LOW);
    while (1) {
        psmove_tracker_update_image(tracker);
        //psmove_tracker_update(tracker, NULL);
        std::cout<<psmove_tracker_get_exposure(tracker)<<std::endl;
        
        
        frame = psmove_tracker_get_frame(tracker);
        
        
        cv::Mat mat = cv::cvarrToMat(frame);
        
        if(frame) {
         //   cvShowImage("1111", frame);
            cv::imshow("2222", mat);
        }
        
        cv::Mat image = cv::imread("/Users/vk/workspace/Code4Everyone/CLRPSMove/CLRPSMove/a.jpg");
        cv::imshow("nihao", image);
        cv::waitKey(1);
    }
    
    
    return 0;
}
