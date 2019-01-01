#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "opencv2/opencv.hpp"
#include "features2d.hpp"

using namespace std;
using namespace cv;

extern int thresh;
extern int thresh1;

extern Mat dst;

extern cv::Mat img;

string findFileName(string name);

void showImgPartB()
{
	string imgPaths[] = {
		"Part_B/test_data/IMG_310",
		"Part_B/test_data/IMG_90",
		"Part_B/test_data/IMG_99",
		"Part_B/test_data/IMG_112",
		"Part_B/test_data/IMG_150",
		"Part_B/test_data/IMG_171",
		"Part_B/test_data/IMG_315",
		"Part_B/test_data/IMG_230",
		"Part_B/test_data/IMG_209",
		"Part_B/test_data/IMG_191",
		"Part_B/test_data/IMG_165",
		"Part_B/test_data/IMG_245",
		"Part_B/test_data/IMG_57",
		"Part_B/test_data/IMG_233",
		"Part_B/test_data/IMG_121",
		"Part_B/test_data/IMG_30",
		"Part_B/test_data/IMG_69",
		"Part_B/test_data/IMG_132",
		"Part_B/test_data/IMG_208",
		"Part_B/test_data/IMG_180",
		"Part_B/test_data/IMG_54",
		"Part_B/test_data/IMG_176",
		"Part_B/test_data/IMG_122",
		"Part_B/test_data/IMG_304",
		"Part_B/test_data/IMG_243",
		"Part_B/test_data/IMG_302",
		"Part_B/test_data/IMG_253",
		"Part_B/test_data/IMG_217",
		"Part_B/test_data/IMG_290",
		"Part_B/test_data/IMG_106",
		"Part_B/test_data/IMG_20",
		"Part_B/test_data/IMG_167",
		"Part_B/test_data/IMG_159",
		"Part_B/test_data/IMG_125",
		"Part_B/test_data/IMG_2",
		"Part_B/test_data/IMG_67",
		"Part_B/test_data/IMG_154",
		"Part_B/test_data/IMG_79",
		"Part_B/test_data/IMG_201",
		"Part_B/test_data/IMG_9",
		"Part_B/test_data/IMG_101",
		"Part_B/test_data/IMG_270",
		"Part_B/test_data/IMG_127",
		"Part_B/test_data/IMG_36",
		"Part_B/test_data/IMG_135",
		"Part_B/test_data/IMG_116",
		"Part_B/test_data/IMG_238",
		"Part_B/test_data/IMG_205",
		"Part_B/test_data/IMG_228",
		"Part_B/test_data/IMG_49",
		"Part_B/test_data/IMG_313",
		"Part_B/test_data/IMG_234",
		"Part_B/test_data/IMG_286",
		"Part_B/test_data/IMG_142",
		"Part_B/test_data/IMG_42",
		"Part_B/test_data/IMG_19",
		"Part_B/test_data/IMG_11",
		"Part_B/test_data/IMG_203",
		"Part_B/test_data/IMG_273",
		"Part_B/test_data/IMG_274",
		"Part_B/test_data/IMG_268",
		"Part_B/test_data/IMG_284",
		"Part_B/test_data/IMG_100",
		"Part_B/test_data/IMG_271",
		"Part_B/test_data/IMG_6",
		"Part_B/test_data/IMG_16",
		"Part_B/test_data/IMG_109",
		"Part_B/test_data/IMG_68",
		"Part_B/test_data/IMG_173",
		"Part_B/test_data/IMG_104",
		"Part_B/test_data/IMG_225",
		"Part_B/test_data/IMG_131",
		"Part_B/test_data/IMG_254",
		"Part_B/test_data/IMG_117",
		"Part_B/test_data/IMG_283",
		"Part_B/test_data/IMG_267",
		"Part_B/test_data/IMG_194",
		"Part_B/test_data/IMG_309",
		"Part_B/test_data/IMG_97",
		"Part_B/test_data/IMG_108",
		"Part_B/test_data/IMG_107",
		"Part_B/test_data/IMG_91",
		"Part_B/test_data/IMG_78",
		"Part_B/test_data/IMG_282",
		"Part_B/test_data/IMG_80",
		"Part_B/test_data/IMG_77",
		"Part_B/test_data/IMG_251",
		"Part_B/test_data/IMG_224",
		"Part_B/test_data/IMG_92",
		"Part_B/test_data/IMG_114",
		"Part_B/test_data/IMG_307",
		"Part_B/test_data/IMG_33",
		"Part_B/test_data/IMG_81",
		"Part_B/test_data/IMG_221",
		"Part_B/test_data/IMG_300",
		"Part_B/test_data/IMG_70",
		"Part_B/test_data/IMG_66",
		"Part_B/test_data/IMG_7",
		"Part_B/test_data/IMG_183",
		"Part_B/test_data/IMG_89",
		"Part_B/test_data/IMG_265",
		"Part_B/test_data/IMG_72",
		"Part_B/test_data/IMG_83",
		"Part_B/test_data/IMG_277",
		"Part_B/test_data/IMG_206",
		"Part_B/test_data/IMG_308",
		"Part_B/test_data/IMG_199",
		"Part_B/test_data/IMG_306",
		"Part_B/test_data/IMG_292",
		"Part_B/test_data/IMG_216",
		"Part_B/test_data/IMG_119",
		"Part_B/test_data/IMG_249",
		"Part_B/test_data/IMG_169",
		"Part_B/test_data/IMG_223",
		"Part_B/test_data/IMG_184",
		"Part_B/test_data/IMG_229",
		"Part_B/test_data/IMG_312",
		"Part_B/test_data/IMG_204",
		"Part_B/test_data/IMG_178",
		"Part_B/test_data/IMG_232",
		"Part_B/test_data/IMG_120",
		"Part_B/test_data/IMG_231",
		"Part_B/test_data/IMG_43",
		"Part_B/test_data/IMG_266",
		"Part_B/test_data/IMG_153",
		"Part_B/test_data/IMG_56",
		"Part_B/test_data/IMG_227",
		"Part_B/test_data/IMG_103",
		"Part_B/test_data/IMG_65",
		"Part_B/test_data/IMG_38",
		"Part_B/test_data/IMG_29",
		"Part_B/test_data/IMG_61",
		"Part_B/test_data/IMG_110",
		"Part_B/test_data/IMG_86",
		"Part_B/test_data/IMG_148",
		"Part_B/test_data/IMG_222",
		"Part_B/test_data/IMG_53",
		"Part_B/test_data/IMG_147",
		"Part_B/test_data/IMG_84",
		"Part_B/test_data/IMG_200",
		"Part_B/test_data/IMG_45",
		"Part_B/test_data/IMG_157",
		"Part_B/test_data/IMG_212",
		"Part_B/test_data/IMG_96",
		"Part_B/test_data/IMG_250",
		"Part_B/test_data/IMG_301",
		"Part_B/test_data/IMG_37",
		"Part_B/test_data/IMG_87",
		"Part_B/test_data/IMG_76",
		"Part_B/test_data/IMG_177",
		"Part_B/test_data/IMG_46",
		"Part_B/test_data/IMG_63",
		"Part_B/test_data/IMG_60",
		"Part_B/test_data/IMG_129",
		"Part_B/test_data/IMG_210",
		"Part_B/test_data/IMG_259",
		"Part_B/test_data/IMG_287",
		"Part_B/test_data/IMG_241",
		"Part_B/test_data/IMG_162",
		"Part_B/test_data/IMG_47",
		"Part_B/test_data/IMG_294",
		"Part_B/test_data/IMG_195",
		"Part_B/test_data/IMG_123",
		"Part_B/test_data/IMG_55",
		"Part_B/test_data/IMG_220",
		"Part_B/test_data/IMG_98",
		"Part_B/test_data/IMG_115",
		"Part_B/test_data/IMG_138",
		"Part_B/test_data/IMG_247",
		"Part_B/test_data/IMG_296",
		"Part_B/test_data/IMG_50",
		"Part_B/test_data/IMG_58",
		"Part_B/test_data/IMG_41",
		"Part_B/test_data/IMG_10",
		"Part_B/test_data/IMG_175",
		"Part_B/test_data/IMG_73",
		"Part_B/test_data/IMG_182",
		"Part_B/test_data/IMG_161",
		"Part_B/test_data/IMG_124",
		"Part_B/test_data/IMG_160",
		"Part_B/test_data/IMG_128",
		"Part_B/test_data/IMG_39",
		"Part_B/test_data/IMG_213",
		"Part_B/test_data/IMG_219",
		"Part_B/test_data/IMG_105",
		"Part_B/test_data/IMG_278",
		"Part_B/test_data/IMG_281",
		"Part_B/test_data/IMG_215",
		"Part_B/test_data/IMG_143",
		"Part_B/test_data/IMG_1",
		"Part_B/test_data/IMG_314",
		"Part_B/test_data/IMG_303",
		"Part_B/test_data/IMG_24",
		"Part_B/test_data/IMG_12",
		"Part_B/test_data/IMG_32",
		"Part_B/test_data/IMG_240",
		"Part_B/test_data/IMG_85",
		"Part_B/test_data/IMG_235",
		"Part_B/test_data/IMG_192",
		"Part_B/test_data/IMG_193",
		"Part_B/test_data/IMG_27",
		"Part_B/test_data/IMG_264",
		"Part_B/test_data/IMG_139",
		"Part_B/test_data/IMG_15",
		"Part_B/test_data/IMG_155",
		"Part_B/test_data/IMG_244",
		"Part_B/test_data/IMG_82",
		"Part_B/test_data/IMG_279",
		"Part_B/test_data/IMG_137",
		"Part_B/test_data/IMG_197",
		"Part_B/test_data/IMG_3",
		"Part_B/test_data/IMG_262",
		"Part_B/test_data/IMG_257",
		"Part_B/test_data/IMG_4",
		"Part_B/test_data/IMG_21",
		"Part_B/test_data/IMG_113",
		"Part_B/test_data/IMG_236",
		"Part_B/test_data/IMG_130",
		"Part_B/test_data/IMG_51",
		"Part_B/test_data/IMG_14",
		"Part_B/test_data/IMG_226",
		"Part_B/test_data/IMG_269",
		"Part_B/test_data/IMG_95",
		"Part_B/test_data/IMG_255",
		"Part_B/test_data/IMG_311",
		"Part_B/test_data/IMG_158",
		"Part_B/test_data/IMG_88",
		"Part_B/test_data/IMG_202",
		"Part_B/test_data/IMG_237",
		"Part_B/test_data/IMG_263",
		"Part_B/test_data/IMG_52",
		"Part_B/test_data/IMG_8",
		"Part_B/test_data/IMG_17",
		"Part_B/test_data/IMG_305",
		"Part_B/test_data/IMG_126",
		"Part_B/test_data/IMG_166",
		"Part_B/test_data/IMG_145",
		"Part_B/test_data/IMG_288",
		"Part_B/test_data/IMG_261",
		"Part_B/test_data/IMG_94",
		"Part_B/test_data/IMG_48",
		"Part_B/test_data/IMG_280",
		"Part_B/test_data/IMG_276",
		"Part_B/test_data/IMG_218",
		"Part_B/test_data/IMG_152",
		"Part_B/test_data/IMG_295",
		"Part_B/test_data/IMG_163",
		"Part_B/test_data/IMG_316",
		"Part_B/test_data/IMG_40",
		"Part_B/test_data/IMG_141",
		"Part_B/test_data/IMG_170",
		"Part_B/test_data/IMG_186",
		"Part_B/test_data/IMG_298",
		"Part_B/test_data/IMG_248",
		"Part_B/test_data/IMG_188",
		"Part_B/test_data/IMG_258",
		"Part_B/test_data/IMG_149",
		"Part_B/test_data/IMG_246",
		"Part_B/test_data/IMG_168",
		"Part_B/test_data/IMG_239",
		"Part_B/test_data/IMG_5",
		"Part_B/test_data/IMG_190",
		"Part_B/test_data/IMG_64",
		"Part_B/test_data/IMG_93",
		"Part_B/test_data/IMG_275",
		"Part_B/test_data/IMG_102",
		"Part_B/test_data/IMG_25",
		"Part_B/test_data/IMG_140",
		"Part_B/test_data/IMG_59",
		"Part_B/test_data/IMG_31",
		"Part_B/test_data/IMG_146",
		"Part_B/test_data/IMG_185",
		"Part_B/test_data/IMG_172",
		"Part_B/test_data/IMG_187",
		"Part_B/test_data/IMG_164",
		"Part_B/test_data/IMG_13",
		"Part_B/test_data/IMG_291",
		"Part_B/test_data/IMG_196",
		"Part_B/test_data/IMG_35",
		"Part_B/test_data/IMG_174",
		"Part_B/test_data/IMG_118",
		"Part_B/test_data/IMG_26",
		"Part_B/test_data/IMG_242",
		"Part_B/test_data/IMG_179",
		"Part_B/test_data/IMG_207",
		"Part_B/test_data/IMG_214",
		"Part_B/test_data/IMG_256",
		"Part_B/test_data/IMG_74",
		"Part_B/test_data/IMG_23",
		"Part_B/test_data/IMG_156",
		"Part_B/test_data/IMG_144",
		"Part_B/test_data/IMG_22",
		"Part_B/test_data/IMG_299",
		"Part_B/test_data/IMG_252",
		"Part_B/test_data/IMG_211",
		"Part_B/test_data/IMG_260",
		"Part_B/test_data/IMG_289",
		"Part_B/test_data/IMG_285",
		"Part_B/test_data/IMG_272",
		"Part_B/test_data/IMG_151",
		"Part_B/test_data/IMG_181",
		"Part_B/test_data/IMG_34",
		"Part_B/test_data/IMG_136",
		"Part_B/test_data/IMG_297",
		"Part_B/test_data/IMG_133",
		"Part_B/test_data/IMG_18",
		"Part_B/test_data/IMG_62",
		"Part_B/test_data/IMG_293",
		"Part_B/test_data/IMG_134",
		"Part_B/test_data/IMG_198",
		"Part_B/test_data/IMG_75",
		"Part_B/test_data/IMG_28",
		"Part_B/test_data/IMG_71",
		"Part_B/test_data/IMG_189",
		"Part_B/test_data/IMG_44",
		"Part_B/test_data/IMG_111",
	};
	std::cout << " cnt is " << sizeof(imgPaths) / sizeof(string) << std::endl;
	int imgCnt = sizeof(imgPaths) / sizeof(string);

	for (int i = 0; i < imgCnt; i++)
	{

		string imgPath = "E:\\DeepLearning\\githubCode\\crowdcount-cascaded-mtl\\outputPart_B\\density_maps_cmtl_shtechB_768\\";
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
				<< x.size << " " << x.size << " " << "0.5" << std::endl;
		}

	}

}
