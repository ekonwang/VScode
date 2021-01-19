#include "device.h"
int main() {
	std::ios::sync_with_stdio(0);
	std::string NamestrA, NamestrB;
	Time t;
	int input, idA, idB, tmp[6], i, arg, tag;
	char ch;
	Graph* g = new Graph(), *del_g;
	g->Load_file();

	while (1) {
		std::cout << "\n\n\n\n" << "继续输入数字以进行你想要的操作：" << std::endl;
		std::cout << "结束运行(0) , 重新载入文件(1), 插入信息(2), 删除信息(3), 查询线路(4), 查询城市信息(5), 查询全部城市信息(6)\n\n" << std::endl;
		std::cout << "目前可选城市 : " << std::endl;
		for (int i = 1; i <= g->GetCityNum(); i++) { 
			std::cout << std::setiosflags(std::ios::left) << std::setw(10) << g->GetName(i);
			std::cout << '\t' ;
		}
		std::cout << "\n\n" << std::endl;
		try {
			std::cin >> input;
			switch (input) {
				case 0:
					delete g;
					system("pause");
					return 0;
				case 1:
					std::cout << "正在删除原始信息..." << "\n\n\n" << std::endl;
					del_g = g;
					delete del_g;
					g = new Graph();
					std::cout << "删除完毕." << std::endl;
					g->Load_file();
					break;
				case 2:
					std::cout << "初始化插入程序..." << "\n\n\n" << std::endl;
					g->Insert();
					break;
				case 3:
					std::cout << "初始化删除程序..." << "\n\n\n" << std::endl;
					g->Delete();
					break;
				case 4:
					std::cout << "初始化线路查询程序..." << "\n\n\n" << std::endl;
					std::cout << "输入你所在的城市：(如 Chengdu)" << std::endl;
					std::cin >> NamestrA;
					std::cout << "输入你的目的地城市：" << std::endl;
					std::cin >> NamestrB;
					std::cout << "你在什么日期后出发： (如 12/31/2020)"<< std::endl;
					std::cin >> tmp[1] >> ch >>tmp[2] >> ch >> tmp[3];
					std::cout << "你能接受的最早出发时刻： (如 14:0、1:21、23:59)" << std::endl;
					std::cin >> tmp[4] >> ch >> tmp[5];
					std::cout << "你想选择的交通方式，请输入一个数字（飞机0， 火车1）" << std::endl;
					std::cin >> arg;
					std::cout << "你想选择最快的线路还是最便宜的线路？请输入一个数字(前者0， 后者1)" << std::endl;
					std::cin >> tag;
					if (!(idA = g->GetID(NamestrA))) throw(NamestrA);
					if (!(idB = g->GetID(NamestrB))) throw(NamestrB);
					if (!(arg == 0 || arg == 1)) throw(arg);
					if (!(tag == 0 || tag == 1)) throw(tag);
					t.set(tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);
					g->ProperPath(idA, idB, t, arg, tag);
					break;
				case 5:
					std::cout << "初始化城市查询程序..." << "\n\n\n" << std::endl;
					std::cout << "输入你想要查询的城市：(如 Chengdu)" << std::endl;
					std::cin >> NamestrA;
					idA = g->GetID(NamestrA);
					if (!idA) throw(idA);
					g->ShowCityInfo(idA);
					break;
				case 6:
					std::cout << "初始化城市查询程序..." << "\n\n\n" << std::endl;
					for (i = 1; i <= g->GetCityNum(); i++) g->ShowCityInfo(i);
					break;
				default:
					throw(input);
			}
		}
		catch (int invalid) {
			std::cout << invalid << ": invalid input! please input again!" << "\n\n\n" << std::endl;
		}
		catch (std::string invalid_str) {
			std::cout << invalid_str << ": City not on board. please try again." << "\n\n\n" << std::endl;
		}

	}
	return 0;
}