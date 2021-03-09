#include<iostream>

using namespace std;

struct Team{
    int year;
    int score;
    int id;
};

void select(Team* all, int y, int years, int num){
    int i = 0, best = 0, maxscore = 0;
    //for(i = 0; i < num; i++){cout << all[i].id<< '\t'<< all[i].score << '\t' << all[i].year << endl;}
    for (i = 0; i < num; i++){
        if( all[i].year <= y && (all[i].year + years - 1) >= y ){
            if (all[i].score >= maxscore) {maxscore = all[i].score; best = i;}   //有漏句
        }
    }
    cout << all[best].id << endl;     //有问题
}

int main(){
    int num = 0, years = 0, start = 0, end = 0, i = 0, y = 0;
    cin >> num >> years >> start >> end;
    Team* all;
    all = new Team[num];

    for ( i = 0; i < num; i++ ){
        cin >> all[i].year >> all[i].score >> all[i].id;}
    for ( y = start; y <= end; y++){
        select(all, y, years, num);}
    delete all;
    system("pause");
    return 0;
}
