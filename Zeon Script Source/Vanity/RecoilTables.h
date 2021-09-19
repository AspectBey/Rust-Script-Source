struct vec2
{
	double x;
	double y;
};

struct vec1
{
	double x;
	double y;
};

std::vector<vec1> Recoil_Ak47 = { {-69.0, 100.0},{10.0, 92.0},{-110.0, 83.0},{-85.0, 75.0},{0.0, 67.0},{33.0, 57.0},{58.0, 48.0},{76.0, 39.0},{84.0, 29.0},{85.0, 19.0},{76.0, 20.0},{60.0, 37.0},{34.0, 50.0},
	{2.0, 59.0},{-30.0, 65.0},{-55.0, 67.0},{-74.0, 64.0},{-86.0, 59.0},{-92.0, 49.0},{-91.0, 34.0},{-84.0, 17.0},{-70.0, 10.0},{-49.0, 28.0},{-22.0, 42.0},{24.0, 51.0},{72.0, 56.0},{97.0, 57.0},{98.0, 51.0},{77.0, 43.0} };

std::vector<vec2> Recoil_Lr300 = { {-5.88604, 49.91794}, {-17.4990 , 61.77337},{-18.5691, 65.90758}, {-24.59519, 62.32076},{-33.35285, 51.09613}, {-25.29157, 41.16616},{-19.41173, 35.38332}, {-4.43821, 30.10056},{18.17255, 25.31769}, {34.33775, 21.03471},{40.05314, 17.25143}, {35.31853, 13.96823}, {20.13392, 11.25902}, {-0.87096, 9.84447},{-11.07738, 8.84336}, {-18.49688, 7.95758},
	{-24.17522, 8.18694}, {-28.11259, 7.53163},{-30.3088, 6.99146}, {-30.76423, 6.56681},{-29.47831, 6.25711}, {-26.45161, 6.06293},{-21.68356, 6.98389}, {-15.17473, 8.01999},{-6.73436, 5.17161}, {26.76074, 5.43837},{60.85377, 5.82027}, {7.19454, 6.3175}, {60.03506, 3.6474}, {0, 8}, {0, 0} };

std::vector<vec2> Recoil_Mp5a4 = { {0, 43}, {0, 58}, {0, 65}, {25, 66}, {59, 58}, {63, 42}, {46, 27}, {3, 23}, {-37, 19}, {-47, 18}, {-40, 18}, {-8, 7}, {16, 12}, {28, 11},
	{35, 9}, {34, 8}, {25, 6}, {12, 0}, {-4, 2}, {-6, 2}, {-18, 0}, {-27, 5}, {-26, 0}, {-27, 0}, {-20, 0}, {-32, 0}, {-12, 0}, {-25, 0}, {-4, 0}, {0, 0}, {43, 0} };


std::vector<vec2> Recoil_Custom_g = { {-28, 52}, {-10, 53}, {0, 53}, {11, 44}, {20, 45}, {22, 42}, {17, 35}, {7, 30}, {-9, 27}, {-13, 28}, {-23, 22}, {-21, 21}, {-15, 24},
	{0, 13}, {20, 14}, {16, 12}, {29, 19}, {7, 6}, {11, 10}, {-4, 8}, {-8, 13}, {-7, 2}, {-13, 14} };

std::vector<vec2> Recoil_Thompson_g = { {-29, 63}, {-12, 61}, {9, 61}, {21, 55}, {25, 52}, {21, 43}, {5, 32}, {-16, 33}, {-24, 25}, {-24, 26}, {-14, 21}, {7, 17}, {16, 18},
	{23, 16}, {25, 17}, {8, 16}, {-5, 5}, {-13, 15}, {-14, 8} };

std::vector<vec2> Recoil_Semi_r = { {0, 75}, {0, 75} };

std::vector<vec2> Recoil_M249 = { {0,58},{0,58} };

std::vector<vec2> python_t = { {0,140}, {0,140} };

std::vector<vec2> m39_t = { {0,68}, {0,68} };

std::vector<double> ControlTime_Ak47 = { 101.96149709966872,90.6333814724611,114.60598637206294,103.37874368443146,62.25151186427745,60.29530438019354,70.9327831420658,80.05526144256157,
86.20256669256554,82.68010184667988,72.82145888317788,70.0451048111144,62.85979604582978,59.51642457624619,67.66762996283607,86.74060009403034,92.3363599080854,104.34161954944257,
100.09299204005345,92.58780746901739,80.48062700875559,64.4889202349561,50.56417811530545,42.386907899993936,56.63787408680247,91.5937793023631,112.38667610336424,111.39338971888095,
87.5067801164596 };
std::vector<double> control_lr = { 50.4865, 63.4098, 69.3522, 69.0191, 60.3428, 50.2792, 40.6239, 30.6262, 31.3695, 40.5333, 43.8973, 38.2302, 23.2199, 9.9479, 14.2676, 20.2684, 25.3868, 29.0513, 31.0987, 31.4694, 30.1404, 27.1089, 22.3954, 16.0886, 8.5469, 27.4875, 61.5337, 72.6973, 60.8312 };
std::vector<double> control_mp5 = { 43.4419, 58.6690, 66.4111, 71.3855, 83.6416, 79.3989, 52.7631, 21.6158, 40.9873, 52.6494, 42.2424, 15.0739, 19.1590, 29.4080, 34.5606, 33.5879, 26.2953, 12.7693, 4.2078, 10.9808, 17.0705, 21.7442, 24.9178, 26.5703, 26.6934, 25.2838, 22.3394, 17.8592, 11.8426 };
std::vector<double> control_custom = { 72.9421, 66.6362, 62.9748, 61.7506, 60.9351, 57.2009, 49.1641, 38.9760, 35.0067, 37.6384, 39.1880, 36.0753, 28.1717, 21.2342, 24.3584, 28.9871, 29.9278, 26.0702, 18.1194, 13.4381, 16.8564, 19.2740, 18.3203 };
std::vector<double> control_thompson = { 86.5989, 78.3471, 74.4083, 73.5689, 69.2117, 57.6526, 44.2315, 43.1724, 46.8478, 43.8323, 32.5948, 25.5974, 32.2693, 36.0543, 31.8981, 20.6215, 16.9973, 22.0460, 22.6901 };

namespace WeaponData {
	struct {
		const double Delay = 133.3333;
	}AK47;
	struct {
		const int Delay = 120;
	}LR300;
	struct {
		const int Delay = 100;
	}MP5;
	struct {
		const int Delay = 100;
	}CUSTOM_SMG;
	struct {
		const int Delay = 129;
	}THOMPSON;
	struct {
		const int Delay = 150;
	}SEMI;
	struct {
		const int Delay = 103;
	}M249;
	struct {
		const int Delay = 110;
	}PYTHON;
	struct {
		const int Delay = 205;
	}M39;
}
namespace Multiplyer {
	struct {
		double x8 = 3.84;
		double x16 = 7.68;
		double Holo = 1.2;
		double Simple = 0.8;
		double None = 1.0;
	}Scope;

	struct {
		double Suppressor = 0.8;
		double None = 1.0;
	}Barrel;

	struct {
		int crouch = 2;
		int none = 1;
	}Crouch;

}