#include "Detector/Detector.h"

int main(int argc, char const* argv[])
{
    Detector* detector = new Detector;
    string    xml_path = "../res/yolov5s.xml";
    // string xml_path = "../res/yolov5m.xml";
    detector->init(xml_path, 0.3, 0.5);

    VideoCapture capture;
    capture.open(0);
    Mat src;
    while (1) {

        capture >> src;
        resize(src, src, Size(640, 640));
        imshow("src", src);
        vector<Detector::Object> detected_objects;
        detector->process_frame(src, detected_objects);
        for (int i = 0; i < detected_objects.size(); ++i) {
            cout << detected_objects[i].classId << endl; // 使用coco数据集标签
            int  xmin   = detected_objects[i].rect.x;
            int  ymin   = detected_objects[i].rect.y;
            int  width  = detected_objects[i].rect.width;
            int  height = detected_objects[i].rect.height;
            Rect rect(xmin, ymin, width, height); //左上坐标（x,y）和矩形的长(x)宽(y)
            cv::rectangle(src, rect, Scalar(255, 0, 0), 1, LINE_8, 0);
        }
        imshow("cap", src);
        waitKey(1);
    }

    // Mat src = imread("../res/bus.jpg");
    // Mat osrc = src.clone();
    // resize(osrc,osrc,Size(640,640));
    // vector<Detector::Object> detected_objects;
    // auto start = chrono::high_resolution_clock::now();
    // detector->process_frame(src,detected_objects);
    // auto end = chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end - start;
    // cout<<"use "<<diff.count()<<" s" << endl;
    // for(int i=0;i<detected_objects.size();++i){
    //      int xmin = detected_objects[i].rect.x;
    //     int ymin = detected_objects[i].rect.y;
    //     int width = detected_objects[i].rect.width;
    //     int height = detected_objects[i].rect.height;
    //     Rect rect(xmin, ymin, width, height);//左上坐标（x,y）和矩形的长(x)宽(y)
    //     cv::rectangle(osrc, rect, Scalar(0, 0, 255),1, LINE_8,0);
    // }
    // imshow("result",osrc);
    // waitKey(0);
}
