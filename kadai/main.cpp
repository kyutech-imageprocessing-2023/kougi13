#include <iostream>
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>


void display(cv::Mat image, std::string windowName = "Image") {
    cv::namedWindow(windowName);
    cv::imshow(windowName, image);
    cv::waitKey(1000 * 100);
    cv::destroyWindow(windowName);
}

int main(int argc, char* argv[]){

  if( argc != 2 ){
    std::cout << "main <filename>" << std::endl;
    exit(0);
  }


  // 画像をグレースケールで読み込む
  cv::Mat src = cv::imread(argv[1], 0);

  int x_size = src.cols;
  int y_size = src.rows ;
  int i, j;

  // 二値化の処理
  cv::Mat bin_img = cv::Mat::zeros(y_size, x_size, CV_8UC1);
  for( i=0 ; i<x_size ; i++ ){
    for( j=0 ; j<y_size ; j++ ){
      if( src.at<uchar>(j, i) < 80 ){
        bin_img.at<uchar>(j, i) = 255;
      }
    }
  }
  display(bin_img);

  // ラベル付け

  // 座標を求める

  // 画像をカラーで読み込む
  src = cv::imread(argv[1]);
  cv::Mat mandrill = cv::imread("Mandrill.jpg");

  //　射影変換、マスク処理で張り付ける


  display(src);


  return 0;
}

