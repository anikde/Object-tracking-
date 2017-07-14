#include <iostream>
#include <opencv2/opencv.hpp>

//creating a function of return type matrix
//This function will be checking for the object available for it

cv::Mat drawBoundingBox(cv::Mat img, cv::Mat mask){
    cv:: Mat output;
    cv::Point br(0,0), tl(mask.cols, mask.rows);
    if(mask.channels() > 1) cv::cvtColor(mask, mask, CV_BGR2GRAY);
    for (int i=0; i<mask.rows; i++){
        for (int j=0; j<mask.cols; j++){
            if(mask.at<uchar>(i,j) > 150){
                if(tl.x > j) tl.x = j;
                if(tl.y > i) tl.y = i;

                if(br.x < j) br.x = j;
                if(br.y < i) br.y = i;
            }
        }
    }

    cv::rectangle(img, tl, br, cv::Scalar(0, 250, 0), 2);
    return img;
}

int main() {


    cv::Mat im ,gray,threshold,output,frame;

    cv::VideoCapture cam(0);


    //im=cv::imread("/home/anik/Downloads/balls.jpg");





    int R1=0, G1=0, B1=0;
    int R2=255,G2=255,B2 =255;


    cv::namedWindow("control",CV_WINDOW_NORMAL);

    cv::createTrackbar("R1","control", &R1,255,NULL);
    cv::createTrackbar("G1","control" ,&G1,255,NULL);
    cv::createTrackbar("B1","control" ,&B1,255,NULL);

    cv::createTrackbar("R2","control",&R2,255,NULL);
    cv::createTrackbar("G2","control",&G2,255,NULL);
    cv::createTrackbar("B2","control",&B2 ,255,NULL);

    while (true) {

        cam.read(im);
        cv::imshow("image",im);
        cv::cvtColor(im,gray,CV_BGR2GRAY);
        cv::inRange(im, cv::Scalar(B1, G1, R1), cv::Scalar(B2, G2, R2), threshold);
        cv::imshow("threshold", threshold);

        //taking the threshold value of the object to be detected

        //keep on updating the bounding box updating
         cv::imshow("Bounding Box", drawBoundingBox(im, threshold));


        int key;
        key = cv::waitKey(30);
        if( key == 27 ) break;


    }
}