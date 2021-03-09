#include "device.h"   //declaration
#include "err_out.h"  //error output
#include "constant.h"



std::map <std::string, int> str2ID;
std::map <int, std::string> ID2str;
/* Time 函数的相关类成员函数的定义 */
Time::Time() {
    year = month = date = hour = min = 0;
}
/* 这个函数定义为私有函数成员，该函数可以越过Time构造函数的时间格式审查 */
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
bool Time::cmpg(Time& t)const {          //判断时间是否更大
    if (year > t.year) return true;
    else if (year == t.year && month > t.month) return true;
    else if (year == t.year && month == t.month && date > t.date) return true;
    else if (year == t.year && month == t.month && date == t.date && hour > t.hour) return true;
    else if (year == t.year && month == t.month && date == t.date && hour == t.hour && min > t.min) return true;
    else return false;
}

bool Time::cmpl(Time& t)const {          //判断时间是否更小
    if (year < t.year) return true;
    else if (year == t.year && month < t.month) return true;
    else if (year == t.year && month == t.month && date < t.date) return true;
    else if (year == t.year && month == t.month && date == t.date && hour < t.hour) return true;
    else if (year == t.year && month == t.month && date == t.date && hour == t.hour && min < t.min) return true;
    else return false;
}

bool Time::cmpe(Time& t)const {          //判断时间是否相同
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
    if (!flag) { std::cout << "信息删除失败，未找到这条信息"; return false; }
    else { std::cout << "信息删除成功."; return true; }
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
        arg_error(str, arg);                                    //如果参数不正确，调用错误输出函数arg_error
    }
    int count = 0;
    std::cout << "********************************************" << std::endl << std::endl;
    std::cout << cityName;
    if (!arg) std::cout << " 航班信息：" << std::endl << std::endl;
    else std::cout << " 列车信息： " << std::endl << std::endl;
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
        v[cur_least] = 1;                                                          //将找到的节点作为已经访问的节点

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
// 对于寻找最便宜路径，不能简单使用迪杰斯特拉算法，因为我们必须将航班/火车发车与到站时间作为另一个因素综合考虑
// 因此对于CPath的寻找，我们采用了递归函数调用的方法遍历各种可能的路径，并且对递归函数进行了优化
// 使其拥有了好得多的性能（这个改动排除了众多不可能的路径）
void Graph::CPath(int from, int dest, Time departureTime, int arg) {
    Cheapest[arg] = LargePrice;
    City* Cptr = CityTable[from];
    FlightTrain* p = Cptr->info[arg][dest];

    memset(V[arg], 0, sizeof(V[arg]));  V[arg][from] = 1;
    memset(C[arg], 0, sizeof(C[arg]));                         // 当前递归路径长度储存在C[0]位置，C[1]及以后中储存路径节点城市ID                     
    while (p != NULL) {
        if (p -> price < Cheapest[arg]) {
            Cheapest[arg] = p->price;
            R[arg][0] = 1;                                     // 当前递归函数最佳路径长度储存在R[0]位置
            R[arg][1] = dest;                                  // R[1]及以后储存最佳路径途经城市ID
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
            if (p->price < Cheapest[arg]) {               // 递归前先判断有无递归的必要
                C[arg][0] ++;                                 // 调用之前一定要路径长度加一
                C[arg][C[arg][0]] = i;                        // 当前路径的节点设为 i
                V[arg][0] = p->price;                         // 递归函数的当前Price储存在V[0]位置
                V[arg][i] = 1;                                // 将即将访问节点的Visited状态设为1
                Cpath[arg][C[arg][0]].Set(p->depart);
                CPath_helper(dest, i, p->depart, arg);
                V[arg][i] = 0;                                // visited设回0
                V[arg][0] -= p->price;                        // 递归函数调用完要将当前V[0]中的数值减回至原值
                C[arg][C[arg][0]] = 0;                        // 设置为调用前的原值
                C[arg][0] --;                                 // 减回
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
                if (p->price + V[arg][0] < Cheapest[arg])         // 优化
                {
                    C[arg][0] ++;                                 // 调用之前一定要路径长度加一
                    C[arg][C[arg][0]] = i;                        // 当前路径的节点设为 i
                    V[arg][0] += p->price;                        // 递归函数的当前Price储存在V[0]位置
                    V[arg][i] = 1;                                // 将即将访问节点的Visited状态设为1
                    Cpath[arg][C[arg][0]].Set(p->depart);
                    CPath_helper(dest, i, p->depart, arg);
                    V[arg][i] = 0;                                // visited设回0
                    V[arg][0] -= p->price;                        // 递归函数调用完要将当前V[0]中的数值减回至原值
                    C[arg][C[arg][0]] = 0;                        // 设置为调用前的原值
                    C[arg][0] --;                                 // 减回
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
    std::cin.rdbuf(fin.rdbuf());                  //用文件流重定向标准输入

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
            if (tempCh[0] != '/') {                                                     //对输入文件严格的格式检查
                input_format(str, std::string(1, tempCh[0]), std::string(1, '/'));      //如果输入字符与预期不符，调用错误输出函数input_format
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
    std::cout << "共 " << FlightNum << "条航班信息， " << TrainNum << " 条列车信息" << "\n\n\n" << std::endl;
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
    std::cout << "请输入始发城市英文名称，如成都（ChengDu）:" << std::endl;
    std::cin >> strNameA;
    std::cout << std::endl;
    std::cout << "请输入目标城市英文名称 ：" << std::endl;
    std::cin >> strNameB;
    std::cout << std::endl;
    if (str2ID.count(strNameA) == 0) {
        CityNum++;
        if (CityNum > MaxCityNum) overflow(str, CityNum);
        else {
            str2ID[strNameA] = CityNum;                             //如果此城市没有出现过，就分配给它一个独特的ID, str2ID以及ID2str储存着
            ID2str[CityNum] = strNameA;                             //ID以及城市名二者相互的映射
            CityTable[CityNum] = new City(strNameA);                //在Graph中构造新城市
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
    std::cout << "航班信息，请输入数字0，否则若为火车信息，输入1" << std::endl << std::endl;
    std::cin >> arg;
    if (arg != 0 && arg != 1) arg_error(str, arg);
    std::cout << std::endl;
    std::cout << "请输入离站日期，如 (10/1/2020) ：" << std::endl << std::endl;
    std::cin >> tempNum[1] >> tempCh[1] >> tempNum[2] >> tempCh[2] >> tempNum[3];
    if (tempCh[1] != '/') input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
    if (tempCh[2] != '/') input_format(str, std::string(1, tempCh[2]), std::string(1, '/'));
    std::cout << std:: endl;
    std::cout << "请输入二十四小时制的离站时刻， 如 （14:32） ： " << std::endl << std::endl;
    std::cin >> tempNum[4] >> tempCh[3] >> tempNum[5];
    if (tempCh[3] != ':') input_format(str, std::string(1, tempCh[3]), std::string(1, ':'));
    Time tA(tempNum[1], tempNum[2], tempNum[4], tempNum[5], tempNum[3]);
    std::cout << std::endl;
    std::cout << "请输入到站日期 ： " << std::endl << std::endl;
    std::cin >> tempNum[1] >> tempCh[1] >> tempNum[2] >> tempCh[2] >> tempNum[3];
    if (tempCh[1] != '/') input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
    if (tempCh[2] != '/') input_format(str, std::string(1, tempCh[2]), std::string(1, '/'));
    std::cout << std::endl;
    std::cout << "请输入二十四小时制的到站时刻 ： " << std::endl << std::endl;
    std::cin >> tempNum[4] >> tempCh[3] >> tempNum[5];
    if (tempCh[3] != ':') input_format(str, std::string(1, tempCh[3]), std::string(1, ':'));
    Time tB(tempNum[1], tempNum[2], tempNum[4], tempNum[5], tempNum[3]);

    if (!tA.cmpl(tB)) time_logical_error(str, tA, tB);

    std::cout << std::endl;
    std::cout << "请输入票价 : " << std::endl << std::endl;
    std::cin >> tempNum[0];
    std::cout << std::endl;
    
    Cptr = CityTable[str2ID[strNameA]];
    if (Cptr->insert(str2ID[strNameB], tA, tB, tempNum[0], arg)) std::cout << std::endl << "信息插入成功" << std::endl;
    return true;
}

bool Graph::Delete() {
    std::string strNameA, strNameB, str("GRAPH_DELETE");
    City* Cptr;
    char tempCh[4];
    int tempNum[6];
    int arg;
    std::cout << "为删除该条航班/火车信息，我们需要您按照要求输入相关详细信息" << std::endl;
    std::cout << "请输入该航班始发城市英文名称，如成都（ChengDu）:" << std::endl;
    std::cin >> strNameA;
    std::cout << std::endl;
    std::cout << "请输入目标城市英文名称 ：" << std::endl;
    std::cin >> strNameB;
    std::cout << std::endl;
    if (str2ID.count(strNameA) == 0) {
        throw(strNameA);
    }
    if (str2ID.count(strNameB) == 0) {
        throw(strNameB);
    }
    std::cout << "航班信息，请输入数字0，否则若为火车信息，输入1" << std::endl << std::endl;
    std::cin >> arg;
    if (arg != 0 && arg != 1) arg_error(str, arg);
    std::cout << std::endl;
    std::cout << "请输入离站日期，如 (10/1/2020) ：" << std::endl << std::endl;
    std::cin >> tempNum[1] >> tempCh[1] >> tempNum[2] >> tempCh[2] >> tempNum[3];
    if (tempCh[1] != '/') input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
    if (tempCh[2] != '/') input_format(str, std::string(1, tempCh[2]), std::string(1, '/'));
    std::cout << std::endl;
    std::cout << "请输入二十四小时制的离站时刻， 如 （14:32） ： " << std::endl << std::endl;
    std::cin >> tempNum[4] >> tempCh[3] >> tempNum[5];
    if (tempCh[3] != ':') input_format(str, std::string(1, tempCh[3]), std::string(1, ':'));
    Time tA(tempNum[1], tempNum[2], tempNum[4], tempNum[5], tempNum[3]);
    std::cout << std::endl;
    std::cout << "请输入到站日期 ： " << std::endl << std::endl;
    std::cin >> tempNum[1] >> tempCh[1] >> tempNum[2] >> tempCh[2] >> tempNum[3];
    if (tempCh[1] != '/') input_format(str, std::string(1, tempCh[1]), std::string(1, '/'));
    if (tempCh[2] != '/') input_format(str, std::string(1, tempCh[2]), std::string(1, '/'));
    std::cout << std::endl;
    std::cout << "请输入二十四小时制的到站时刻 ： " << std::endl << std::endl;
    std::cin >> tempNum[4] >> tempCh[3] >> tempNum[5];
    if (tempCh[3] != ':') input_format(str, std::string(1, tempCh[3]), std::string(1, ':'));
    Time tB(tempNum[1], tempNum[2], tempNum[4], tempNum[5], tempNum[3]);

    if (!tA.cmpl(tB)) time_logical_error(str, tA, tB);
    //用户将航班/火车的详细信息输入后，程序先查询是否存在这条航班/火车信息，再输出最后的反馈：
    //如果存在这条航班信息，就输出“删除成功”，否则删除失败
    Cptr = CityTable[str2ID[strNameA]];
    return (Cptr->Delete(str2ID[strNameB], tA, tB, arg));
}

void Graph::ProperPath(int from, int dest, Time &depatureTime, int arg, int tag){
    int cur, nxt;
    City* Cptr; 
    FlightTrain* p;
    if (tag == 0) {
        std::cout << "搜寻最快线路中..." << std::endl;
        FPath(from, dest, depatureTime, arg);

        if (!R[arg][0]) {                             //如果从from到dest没有线路
            std::cout << "\n\n\n\n在该时间点后，以此交通方式，从出发城市到目的地没有任何一条可行线路." << std::endl;
            std::cout << "请修改目的地城市或者时间后重试." << " \n\n\n\n " << std::endl;
            return;
        }

        std::cout << "最快线路搜寻完毕." << std::endl;
        std::cout << "最快线路为: " << std::endl << std::endl;
        std::cout << "*********************" << std::endl << std::endl;
        if (arg == 1) std::cout << "火车路线: " << std::endl;
        else  std::cout << "航班路线：" << std::endl;
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
        std::cout << "搜寻最便宜线路中..." << std::endl;
        CPath(from, dest, depatureTime, arg);

        if (!R[arg][0]) {                             //如果从from到dest没有线路
            std::cout << "\n\n\n\n在该时间点后，以此交通方式，从出发城市到目的地没有任何一条可行线路." << std::endl;
            std::cout << "请修改目的地城市或者时间后重试." << " \n\n\n\n " << std::endl;
            return;
        }

        std::cout << "最便宜线路搜寻完毕." << std::endl;
        std::cout << "最便宜线路为: " << std::endl << std::endl;
        std::cout << "*********************" << std::endl << std::endl;
        if (arg == 0) std::cout << "航班路线：" << std::endl;
        else  std::cout << "火车路线: " << std::endl;
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
