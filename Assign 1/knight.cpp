#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
bool songuyento(int x){
    if(x < 2){
        return 0;
    }
    for(int h = 2; h <= sqrt(x); h++){
        if(x % h == 0){
            return 0;
        }
    }
    return 1;
}
int sofibogannhat(int n) {
    int f1 = 1;
    int f2 = 1;
    int f3 = f1 + f2;
    while (f3 < n) {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return f2;
}
bool checkmerlin(string s) {
for(int i=0;i<s.length();i++){
    s[i]=tolower(s[i]);
}
size_t s1=s.find("m");
size_t s2=s.find("e");
size_t s3=s.find("r");
size_t s4=s.find("l");
size_t s5=s.find("i");
size_t s6=s.find("n");
if (s1<s.length()&&s2<s.length()&&s3<s.length()&&s4<s.length()&&s5<s.length()&&s6<s.length()){
    return 1;
} else return 0;
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
ifstream file(file_input);
    string line1, line2, line3;
    getline(file, line1);
    stringstream ss1(line1);
    ss1 >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    getline(file, line2);
    stringstream ss2(line2);
    getline(file, line3);
    stringstream ss3(line3);
    string file_mush_ghost, file_asclepius_pack, file_merlin_pack;
    getline(ss3, file_mush_ghost, ',');
    getline(ss3, file_asclepius_pack, ',');
    getline(ss3, file_merlin_pack);
file.close();
    string sukien;
    int songuyensukien;
    int r=1,b,levelO=1;
    int MaxHP=HP;
    bool Arthur=0,Lancelot=0,tihon=0,ech=0;
    bool alreadyreceivemerlin=0,alreadyreceiveaclepius=0;
    float baseDamage,damage;
    int tihoncountdown=0,echcountdown=0;
    int previouslevel;
    string sukien13;
if (HP==999){
    Arthur=1;
}
if(songuyento(HP)==1){
    Lancelot=1;
}
while (ss2 >> sukien) {
if(tihoncountdown>0){
tihoncountdown--;}
if(echcountdown>0){
echcountdown--;}
    songuyensukien=stoi(sukien);
    sukien13=sukien.substr(0,2);
    if(rescue==-1){display(HP,level,remedy,maidenkiss,phoenixdown,rescue);}
    switch(songuyensukien){
    case 0:{
        rescue=1;
        break;
    }
    case 1:{
        b=r%10;
    levelO=r>6?(b>5?b:5):b;
    baseDamage=1;
    if(Lancelot==1 || Arthur==1){
        level+=1;
        goto loop1;
    }
    if (level>levelO){
    level++;
    }
    if (level<levelO){
    damage=baseDamage*levelO*10;
    HP=HP-damage;
    }
    if (level==levelO){
        goto loop1;
    }
    loop1:;
    rescue=-1;
    break;
}
case 2:{
    b=r%10;
    levelO=r>6?(b>5?b:5):b;
    baseDamage=1.5;
    if(Lancelot==1 || Arthur==1){
        level+=1;
        goto loop2;
    }
    if (level>levelO){
    level++;
    }
    if (level<levelO){
    damage=baseDamage*levelO*10;
    HP=HP-damage;
    }
    if (level==levelO){
        goto loop2;
    }
    loop2:;
    rescue=-1;
    break;
}
case 3:{
    b=r%10;
    levelO=r>6?(b>5?b:5):b;
    baseDamage=4.5;
    if(Lancelot==1 || Arthur==1){
        level+=1;
        goto loop3;
    }
    if (level>levelO){
    level++;
    }
    if (level<levelO){
    damage=baseDamage*levelO*10;
    HP=HP-damage;
    }
    if (level==levelO){
        goto loop3;
    }
    loop3:;
    rescue=-1;
    break;
}
case 4:{
    b=r%10;
    levelO=r>6?(b>5?b:5):b;
    baseDamage=7.5;
    if(Lancelot==1 || Arthur==1){
        level+=1;
        goto loop4;
    }
    if (level>levelO){
    level++;
    }
    if (level<levelO){
    damage=baseDamage*levelO*10;
    HP=HP-damage;
    }
    if (level==levelO){
        goto loop4;
    }
    loop4:;
    rescue=-1;
    break;
}
case 5:{
    b=r%10;
    levelO=r>6?(b>5?b:5):b;
    baseDamage=9.5;
    if(Lancelot==1 || Arthur==1){
        level+=1;
        goto loop5;
    }
    if (level>levelO){
    level++;
    }
    if (level<levelO){
    damage=baseDamage*levelO*10;
    HP=HP-damage;
    }
    if (level==levelO){
        goto loop5;
    }
    loop5:;
    rescue=-1;
    break;
}
case 6:{
     if (tihon==1 || ech==1){
    goto loop6;
}
    b=r%10;
    levelO=r>6?(b>5?b:5):b;
    if(Lancelot==1 || Arthur==1){
        level+=2;
        goto loop6;
    }
    if (level>levelO && level<10){
    level+=2;
    }
    if (level==levelO){
        goto loop6;
    }
    if (level<levelO){
    if(remedy==0){
    tihon=1;
    tihoncountdown=3;
        if(HP<5){
        HP=1;
    }else
    HP=HP/5;
    } else if (remedy>0){remedy--;}
    } 
    loop6:;
    rescue=-1;
    break;
}
case 7:{
    if (tihon==1 || ech==1){
    goto loop7;
}
    b=r%10;
    levelO=r>6?(b>5?b:5):b;
    if(Lancelot==1 || Arthur==1){
        level+=2;
        goto loop7;
    }
    if (level>levelO && level<10){
    level+=2;
    }
    if (level==levelO){
        goto loop7;
    }
    if (level<levelO){
    ech=1;
    echcountdown=3;
    previouslevel=level;
    level=1;
    } 
    loop7:;
    rescue=-1;
    break;
}
case 11:{
    int n1=((level+phoenixdown)%5+1)*3;
    int songuyenle=99;
    int s1=songuyenle;
    for (int k=1; k<n1;k++){
        songuyenle-=2;
        s1+=songuyenle;
    }
    HP=HP+(s1%100);
     while (!songuyento(HP)|| songuyento(HP)) {
                HP++;
                if(songuyento(HP)){
                    break;
                }
            }
    if (HP>MaxHP){
        HP=MaxHP;
    }
    rescue=-1;
    break;
}
case 12:{
    if(HP>1){
        HP=sofibogannhat(HP);
    }
    rescue=-1;
    break;
}
case 15:{
    if (remedy<99){
    remedy++;
    } 
    rescue=-1;
    break;
}
case 16:{
    if (maidenkiss<99){
    maidenkiss++;
    }
    rescue=-1;
    break;
}
case 17:{
    if (phoenixdown<99){
    phoenixdown++;
    } 
    rescue=-1;
    break;
}
case 18:{
    if(alreadyreceivemerlin==0){
    alreadyreceivemerlin=1;
    ifstream trangbi(file_merlin_pack);
    int n;
    trangbi >> n;
    int HPphuphep=2;
    for (int i = 0; i < n; i++) {
        string tentrangbi;
        trangbi >> tentrangbi;
        if (checkmerlin(tentrangbi)) {
            if (tentrangbi.find("Merlin") != std::string::npos || tentrangbi.find("merlin") != std::string::npos) {
                HPphuphep = 3;
            }
            HP+=HPphuphep;
            HPphuphep = 2;
        }
    }
    trangbi.close();
    rescue=-1;
}
break;
}
case 19:{
if(alreadyreceiveaclepius==0){
    alreadyreceiveaclepius=1;
    ifstream thuoc(file_asclepius_pack);
    int r1, c1;
    thuoc >> r1 >> c1;
    int potions[r1][c1];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            thuoc >> potions[i][j];
        }
    }
    thuoc.close();
     for (int i = 0; i < r1; i++) {
        int limit = 1;
        for (int j = 0; j < c1; j++) {
            if(potions[i][j] == 16){
                remedy++;
                limit++;
            }else
            if(potions[i][j] == 17){
                maidenkiss++;
                limit++;
            }else
            if(potions[i][j] == 18){
                phoenixdown++;
                limit++;
            }
            if (limit > 3) {
                break;
            }
        }
        }
    if (remedy>99){remedy=99;}
    if (maidenkiss>99){maidenkiss=99;}
    if (phoenixdown>99){phoenixdown=99;}
    rescue=-1;
}
break;
}
case 99:{
if(Lancelot==1 && level>=8||Arthur==1 || level==10){
level=10;
rescue=-1;
} else rescue=0;
break;
}
default:{
    if (sukien13=="13"){
    string ms;
    for(int k=2;k<sukien.length();k++){
    ms=sukien.substr(k,1);
    int maxi,mini,mtx,mti,maxi2,mini2,max2_3x,max2_3i;
    ifstream nam(file_mush_ghost);
    int n2;
    nam>>n2;
    int arr[n2];   
        for (int i = 0; i < n2; i++) {
            char c;
            nam >> arr[i];
            if (i < n2 - 1) {
                nam >> c;
            }
        }
    if(ms=="1"){
    maxi = 0;
    mini = 0;
    for (int i = 1; i < n2; i++) {
        if (arr[i] >= arr[maxi]) {
            maxi = i;
        }
        if (arr[i] <= arr[mini]) {
            mini = i;
        }
    }
        HP=HP-(maxi+mini);
        if (HP<=0 && phoenixdown>=1){
    phoenixdown--;
    HP=MaxHP;
    rescue=-1;
} else if (HP<=0 && phoenixdown<1){
    rescue=0;
    break;
}
if(HP>MaxHP){
        HP=MaxHP;
    }
        rescue=-1;
    }
    else if(ms=="2"){
mtx=-2; mti=-3;
    for (int i = 1; i < n2; i++) {
        if (arr[i] > arr[i-1]) {
            mtx=arr[i];
            mti=i;
            continue;
        }
        if (i+1==n2){
            break;}
        if (arr[i] <= arr[i-1]){
            mtx=-2; mti=-3;
            break;
        }
    }
        for (int i = 1; i < n2; i++) {
        if (arr[i] < arr[i-1]) {
        mtx=arr[0];
        mti=0;
            continue;
        }
        if (i+1==n2){
            break;}
         if (arr[i] >= arr[i-1] && mtx!=arr[n2-1]&& mti!=n2-1){
            mtx=-2; mti=-3;
            break;
        }
    }
    for (int i = 1; i < n2; i++) {
        if (arr[i] > arr[i-1]) {
            continue;
        } if (arr[i] < arr[i-1]) {
            mtx = arr[i-1]; 
            mti = i-1;
            for (int k=i+1;k<n2;k++){
                if (arr[k] > arr[k-1]){
                 mtx=-2; 
                 mti=-3; 
                 break;
                }
        }break;
    }
    }
    if (n2==1){mtx=arr[0];mti=0;}
    HP=HP-(mtx+mti);
    if (HP<=0 && phoenixdown>=1){
    phoenixdown--;
    HP=MaxHP;
    rescue=-1;
} else if (HP<=0 && phoenixdown<1){
    rescue=0;
    break;
}
if(HP>MaxHP){
        HP=MaxHP;
    }
    
rescue=-1;
}
    else if (ms=="3"){
    maxi2=0;
    mini2=0;
    for (int i = 0; i <n2 ; i++) {
    if (arr[i]<0){
        arr[i]=-arr[i];} 
        arr[i]=(17*arr[i]+9)%257;}
for (int i = 1; i <n2 ; i++) {
if (arr[i] > arr[maxi2]) {
            maxi2 = i;
        }
        if (arr[i] < arr[mini2]) {
            mini2 = i;
        }
}
HP=HP-(maxi2+mini2);
if (HP<=0 && phoenixdown>=1){
    phoenixdown--;
    HP=MaxHP;
    rescue=-1;
} else if (HP<=0 && phoenixdown<1){
    rescue=0;
    break;
}
if(HP>MaxHP){
        HP=MaxHP;
    }
rescue=-1;
}
else if (ms=="4"){
for (int i = 0; i <n2 ; i++) {
    if (arr[i]<0){
        arr[i]=-arr[i];} 
        arr[i]=(17*arr[i]+9)%257;}
    max2_3i=0;
    max2_3x = arr[0];
    int minest=arr[0];
     for (int i = 1; i <3 ; i++) {
        if (arr[i] > arr[max2_3i]) {
            max2_3i = i;
            max2_3x = arr[i];
        }
     }
        for (int i = 1; i <3 ; i++) {
        if (arr[i] < minest) {
            minest=arr[i];
        }
        }
for (int i=0;i<3;i++){
           if (arr[i]>minest && arr[i]<max2_3x){
              max2_3i=i;
              max2_3x=arr[i];
           }    
       }
if(arr[0]==arr[1] && arr[1]==arr[2]){
    max2_3x=-5;
    max2_3i=-7;
}
if(arr[0]==arr[1] || arr[1]==arr[2] || arr[0]==arr[2])
{
    max2_3i=0;
    max2_3x = arr[0];
    for (int i = 1; i <3 ; i++) {
        if (arr[i] < arr[max2_3i]) {
            max2_3i = i;
            max2_3x = arr[i];
        }
     }
}
if (n2<3){
    max2_3x=-5;
    max2_3i=-7;
}
HP=HP-(max2_3x+max2_3i);
if (HP<=0 && phoenixdown>=1){
    phoenixdown--;
    HP=MaxHP;
    rescue=-1;
} else if (HP<=0 && phoenixdown<1){
    rescue=0;
    break;
}
if(HP>MaxHP){
        HP=MaxHP;
    }
rescue=-1;
}
if(HP>MaxHP){
        HP=MaxHP;
    }
    rescue=-1;
    }
}
break;
}
    }
if(level>10){
        level=10;}
if(HP>MaxHP){
        HP=MaxHP;}
if (HP<=0 && phoenixdown==0){
    rescue=0;
}
if (HP<=0 && phoenixdown>=1){
    phoenixdown--;
    HP=MaxHP;
    rescue=-1;
}
 if (HP<=0 && tihon==1 && phoenixdown>=1 ){
        phoenixdown--;
        tihon=0;
        tihoncountdown=0;
        HP=MaxHP;
    }
if (maidenkiss>=1 && ech==1){
        maidenkiss--;
        ech=0;
        echcountdown=0;
        level=previouslevel;
    }
if (remedy>=1 && tihon==1){
        remedy--;
        tihon=0;
        tihoncountdown=0;
        HP*=5;
    if(HP>MaxHP){
        HP=MaxHP;
    }
    }
if(rescue==1){
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        break;
        }
    if(rescue==0){
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        break;
        }
r++;
        if(ech==1 && echcountdown==0){
ech=0;
level=previouslevel;
}
if(tihon==1 && tihoncountdown==0){
    tihon=0;
    HP*=5;
    if(HP>MaxHP){
        HP=MaxHP;
    }
}
}
if(rescue==-1){
rescue=1;
display(HP,level,remedy,maidenkiss,phoenixdown,rescue);}
}




