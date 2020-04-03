#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;
//��������ͷ
int main()
{
	VideoCapture cap;          //ʵ����һ��videocapture�࣬����Ϊcap
	cap.open(0);              //�򿪱����ĵ�һ������ͷ
	if (!cap.isOpened())     //isOpened()�����Ƶ�Ƿ�����������������1
	{
		std::cout << "���ɴ���Ƶ�ļ�" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);//ͨ��get()����ͬ�������Ի����Ƶ��fps
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		Mat frame;
		Mat dst1;
		Mat dst2;
		Mat dx;
		Mat dy;
		Mat abs_dx;
		Mat abs_dy;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			//��һ��
			Sobel(frame, dx, CV_16SC1, 1, 0, 3);
			convertScaleAbs(dx, abs_dx);
			Sobel(frame, dy, CV_16SC1, 0, 1, 3);
			convertScaleAbs(dy, abs_dy);
			Canny(dx, dy, dst1, 30, 90);
			//�ڶ���
			Canny(frame, dst2, 30, 90);
			cv::imshow("frame ", frame);
			cv::imshow("dst1 ", dst1);
			cv::imshow("dst2 ", dst2);
		}
		waitKey(30);

	}
	return 0;
}