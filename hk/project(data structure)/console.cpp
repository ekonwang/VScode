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
		std::cout << "\n\n\n\n" << "�������������Խ�������Ҫ�Ĳ�����" << std::endl;
		std::cout << "��������(0) , ���������ļ�(1), ������Ϣ(2), ɾ����Ϣ(3), ��ѯ��·(4), ��ѯ������Ϣ(5), ��ѯȫ��������Ϣ(6)\n\n" << std::endl;
		std::cout << "Ŀǰ��ѡ���� : " << std::endl;
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
					std::cout << "����ɾ��ԭʼ��Ϣ..." << "\n\n\n" << std::endl;
					del_g = g;
					delete del_g;
					g = new Graph();
					std::cout << "ɾ�����." << std::endl;
					g->Load_file();
					break;
				case 2:
					std::cout << "��ʼ���������..." << "\n\n\n" << std::endl;
					g->Insert();
					break;
				case 3:
					std::cout << "��ʼ��ɾ������..." << "\n\n\n" << std::endl;
					g->Delete();
					break;
				case 4:
					std::cout << "��ʼ����·��ѯ����..." << "\n\n\n" << std::endl;
					std::cout << "���������ڵĳ��У�(�� Chengdu)" << std::endl;
					std::cin >> NamestrA;
					std::cout << "�������Ŀ�ĵس��У�" << std::endl;
					std::cin >> NamestrB;
					std::cout << "����ʲô���ں������ (�� 12/31/2020)"<< std::endl;
					std::cin >> tmp[1] >> ch >>tmp[2] >> ch >> tmp[3];
					std::cout << "���ܽ��ܵ��������ʱ�̣� (�� 14:0��1:21��23:59)" << std::endl;
					std::cin >> tmp[4] >> ch >> tmp[5];
					std::cout << "����ѡ��Ľ�ͨ��ʽ��������һ�����֣��ɻ�0�� ��1��" << std::endl;
					std::cin >> arg;
					std::cout << "����ѡ��������·��������˵���·��������һ������(ǰ��0�� ����1)" << std::endl;
					std::cin >> tag;
					if (!(idA = g->GetID(NamestrA))) throw(NamestrA);
					if (!(idB = g->GetID(NamestrB))) throw(NamestrB);
					if (!(arg == 0 || arg == 1)) throw(arg);
					if (!(tag == 0 || tag == 1)) throw(tag);
					t.set(tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);
					g->ProperPath(idA, idB, t, arg, tag);
					break;
				case 5:
					std::cout << "��ʼ�����в�ѯ����..." << "\n\n\n" << std::endl;
					std::cout << "��������Ҫ��ѯ�ĳ��У�(�� Chengdu)" << std::endl;
					std::cin >> NamestrA;
					idA = g->GetID(NamestrA);
					if (!idA) throw(idA);
					g->ShowCityInfo(idA);
					break;
				case 6:
					std::cout << "��ʼ�����в�ѯ����..." << "\n\n\n" << std::endl;
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