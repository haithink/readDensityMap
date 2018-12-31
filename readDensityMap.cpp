#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "opencv2/opencv.hpp"
#include "features2d.hpp"

using namespace std;
using namespace cv;

//删除字符串中空格，制表符tab等无效字符
string Trim(string& str)
{
	//str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
	str.erase(0, str.find_first_not_of(" \t\r\n"));
	str.erase(str.find_last_not_of(" \t\r\n") + 1);
	return str;
}


Mat dst;
int thresh, thresh1;
cv::Mat img;
void on_thresh(int, void*)
{
	threshold(img, dst, thresh, 255, thresh1);
	imshow("threshold二值化灰图", dst);
}

string findFileName(string name)
{
	auto pos = name.find_last_of("/");
	return name.substr(pos + 1);
}
void showImg()
{
	string imgPaths[] = {
		"Part_A/test_data/IMG_167",
		"Part_A/test_data/IMG_159",
		"Part_A/test_data/IMG_125",
		"Part_A/test_data/IMG_2",
		"Part_A/test_data/IMG_67",
		"Part_A/test_data/IMG_154",
		"Part_A/test_data/IMG_79",
		"Part_A/test_data/IMG_9",
		"Part_A/test_data/IMG_101",
		"Part_A/test_data/IMG_127",
		"Part_A/test_data/IMG_36",
		"Part_A/test_data/IMG_135",
		"Part_A/test_data/IMG_116",
		"Part_A/test_data/IMG_49",
		"Part_A/test_data/IMG_142",
		"Part_A/test_data/IMG_42",
		"Part_A/test_data/IMG_19",
		"Part_A/test_data/IMG_11",
		"Part_A/test_data/IMG_100",
		"Part_A/test_data/IMG_6",
		"Part_A/test_data/IMG_16",
		"Part_A/test_data/IMG_109",
		"Part_A/test_data/IMG_68",
		"Part_A/test_data/IMG_173",
		"Part_A/test_data/IMG_104",
		"Part_A/test_data/IMG_131",
		"Part_A/test_data/IMG_117",
		"Part_A/test_data/IMG_97",
		"Part_A/test_data/IMG_108",
		"Part_A/test_data/IMG_107",
		"Part_A/test_data/IMG_91",
		"Part_A/test_data/IMG_78",
		"Part_A/test_data/IMG_80",
		"Part_A/test_data/IMG_77",
		"Part_A/test_data/IMG_92",
		"Part_A/test_data/IMG_114",
		"Part_A/test_data/IMG_33",
		"Part_A/test_data/IMG_81",
		"Part_A/test_data/IMG_70",
		"Part_A/test_data/IMG_66",
		"Part_A/test_data/IMG_7",
		"Part_A/test_data/IMG_89",
		"Part_A/test_data/IMG_72",
		"Part_A/test_data/IMG_83",
		"Part_A/test_data/IMG_119",
		"Part_A/test_data/IMG_169",
		"Part_A/test_data/IMG_178",
		"Part_A/test_data/IMG_120",
		"Part_A/test_data/IMG_43",
		"Part_A/test_data/IMG_153",
		"Part_A/test_data/IMG_56",
		"Part_A/test_data/IMG_103",
		"Part_A/test_data/IMG_65",
		"Part_A/test_data/IMG_38",
		"Part_A/test_data/IMG_29",
		"Part_A/test_data/IMG_61",
		"Part_A/test_data/IMG_110",
		"Part_A/test_data/IMG_86",
		"Part_A/test_data/IMG_148",
		"Part_A/test_data/IMG_53",
		"Part_A/test_data/IMG_147",
		"Part_A/test_data/IMG_84",
		"Part_A/test_data/IMG_45",
		"Part_A/test_data/IMG_157",
		"Part_A/test_data/IMG_96",
		"Part_A/test_data/IMG_37",
		"Part_A/test_data/IMG_87",
		"Part_A/test_data/IMG_76",
		"Part_A/test_data/IMG_177",
		"Part_A/test_data/IMG_46",
		"Part_A/test_data/IMG_63",
		"Part_A/test_data/IMG_60",
		"Part_A/test_data/IMG_129",
		"Part_A/test_data/IMG_162",
		"Part_A/test_data/IMG_47",
		"Part_A/test_data/IMG_123",
		"Part_A/test_data/IMG_55",
		"Part_A/test_data/IMG_98",
		"Part_A/test_data/IMG_115",
		"Part_A/test_data/IMG_138",
		"Part_A/test_data/IMG_50",
		"Part_A/test_data/IMG_58",
		"Part_A/test_data/IMG_41",
		"Part_A/test_data/IMG_10",
		"Part_A/test_data/IMG_175",
		"Part_A/test_data/IMG_73",
		"Part_A/test_data/IMG_182",
		"Part_A/test_data/IMG_161",
		"Part_A/test_data/IMG_124",
		"Part_A/test_data/IMG_160",
		"Part_A/test_data/IMG_128",
		"Part_A/test_data/IMG_39",
		"Part_A/test_data/IMG_105",
		"Part_A/test_data/IMG_143",
		"Part_A/test_data/IMG_1",
		"Part_A/test_data/IMG_24",
		"Part_A/test_data/IMG_12",
		"Part_A/test_data/IMG_32",
		"Part_A/test_data/IMG_85",
		"Part_A/test_data/IMG_27",
		"Part_A/test_data/IMG_139",
		"Part_A/test_data/IMG_15",
		"Part_A/test_data/IMG_155",
		"Part_A/test_data/IMG_82",
		"Part_A/test_data/IMG_137",
		"Part_A/test_data/IMG_3",
		"Part_A/test_data/IMG_90",
		"Part_A/test_data/IMG_99",
		"Part_A/test_data/IMG_112",
		"Part_A/test_data/IMG_150",
		"Part_A/test_data/IMG_171",
		"Part_A/test_data/IMG_165",
		"Part_A/test_data/IMG_57",
		"Part_A/test_data/IMG_121",
		"Part_A/test_data/IMG_30",
		"Part_A/test_data/IMG_69",
		"Part_A/test_data/IMG_132",
		"Part_A/test_data/IMG_180",
		"Part_A/test_data/IMG_54",
		"Part_A/test_data/IMG_176",
		"Part_A/test_data/IMG_122",
		"Part_A/test_data/IMG_106",
		"Part_A/test_data/IMG_20",
		"Part_A/test_data/IMG_4",
		"Part_A/test_data/IMG_21",
		"Part_A/test_data/IMG_113",
		"Part_A/test_data/IMG_130",
		"Part_A/test_data/IMG_51",
		"Part_A/test_data/IMG_14",
		"Part_A/test_data/IMG_95",
		"Part_A/test_data/IMG_158",
		"Part_A/test_data/IMG_88",
		"Part_A/test_data/IMG_52",
		"Part_A/test_data/IMG_8",
		"Part_A/test_data/IMG_17",
		"Part_A/test_data/IMG_126",
		"Part_A/test_data/IMG_166",
		"Part_A/test_data/IMG_145",
		"Part_A/test_data/IMG_94",
		"Part_A/test_data/IMG_48",
		"Part_A/test_data/IMG_152",
		"Part_A/test_data/IMG_163",
		"Part_A/test_data/IMG_40",
		"Part_A/test_data/IMG_141",
		"Part_A/test_data/IMG_170",
		"Part_A/test_data/IMG_149",
		"Part_A/test_data/IMG_168",
		"Part_A/test_data/IMG_5",
		"Part_A/test_data/IMG_64",
		"Part_A/test_data/IMG_93",
		"Part_A/test_data/IMG_102",
		"Part_A/test_data/IMG_25",
		"Part_A/test_data/IMG_140",
		"Part_A/test_data/IMG_59",
		"Part_A/test_data/IMG_31",
		"Part_A/test_data/IMG_146",
		"Part_A/test_data/IMG_172",
		"Part_A/test_data/IMG_164",
		"Part_A/test_data/IMG_13",
		"Part_A/test_data/IMG_35",
		"Part_A/test_data/IMG_174",
		"Part_A/test_data/IMG_118",
		"Part_A/test_data/IMG_26",
		"Part_A/test_data/IMG_179",
		"Part_A/test_data/IMG_74",
		"Part_A/test_data/IMG_23",
		"Part_A/test_data/IMG_156",
		"Part_A/test_data/IMG_144",
		"Part_A/test_data/IMG_22",
		"Part_A/test_data/IMG_151",
		"Part_A/test_data/IMG_181",
		"Part_A/test_data/IMG_34",
		"Part_A/test_data/IMG_136",
		"Part_A/test_data/IMG_133",
		"Part_A/test_data/IMG_18",
		"Part_A/test_data/IMG_62",
		"Part_A/test_data/IMG_134",
		"Part_A/test_data/IMG_75",
		"Part_A/test_data/IMG_28",
		"Part_A/test_data/IMG_71",
		"Part_A/test_data/IMG_44",
		"Part_A/test_data/IMG_111",
	};
	std::cout << " cnt is " << sizeof(imgPaths) / sizeof(string) << std::endl;
	int imgCnt = sizeof(imgPaths) / sizeof(string);

	for (int i = 0; i < imgCnt; i++)
	{

		string imgPath = "E:\\DeepLearning\\githubCode\\crowdcount-cascaded-mtl\\outputPart_A\\density_maps_cmtl_shtechA_204\\";
		string name = imgPath + "output_" + findFileName(imgPaths[i]) + ".png";

		img = cv::imread(name, 0);

		//Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
		//cv::Mat img2;
		//erode(img, img2, element);
		//img = img2;

		threshold(img, dst, 19, 255, thresh1);

		string imgSrcPaht = "E:\\DataContest\\yuncong\\yuncong_data\\";
		string srcName = imgSrcPaht + imgPaths[i] + ".jpg";

		cv::Mat imgSrc = cv::imread(srcName, 0);

		cv::Mat local;

		int blockSize = 25;
		int constValue = 10;
		//cv::adaptiveThreshold(img, local, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY_INV, blockSize, constValue);

		//cv::imshow("density", img);

		//namedWindow("threshold二值化灰图");
		//createTrackbar("阈值:", "threshold二值化灰图", &thresh, 255, on_thresh);
		//createTrackbar("type:", "threshold二值化灰图", &thresh1, 4, on_thresh);
		//on_thresh(0, 0);
		//waitKey(0);
		//CV_THRESH_BINARY

		//SimpleBlobDetector detector;
		cv::SimpleBlobDetector::Params params;
		params.minDistBetweenBlobs = 1.0f;
		params.filterByInertia = false;
		params.filterByConvexity = false;
		params.filterByColor = false;
		params.filterByCircularity = false;
		params.filterByArea = true;
		params.minArea = 36.0f;
		params.maxArea = 500.0f;
		Ptr<SimpleBlobDetector> d = SimpleBlobDetector::create(params);

		std::vector<KeyPoint> keypoints;
		d->detect(dst, keypoints);

		Mat im_with_keypoints;
		drawKeypoints(imgSrc, keypoints, im_with_keypoints, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

		//std::cout << " head count is " << keypoints.size() << std::endl;
		// Show blobs
		//imshow("keypoints", im_with_keypoints);
		//waitKey(24);

		std::cout << imgPaths[i] << endl;
		std::cout << keypoints.size() << std::endl;

		for (auto x : keypoints)
		{
			auto halfW = x.size / 2;
			std::cout << std::max(x.pt.x - halfW, 0.0f) << " " << std::max(x.pt.y - halfW, 0.0f)
				<< " "
				<< x.size  << " " << x.size << " " << "0.5" << std::endl;
		}

	}

}

int main()
{
	showImg();
	return 0;

	ifstream fin("IMG_2.csv"); //打开文件流操作
	string line;

	auto cnt = 0;

	cv::Mat image(684, 1024, CV_32F);

	while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
	{
		//cout << "原始字符串：" << line << endl; //整行输出
		istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
		vector<string> fields; //声明一个字符串向量
		string field;

		int j = 0;
		while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
		{
			fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
			image.at<float>(cnt, j) = std::stof(field);

			j++;
		}
		string name = Trim(fields[0]); //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
		string age = Trim(fields[1]); //清除掉向量fields中第二个元素的无效字符，并赋值给变量age
		string birthday = Trim(fields[2]); //清除掉向量fields中第三个元素的无效字符，并赋值给变量birthday
		//cout << "处理之后的字符串：" << name << "\t" << age << "\t" << birthday << endl;

		//cout << " size is " << fields.size() << std::endl;

		cnt++;
	}

	cout << "cnt is " << cnt << std::endl;
	return EXIT_SUCCESS;
}
