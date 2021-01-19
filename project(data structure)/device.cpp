#include "device.h"   //declaration
#include "err_out.h"  //error output
#include "constant.h"



std::map <std::string, int> str2ID;
std::map <int, std::string> ID2str;
/* Time ������������Ա�����Ķ��� */
Time::Time() {
    year = month = date = hour = min = 0;
}
/* �����������Ϊ˽�к�����Ա���ú�������Խ��Time���캯����ʱ���ʽ��� */
Time::Time(int y, int m, int d, int h, int minute, int arg) {
    year = y;
    month = m;
    date = d;
    hour = h;
    min = minute;
}
Time::Time(int m, int d, int h, int minute, int y) {
    unsigned int um = m;
    unsigned int ud = d;
    unsigned int uh = h;
    unsigned int umin = minute;
    if (um > LargeMonth || ud > LargeDate || uh > LargeHour || umin > Largemin) {
        Time t_wrong(y, m, d, h, minute, 1);
        std::string str("TIME_CONSTRUCTION");
        time_overflow(str, t_wrong);
    }
    else {
        year = y;
        month = m;
        date = d;
        hour = h;
        min = minute;
    }
}
Time::~Time() {}
void Time::SetLarge() {
    year = LargeYear;
    month = LargeMonth;
    date = LargeDate;
    hour = LargeHour;
    min = Largemin;
}
void Time::Set(Time& t) {
    year = t.year;
    month = t.month;
    date = t.date;
    hour = t.hour;
    min = t.min;
}
bool Time::set(int m, int d, int y, int h, int minute) {
    month = m;
    date = d;
    year = y;
    hour = h;
    min = minute;
    return true;
}
void Time::FormatShow(int arg) const {  //output with '\t' when argument == 1, and output with '\n' when arg == 2.
    std::cout << month << '/' << date << '/' << year << "\t" << hour << ':' << min;
    if (arg == 1) std::cout << '\t';
    else if (arg == 2) std::cout << '\n';
}
bool Time::cmpg(Time& t)const {          //�ж�ʱ���Ƿ����
    if (year > t.year) return true;
    else if (year == t.year && month > t.month) return true;
    else if (year == t.year && month == t.month && date > t.date) return true;
    else if (year == t.year && month == t.month && date == t.date && hour > t.hour) return true;
    else if (year == t.year && month == t.month && date == t.date && hour == t.hour && min > t.min) return true;
    else return false;
}

bool Time::cmpl(Time& t)const {          //�ж�ʱ���Ƿ��С
    if (year < t.year) return true;
    else if (year == t.year && month < t.month) return true;
    else if (year == t.year && month == t.month && date < t.date) return true;
    else if (year == t.year && month == t.month && date == t.date && hour < t.hour) return true;
    else if (year == t.year && month == t.month && date == t.date && hour == t.hour && min < t.min) return true;
    else return false;
}

bool Time::cmpe(Time& t)const {          //�ж�ʱ���Ƿ���ͬ
    return (year == t.year) && (month == t.month) && (date == t.date) && (hour == t.hour) && (min == t.min);
}

FlightTrain::FlightTrain(int p, Time& tA, Time& tB, int argA, int argB) {
    price = p;
    depart.year = tA.year;
    depart.date = tA.date;
    depart.month = tA.month;
    depart.hour = tA.hour;
    depart.min = tA.min;
    arrive.year = tB.year;
    arrive.date = tB.date;
    arrive.month = tB.month;
    arrive.hour = tB.hour;
    arrive.min = tB.min;
    dest_station = 0;
    from_station = 0;
    link = NULL;
}
FlightTrain::~FlightTrain() {}
void FlightTrain::show_info(int from, int dest) {
    std::cout << std::setiosflags(std::ios::left) << std::setw(10) << ID2str[from] << std::setw(10) << ID2str[dest] << '\t';
    depart.FormatShow(1);
    arrive.FormatShow(1);
    std::cout << price << std::endl;
}
City::City(std::string NameStr) {
    cityName = NameStr;
    FlightAdjNum = TrainAdjNum = 0;
    memset(info, 0, sizeof(info));
}
City::~City() {                              //destruction function of City objective.
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= MaxCityNum; j++) {
            FlightTrain* p = info[i][j];
            deleteRe(p);
        }
    }
}
void City::deleteRe(FlightTrain* ptr) {           //delete link nodes of information recursively.
    if (!ptr) return;
    else {
        deleteRe(ptr->link);
        FlightTrain* dptr = ptr;
        delete dptr;
    }
}
bool City::Delete(int CityID, Time& tA, Time& tB, int arg) {
    if (arg != 0 && arg != 1) {
        std::string str("CITY_DELETE");
        arg_error(str, arg);
    }
    FlightTrain* head = info[arg][CityID], *d_ptr, *ptr = head;
    int flag = 0;
    if (head == NULL) {
        flag = 0;
    }else if (head->depart.cmpe(tA) && head->arrive.cmpe(tB)) {
        flag = 1;
        info[arg][CityID] = head->link;
        delete head;
    }else {
        while ((d_ptr = ptr->link) != NULL) {
            if (d_ptr->depart.cmpe(tA) && d_ptr->arrive.cmpe(tB)) {
                ptr->link = d_ptr->link;
                delete d_ptr;
                flag = 1;
                break;
            }
            ptr = d_ptr;
        }
    }
    if (!flag) { std::cout << "��Ϣɾ��ʧ�ܣ�δ�ҵ�������Ϣ"; return false; }
    else { std::cout << "��Ϣɾ���ɹ�."; return true; }
}

bool City::insert(int CityID, Time& tA, Time& tB, int Price, int arg) {
    if (arg != 0 && arg != 1) {
        std::string str("CITY_INSERT");
        arg_error(str, arg);
    }
    FlightTrain* p = info[arg][CityID], * q = new FlightTrain(Price, tA, tB);
    if (p == NULL) info[arg][CityID] = q;
    else {
        if (p->depart.cmpg(tA)) { q->link = p; info[arg][CityID] = q; }
        else {
            while (p->link != NULL && p->link->depart.cmpl(tA)) p = p->link;
            q->link = p->link;
            p->link = q;
        }
    }
    return true;
}
int City::Show_info(int arg) {
    if (arg != 1 && arg != 0) {
        std::string str("CITY_SHOW_INFO");
        arg_error(str, arg);                                    //�����������ȷ�����ô����������arg_error
    }
    int count = 0;
    std::cout << "********************************************" << std::endl << std::endl;
    std::cout << cityName;
    if (!arg) std::cout << " ������Ϣ��" << std::endl << std::endl;
    else std::cout << " �г���Ϣ�� " << std::endl << std::endl;
    for (int i = 1; i <= MaxCityNum; i++) {
        if (!ID2str.count(i)) continue;
        FlightTrain* p = info[arg][i];
        while (p != NULL) { p->show_info(str2ID[cityName], i); count++; p = p->link; }
    }
    std::cout << "********************************************" << std::endl << std::endl << std::endl << std::endl;
    return count;
}
Graph::Graph() {
    CityNum = NULL;
    memset(Cheapest, 0, sizeof(Cheapest));
    memset(CityTable, 0, sizeof(CityTable));
    memset(C, 0, sizeof(C));
    memset(V, 0, sizeof(V));
    memset(R, 0, sizeof(R));
}
void Graph::FPath(int from, int dest, Time departureTime, int arg) {        //Dijkstra Algorithm.
    int v[MaxCityNum + 1] = { 0 };                                          //Visited city table.
    City* CityFrom;
    FlightTrain* ptr;
    int pos = dest;

    memset(V, 0, sizeof(V));
    for (int i = 0; i <= CityNum; i++) {
        VPath[arg][i].SetLarge();
    }
    VPath[arg][from].Set(departureTime);

    for (int i = 1; i <= CityNum; i++) {
        int cur_least = 0;
        for (int j = 1; j <= CityNum; j++) {
            if (!v[j] && VPath[arg][j].cmpl(VPath[arg][cur_least])) cur_least = j; //find the least one in the unvisited cities.   
        }
        if (!cur_least) break;
        v[cur_least] = 1;                                                          //���ҵ��Ľڵ���Ϊ�Ѿ����ʵĽڵ�

        CityFrom = CityTable[cur_least];
        for (int j = 1; j <= CityNum; j++) {
            if (v[j]) continue;
            ptr = CityFrom->info[arg][j];
            while (ptr != NULL && ptr->depart.cmpl(VPath[arg][cur_least])) ptr = ptr->link;
            if (ptr == NULL) continue;
            else {
                while (ptr != NULL) {
                    if (ptr->arrive.cmpl(VPath[arg][j])) {
                        VPath[arg][j].Set(ptr->arrive);                           //update
                        V[arg][j] = cur_least;
                    }
                    ptr = ptr->link;
                }
            }
        }
    }
    R[arg][0] = 0;
    while (pos != from) {
        R[arg][0]++;
        pos = V[arg][pos];
        if (R[arg][0] >= MaxCityNum) {
            R[arg][0] = 0; return;
        }
    }
    R[arg][R[arg][0]] = pos = dest;
    for (int i = R[arg][0] - 1; i > 0; --i) {
        R[arg][i] = V[arg][pos]; 
        pos = V[arg][pos];
    }
}
// ����Ѱ�������·�������ܼ�ʹ�õϽ�˹�����㷨����Ϊ���Ǳ��뽫����/�𳵷����뵽վʱ����Ϊ��һ�������ۺϿ���
// ��˶���CPath��Ѱ�ң����ǲ����˵ݹ麯�����õķ����������ֿ��ܵ�·�������ҶԵݹ麯���������Ż�
// ʹ��ӵ���˺õö�����ܣ�����Ķ��ų����ڶ಻���ܵ�·����
void Graph::CPath(int from, int dest, Time departureTime, int arg) {
    Cheapest[arg] = LargePrice;
    City* Cptr = CityTable[from];
    FlightTrain* p = Cptr->info[arg][dest];

    memset(V[arg], 0, sizeof(V[arg]));  V[arg][from] = 1;
    memset(C[arg], 0, sizeof(C[arg]));                         // ��ǰ�ݹ�·�����ȴ�����C[0]λ�ã�C[1]���Ժ��д���·���ڵ����ID                     
    while (p != NULL) {
        if (p -> price < Cheapest[arg]) {
            Cheapest[arg] = p->price;
            R[arg][0] = 1;                                     // ��ǰ�ݹ麯�����·�����ȴ�����R[0]λ��
            R[arg][1] = dest;                                  // R[1]���Ժ󴢴����·��;������ID
            VPath[arg][1].Set(p->arrive);
        }
        p = p->link;
    }
    C[arg][0] = 0;

    for (int i = 1; i <= CityNum; i++) {
        if (i == dest || V[arg][i]) continue;
        Cptr = CityTable[from];
        p = Cptr->info[arg][i];
        while (p != NULL && p->depart.cmpl(departureTime)) p = p->link;
        while (p != NULL) {
            if (p->price < Cheapest[arg]) {               // �ݹ�ǰ���ж����޵ݹ�ı�Ҫ
                C[arg][0] ++;                                 // ����֮ǰһ��Ҫ·�����ȼ�һ
                C[arg][C[arg][0]] = i;                        // ��ǰ·���Ľڵ���Ϊ i
                V[arg][0] = p->price;                         // �ݹ麯���ĵ�ǰPrice������V[0]λ��
                V[arg][i] = 1;                                // ���������ʽڵ��Visited״̬��Ϊ1
                Cpath[arg][C[arg][0]].Set(p->depart);
                CPath_helper(dest, i, p->depart, arg);
                V[arg][i] = 0;                                // visited���0
                V[arg][0] -= p->price;                        // �ݹ麯��������Ҫ����ǰV[0]�е���ֵ������ԭֵ
                C[arg][C[arg][0]] = 0;                        // ����Ϊ����ǰ��ԭֵ
                C[arg][0] --;                                 // ����
            }
            p = p->link;
        }
    }
}
void Graph::CPath_helper(int dest, int cur, Time& CurTime, int arg) {
    City* Cptr;
    FlightTrain* p;

    if (cur == dest) {
        Cheapest[arg] = V[arg][0];
        R[arg][0] = C[arg][0];
        for (int i = 1; i <= C[arg][0]; ++i) {
            R[arg][i] = C[arg][i]; 
            VPath[arg][i].Set(Cpath[arg][i]);
        }
    }
    else
    {
        for (int i = 1; i <= CityNum; i++) {
            if (V[arg][i]) continue;
            Cptr = CityTable[cur];
            p = Cptr->info[arg][i];
            while (p != NULL && p->depart.cmpl(CurTime)) p = p->link;
            while (p != NULL) {
                if (p->price + V[arg][0] < Cheapest[arg])         // �Ż�
                {
                    C[arg][0] ++;                                 // ����֮ǰһ��Ҫ·�����ȼ�һ
                    C[arg][C[arg][0]] = i;                        // ��ǰ·���Ľڵ���Ϊ i
                    V[arg][0] += p->price;                        // �ݹ麯���ĵ�ǰPrice������V[0]λ��
                    V[arg][i] = 1;                                // ���������ʽڵ��Visited״̬��Ϊ1
                    Cpath[arg][C[arg][0]].Set(p->depart);
                    CPath_helper(dest, i, p->depart, arg);
                    V[arg][i] = 0;                                // visited���0
                    V[arg][0] -= p->price;                        // �ݹ麯��������Ҫ����ǰV[0]�е���ֵ������ԭֵ
                    C[arg][C[arg][0]] = 0;                        // ����Ϊ����ǰ��ԭֵ
                    C[arg][0] --;                                 // ����
                }
                p = p->link;
            }
        }
    }
}

bool Graph::Load(int arg) {
    int num, current = 1;
    std::string strName, str("GRAPH_LOAD");
    std::streambuf* backup;
    std::ifstream fin;
    if (!arg) {
        fin.open("d:/WORK/VSC C/Flight.txt");
    }
    else fin.open("d:/WORK/VSC C/Train.txt");
    backup = std::cin.rdbuf();
    std::cin.rdbuf(fin.rdbuf());                  //���ļ����ض����׼����

    while (true) {
        std::cin >> num; if (num == EOF) break;
        std::cin >> strName;
        if (!str2ID.count(strName)) {
            str2ID[strName] = ++CityNum;
            ID2str[CityNum] = strName;
            if (CityNum > MaxCityNum) {
                overflow(str, CityNum);
            }
            CityTable[CityNum] = new City(strName);
        }
        std::string tempNameA, tempNameB;
        int tempNum[12] = { 0 }; char tempCh[7];
        for (int i = 0; i < num; i++) {
            std::cin >> tempNameA >> tempNameB;

            if (tempNameA != strName)
                input_format(str, tempNameA, str);
            if (!str2ID.count(tempNameB)) {
                str2ID[tempNameB] = ++CityNum;
                ID2str[CityNum] = tempNameB;
                if (CityNum > MaxCityNum) {
                    overflow(str, CityNum);
                }
                CityTable[CityNum] = new City(tempNameB);
            }

            std::cin >> tempNum[0] >> tempCh[0] >> tempNum[1] >> tempCh[1] >> tempNum[2];
            std::cin >> tempNum[3] >> tempCh[2] >> tempNum[4];
            std::cin >> tempNum[6] >> tempCh[3] >> tempNum[7] >> tempCh[4] >> tempNum[8];
            std::cin >> tempNum[9] >> tempCh[5] >> tempNum[10] >> tempNum[11];
            if (tempCh[0] != '/') {                                                     //�������ļ��ϸ�ĸ�ʽ���
                input_format(str, std::string(1, tempCh[0]), std::string(1, '/'));      //��������ַ���Ԥ�ڲ��������ô����������input_format
            }
            if (tempCh[1] != '/') {
                input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
            }
            if (tempCh[2] != ':') {
                input_format(str, std::string(1, tempCh[2]), std::string(1, ':'));
            }
            if (tempCh[3] != '/') {
                input_format(str, std::string(1, tempCh[3]), std::string(1, '/'));
            }
            if (tempCh[4] != '/') {
                input_format(str, std::string(1, tempCh[4]), std::string(1, '/'));
            }
            if (tempCh[5] != ':') {
                input_format(str, std::string(1, tempCh[5]), std::string(1, ':'));
            }
            while (std::cin.get(tempCh[6])) { if (tempCh[6] != ' ') break; }
            if (tempCh[6] != '\n') input_format(str, std::string(1, tempCh[6]), std::string("newline"));

            Time tA(tempNum[0], tempNum[1], tempNum[3], tempNum[4], tempNum[2]);
            Time tB(tempNum[6], tempNum[7], tempNum[9], tempNum[10], tempNum[8]);
            CityTable[str2ID[tempNameA]]->insert(str2ID[tempNameB], tA, tB, tempNum[11], arg);
        }
    }
    std::cin.rdbuf(backup);               //std input redirects from file stream to standard in/out stream.
    return true;
}
bool Graph::Load_file() {
    std::cout << "File loading..." << std::endl;
    Load(0);
    Load(1);
    std::cout << "Loading completed." << std::endl;
    return true;
}
bool Graph::ShowCityInfo(int CityID) {
    int FlightNum, TrainNum;
    FlightNum = CityTable[CityID]->Show_info();
    TrainNum = CityTable[CityID]->Show_info(1);
    std::cout << "�� " << FlightNum << "��������Ϣ�� " << TrainNum << " ���г���Ϣ" << "\n\n\n" << std::endl;
    return true;
}
int Graph::GetCityNum() { return CityNum; }

Graph :: ~Graph() {
    for (int i = 1; i <= CityNum; i++) {
        City* Cptr = CityTable[i];
        delete Cptr;
    }
    ID2str.clear();
    str2ID.clear();
}
bool Graph::Insert() {
    std::string strNameA, strNameB, str("GRAPH_INSERT");
    City* Cptr;
    char tempCh[4];
    int tempNum[6];
    int arg;
    std::cout << "������ʼ������Ӣ�����ƣ���ɶ���ChengDu��:" << std::endl;
    std::cin >> strNameA;
    std::cout << std::endl;
    std::cout << "������Ŀ�����Ӣ������ ��" << std::endl;
    std::cin >> strNameB;
    std::cout << std::endl;
    if (str2ID.count(strNameA) == 0) {
        CityNum++;
        if (CityNum > MaxCityNum) overflow(str, CityNum);
        else {
            str2ID[strNameA] = CityNum;                             //����˳���û�г��ֹ����ͷ������һ�����ص�ID, str2ID�Լ�ID2str������
            ID2str[CityNum] = strNameA;                             //ID�Լ������������໥��ӳ��
            CityTable[CityNum] = new City(strNameA);                //��Graph�й����³���
        }
    }
    if (str2ID.count(strNameB) == 0) {
        CityNum++;
        if (CityNum > MaxCityNum) overflow(str, CityNum);
        else {
            str2ID[strNameB] = CityNum;
            ID2str[CityNum] = strNameB;
            CityTable[CityNum] = new City(strNameB);
        }
    }
    std::cout << "������Ϣ������������0��������Ϊ����Ϣ������1" << std::endl << std::endl;
    std::cin >> arg;
    if (arg != 0 && arg != 1) arg_error(str, arg);
    std::cout << std::endl;
    std::cout << "��������վ���ڣ��� (10/1/2020) ��" << std::endl << std::endl;
    std::cin >> tempNum[1] >> tempCh[1] >> tempNum[2] >> tempCh[2] >> tempNum[3];
    if (tempCh[1] != '/') input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
    if (tempCh[2] != '/') input_format(str, std::string(1, tempCh[2]), std::string(1, '/'));
    std::cout << std:: endl;
    std::cout << "�������ʮ��Сʱ�Ƶ���վʱ�̣� �� ��14:32�� �� " << std::endl << std::endl;
    std::cin >> tempNum[4] >> tempCh[3] >> tempNum[5];
    if (tempCh[3] != ':') input_format(str, std::string(1, tempCh[3]), std::string(1, ':'));
    Time tA(tempNum[1], tempNum[2], tempNum[4], tempNum[5], tempNum[3]);
    std::cout << std::endl;
    std::cout << "�����뵽վ���� �� " << std::endl << std::endl;
    std::cin >> tempNum[1] >> tempCh[1] >> tempNum[2] >> tempCh[2] >> tempNum[3];
    if (tempCh[1] != '/') input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
    if (tempCh[2] != '/') input_format(str, std::string(1, tempCh[2]), std::string(1, '/'));
    std::cout << std::endl;
    std::cout << "�������ʮ��Сʱ�Ƶĵ�վʱ�� �� " << std::endl << std::endl;
    std::cin >> tempNum[4] >> tempCh[3] >> tempNum[5];
    if (tempCh[3] != ':') input_format(str, std::string(1, tempCh[3]), std::string(1, ':'));
    Time tB(tempNum[1], tempNum[2], tempNum[4], tempNum[5], tempNum[3]);

    if (!tA.cmpl(tB)) time_logical_error(str, tA, tB);

    std::cout << std::endl;
    std::cout << "������Ʊ�� : " << std::endl << std::endl;
    std::cin >> tempNum[0];
    std::cout << std::endl;
    
    Cptr = CityTable[str2ID[strNameA]];
    if (Cptr->insert(str2ID[strNameB], tA, tB, tempNum[0], arg)) std::cout << std::endl << "��Ϣ����ɹ�" << std::endl;
    return true;
}

bool Graph::Delete() {
    std::string strNameA, strNameB, str("GRAPH_DELETE");
    City* Cptr;
    char tempCh[4];
    int tempNum[6];
    int arg;
    std::cout << "Ϊɾ����������/����Ϣ��������Ҫ������Ҫ�����������ϸ��Ϣ" << std::endl;
    std::cout << "������ú���ʼ������Ӣ�����ƣ���ɶ���ChengDu��:" << std::endl;
    std::cin >> strNameA;
    std::cout << std::endl;
    std::cout << "������Ŀ�����Ӣ������ ��" << std::endl;
    std::cin >> strNameB;
    std::cout << std::endl;
    if (str2ID.count(strNameA) == 0) {
        throw(strNameA);
    }
    if (str2ID.count(strNameB) == 0) {
        throw(strNameB);
    }
    std::cout << "������Ϣ������������0��������Ϊ����Ϣ������1" << std::endl << std::endl;
    std::cin >> arg;
    if (arg != 0 && arg != 1) arg_error(str, arg);
    std::cout << std::endl;
    std::cout << "��������վ���ڣ��� (10/1/2020) ��" << std::endl << std::endl;
    std::cin >> tempNum[1] >> tempCh[1] >> tempNum[2] >> tempCh[2] >> tempNum[3];
    if (tempCh[1] != '/') input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
    if (tempCh[2] != '/') input_format(str, std::string(1, tempCh[2]), std::string(1, '/'));
    std::cout << std::endl;
    std::cout << "�������ʮ��Сʱ�Ƶ���վʱ�̣� �� ��14:32�� �� " << std::endl << std::endl;
    std::cin >> tempNum[4] >> tempCh[3] >> tempNum[5];
    if (tempCh[3] != ':') input_format(str, std::string(1, tempCh[3]), std::string(1, ':'));
    Time tA(tempNum[1], tempNum[2], tempNum[4], tempNum[5], tempNum[3]);
    std::cout << std::endl;
    std::cout << "�����뵽վ���� �� " << std::endl << std::endl;
    std::cin >> tempNum[1] >> tempCh[1] >> tempNum[2] >> tempCh[2] >> tempNum[3];
    if (tempCh[1] != '/') input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
    if (tempCh[2] != '/') input_format(str, std::string(1, tempCh[2]), std::string(1, '/'));
    std::cout << std::endl;
    std::cout << "�������ʮ��Сʱ�Ƶĵ�վʱ�� �� " << std::endl << std::endl;
    std::cin >> tempNum[4] >> tempCh[3] >> tempNum[5];
    if (tempCh[3] != ':') input_format(str, std::string(1, tempCh[3]), std::string(1, ':'));
    Time tB(tempNum[1], tempNum[2], tempNum[4], tempNum[5], tempNum[3]);

    if (!tA.cmpl(tB)) time_logical_error(str, tA, tB);
    //�û�������/�𳵵���ϸ��Ϣ����󣬳����Ȳ�ѯ�Ƿ������������/����Ϣ����������ķ�����
    //�����������������Ϣ���������ɾ���ɹ���������ɾ��ʧ��
    Cptr = CityTable[str2ID[strNameA]];
    return (Cptr->Delete(str2ID[strNameB], tA, tB, arg));
}

void Graph::ProperPath(int from, int dest, Time &depatureTime, int arg, int tag){
    int cur, nxt;
    City* Cptr; 
    FlightTrain* p;
    if (tag == 0) {
        std::cout << "��Ѱ�����·��..." << std::endl;
        FPath(from, dest, depatureTime, arg);

        if (!R[arg][0]) {                             //�����from��destû����·
            std::cout << "\n\n\n\n�ڸ�ʱ�����Դ˽�ͨ��ʽ���ӳ������е�Ŀ�ĵ�û���κ�һ��������·." << std::endl;
            std::cout << "���޸�Ŀ�ĵس��л���ʱ�������." << " \n\n\n\n " << std::endl;
            return;
        }

        std::cout << "�����·��Ѱ���." << std::endl;
        std::cout << "�����·Ϊ: " << std::endl << std::endl;
        std::cout << "*********************" << std::endl << std::endl;
        if (arg == 1) std::cout << "��·��: " << std::endl;
        else  std::cout << "����·�ߣ�" << std::endl;
        cur = from;
        for (int i = 1; i <= R[arg][0]; i++) {
            nxt = R[arg][i];
            Cptr = CityTable[cur];
            p = Cptr->info[arg][nxt];
            while (!p->arrive.cmpe(VPath[arg][nxt])) p = p->link;
            p->show_info(cur, nxt);
            cur = nxt;
        }
        std::cout << std::endl << "*********************" << std::endl << std::endl << std::endl << std::endl;
    }
    
    if (tag == 1) {
        std::cout << "��Ѱ�������·��..." << std::endl;
        CPath(from, dest, depatureTime, arg);

        if (!R[arg][0]) {                             //�����from��destû����·
            std::cout << "\n\n\n\n�ڸ�ʱ�����Դ˽�ͨ��ʽ���ӳ������е�Ŀ�ĵ�û���κ�һ��������·." << std::endl;
            std::cout << "���޸�Ŀ�ĵس��л���ʱ�������." << " \n\n\n\n " << std::endl;
            return;
        }

        std::cout << "�������·��Ѱ���." << std::endl;
        std::cout << "�������·Ϊ: " << std::endl << std::endl;
        std::cout << "*********************" << std::endl << std::endl;
        if (arg == 0) std::cout << "����·�ߣ�" << std::endl;
        else  std::cout << "��·��: " << std::endl;
        cur = from;
        for (int i = 1; i <= R[arg][0]; ++i) {
            nxt = R[arg][i];
            Cptr = CityTable[cur];
            p = Cptr->info[arg][nxt];
            while (!p->depart.cmpe(VPath[arg][i])) p = p->link;
            p->show_info(cur, nxt);
            cur = nxt;
        }
        std::cout << std::endl << "*********************" << std::endl << std::endl << std::endl << std::endl;
    }
}
int Graph::GetID(std::string& NameStr) {
    return str2ID[NameStr];
}
std::string Graph::GetName(int CityID) {        
    return ID2str[CityID];
}
