#include "opencv2/opencv.hpp"
#include "iostream"
#include "string"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/types_c.h"
#include "opencv2/highgui/highgui_c.h"

using namespace std;

void Video_To_Image(string filename);

int main(int argc, char* argv[])
{
	string video_name = "deqing.mp4";
	Video_To_Image(video_name);
	return 0;
}

void Video_To_Image(string filename)
{
	cv::VideoCapture capture(filename);
	if(!capture.isOpened())
	{
		cout << "open video error";
	}
	int frame_width = (int)capture.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT);
	float frame_fps = capture.get(CV_CAP_PROP_FPS);
	int frame_number = capture.get(CV_CAP_PROP_FRAME_COUNT);//��֡��
	cout << "frame_width is" << frame_width << endl;
	cout << "frame_height is" << frame_height << endl;
	cout << "frame_fps is" << frame_fps << endl;

	int num = 0;//ͳ��֡��
	cv::Mat img;
	string img_name;
	char image_name[20];
	cv::namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);
	while (true)
	{
		cv::Mat frame;
		//����Ƶ�ж�ȡһ��֡
		bool bSuccess = capture.read(frame);
		if(!bSuccess)
		{
			cout << "read frame failed" << endl;
			break;
		}
		cv::imshow("MyVideo",frame);
		sprintf(image_name, "%s%d%s", "image", ++num, ".jpg");//�����ͼƬ��
		img_name = image_name;
		cv::imwrite(img_name, frame);//����Ϊһ֡ͼƬ
		if(cv::waitKey(30) == 27||num == frame_number)
		{
			cout << "press the ESC" << endl;
			break;
		}
	}
}


