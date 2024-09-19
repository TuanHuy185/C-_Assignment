#include "knight2.h"
/* * * BEGIN implementation of class BaseOpponent * * */
bool BaseOpponent::WinOmegaWeapon = false;
bool BaseOpponent::WinHades = false;
BaseOpponent* BaseOpponent::create(int i, OpponentType TypeOpponent){
BaseOpponent* opponent;
if(TypeOpponent==MadBear) opponent = new MadBearOpponent(i);
else if(TypeOpponent==Bandit) opponent = new BanditOpponent(i);
else if(TypeOpponent==LordLupin) opponent = new LordLupinOpponent(i);
else if(TypeOpponent==Elf) opponent = new ElfOpponent(i);
else if(TypeOpponent==Troll) opponent = new TrollOpponent(i);
else if(TypeOpponent==Tornbery) opponent = new TornberyOpponent(i);
else if(TypeOpponent==QueenOfCards) opponent = new QueenOfCardsOpponent(i);
else if(TypeOpponent==NinaDeRings) opponent = new NinaDeRingsOpponent(i);
else if(TypeOpponent==DurianGarden) opponent = new DurianOpponent(i);
else if(TypeOpponent==OmegaWeapon) opponent = new OmegaWeaponOpponent(i);
else if(TypeOpponent==Hades) opponent = new HadesOpponent(i);
else return nullptr;
    return opponent;
}
void MadBearOpponent::fight(BaseKnight* knight){
    int levelO=(this->i+this->getType())%10+1;
    if(knight->getLevel()<levelO && knight->getType()!=PALADIN && knight->getType()!=LANCELOT){ 
        knight->setHp(knight->getHp()-10*(levelO-knight->getLevel())); 
    }
    else this->receiveGil(knight);
}
void BanditOpponent::fight(BaseKnight* knight){
    int levelO=(this->i+this->getType())%10+1;
    if(knight->getLevel()<levelO && knight->getType()!=PALADIN && knight->getType()!=LANCELOT){ 
        knight->setHp(knight->getHp()-15*(levelO-knight->getLevel())); 
    }
    else this->receiveGil(knight);
}
void LordLupinOpponent::fight(BaseKnight* knight){
    int levelO=(this->i+this->getType())%10+1;
    if(knight->getLevel()<levelO && knight->getType()!=PALADIN && knight->getType()!=LANCELOT){  
        knight->setHp(knight->getHp()-45*(levelO-knight->getLevel())); 
    }
    else this->receiveGil(knight);
}
void ElfOpponent::fight(BaseKnight* knight){
    int levelO=(this->i+this->getType())%10+1;
    if(knight->getLevel()<levelO && knight->getType()!=PALADIN && knight->getType()!=LANCELOT){ 
        knight->setHp(knight->getHp()-75*(levelO-knight->getLevel())); 
    }
    else this->receiveGil(knight);
}
void TrollOpponent::fight(BaseKnight* knight){
    int levelO=(this->i+this->getType())%10+1;
    if(knight->getLevel()<levelO && knight->getType()!=PALADIN && knight->getType()!=LANCELOT){  
        knight->setHp(knight->getHp()-95*(levelO-knight->getLevel())); 
    }
    else this->receiveGil(knight);
}
void TornberyOpponent::fight(BaseKnight* knight){
    int levelO=(this->i+this->getType())%10+1;
    if(knight->getLevel()<levelO && knight->getType() !=DRAGON) knight->setPoison(true);
    else if(knight->getLevel()>=levelO && knight->getLevel()<10){knight->setLevel(knight->getLevel() + 1);}
       if(knight->getPoison() == true){
        knight->getBag()->get(Antidote);
       if(knight->getPoison() == false){}
        else {
            knight->getBag()->remove();
            knight->setHp(knight->getHp()-10);
            knight->setPoison(false);
        }
    }
}
void QueenOfCardsOpponent::fight(BaseKnight* knight){
    int levelO=(this->i+this->getType())%10+1;
    if(knight->getLevel()>=levelO) this->receiveGil(knight);
    else if(knight->getType()!= PALADIN) knight->setGil(knight->getGil()/2);
}
void NinaDeRingsOpponent::fight(BaseKnight* knight){
    if(knight->getType()==PALADIN || knight->getGil()>=50){ 
        if(knight->getHp()<knight->getMaxHp()/3){
        this->receiveGil(knight);
        knight->setHp(knight->getHp()+knight->getMaxHp()/5);
        } 
    }
}
void DurianOpponent::fight(BaseKnight* knight){
     knight->setHp(knight->getMaxHp());
}
void OmegaWeaponOpponent::fight(BaseKnight* knight){
    if(BaseOpponent::WinOmegaWeapon) return;
    else if(knight->getType()==DRAGON || (knight->getLevel()==10 && knight->getHp()==knight->getMaxHp())){ 
        this->receiveGil(knight);
        knight->setLevel(10);
        BaseOpponent::WinOmegaWeapon=true;
    }
    else knight->setHp(0); 
}
void HadesOpponent::fight(BaseKnight* knight){
    if(BaseOpponent::WinHades) return;
    else if(knight->getLevel() == 10 || (knight->getType()==PALADIN && knight->getLevel()>=8)){
        BaseOpponent::WinHades = true;
    }
    else knight->setHp(0);
}
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class BaseBag * * */
BaseBag::BaseBag(BaseKnight* knight){
this->size=0;
this->maxsize=0;
this->knight=knight;
this->head=nullptr;
}
void BaseBag::upHP(){
    if(head==nullptr) return;
    if(head->canUse(knight)){
        head->use(knight);
        BaseItem* x=head;
        head=head->next;
        this->size--;
        delete x;
        return;
    } 
    if(this->size>=2 && head->next->canUse(knight)){
        head->next->use(knight);
        BaseItem* x=head->next;
        head->next=x->next;
        this->size--;
        delete x;
        return;
    }
    if(this->size>=3){
        BaseItem* x=head;
        while(x->next->canUse(knight)==false){
            x=x->next;
            if(x->next==nullptr) return;
        }
        BaseItem* y=x->next;
        BaseItem* z=head->next;
        x->next=head;
        head->next=y->next;
        head=z;
        y->use(knight);
        this->size--;
        delete y;
        return;
    }
    return;
}
BaseItem* BaseBag::get(ItemType itemType){
    if(head==nullptr) return nullptr;
    if(head->getName()==itemType){
        head->use(knight);
        BaseItem* x=head;
        head=head->next;
        this->size--;
        delete x;
        return nullptr;
    } 
    if(this->size>=2 && head->next->getName()==itemType){
        head->next->use(knight);
        BaseItem* x=head->next;
        head->next=x->next;
        this->size--;
        delete x;
        return nullptr;
    }
    if(this->size>=3){
        BaseItem* x=head;
        while(x->next->getName()!=itemType){
            x=x->next;
            if(x->next==nullptr) return nullptr;
        }
        BaseItem* y=x->next;
        BaseItem* z=head->next;
        x->next=head;
        head->next=y->next;
        head=z;
        y->use(knight);
        this->size--;
        delete y;
        return nullptr;
    }
    return nullptr;
}
void BaseBag::remove(){
    int i=0;
    while(i<3 && head!=nullptr){
        BaseItem* x = head;
        head=head->next;
        delete x;
        this->size--;
        i++;
    }
}
BaseBag::~BaseBag(){
    for(int i=0;i<this->size;i++){
        BaseItem* x=head;
        head=head->next;
        delete x;
    }
}
bool BaseBag::insertFirst(BaseItem* item){
    if(this->size<this->maxsize || this->knight->getType()==PALADIN){
        this->size++;
        item->next=head;
        head=item;
        return 1;
    }
    return 0;
}
string BaseBag::toString() const{
    if(this->size==0){
        return "Bag[count=0;]";
    }
    else{
        string stringBag="Bag[count=" + to_string(this->size) + ";";
        BaseItem* item=head;
        while (item){
            stringBag+=item->name()+",";
            item=item->next;
        }
       stringBag.pop_back();
       stringBag+=']';
       return stringBag; 
    }
}

PaladinBag::PaladinBag(BaseKnight* knight,int antidote,int phoenix): BaseBag(knight){
    this->maxsize=-1;
    int i = 0;
    while(i<5 && phoenix){
        this->insertFirst(new PhoenixdownIItem());
        i++; phoenix--;
    } 
    i = 0;
     while(i<5 && antidote){
        this->insertFirst(new AntidoteItem());
        i++; antidote--;
    }
}
bool PaladinBag::insertFirst(BaseItem * item){
    if(head == nullptr){
        head = item;
        this->size++;
        return true;
    }
    item ->next = this->head;
    head = item;
    this->size++;
    return true;
}
// -----
LancelotBag::LancelotBag(BaseKnight* knight,int antidote,int phoenix):BaseBag(knight){
    this->maxsize = 16;
    int i = 0;
    while(i<5 && phoenix){
        this->insertFirst(new PhoenixdownIItem());
        i++; phoenix--;
    } 
    i = 0;
     while(i<5 && antidote){
        this->insertFirst(new AntidoteItem());
        i++; antidote--;
    }
}
bool LancelotBag::insertFirst(BaseItem * item){
    if(this->size >= this->maxsize) return false;
    if(head == nullptr){
        head = item;
        this->size++;
        return true;
    }
    item->next = this->head;
    head = item;
    this->size++;
    return true;
}
NormalBag::NormalBag(BaseKnight* knight,int antidote,int phoenix):BaseBag(knight){
    this->maxsize = 19;
   int i = 0;
    while(i<5 && phoenix){
        this->insertFirst(new PhoenixdownIItem());
        i++; phoenix--;
    } 
    i = 0;
     while(i<5 && antidote){
        this->insertFirst(new AntidoteItem());
        i++; antidote--;
    }
}
bool NormalBag::insertFirst(BaseItem * item){
    if(this->size >= this->maxsize) return false;
    if(head == nullptr){
        head = item;
        this->size++;
        return true;
    }
    item->next = this->head;
    head = item;
    this->size++;
    return true;
}
DragonBag::DragonBag(BaseKnight* knight,int phoenix):BaseBag(knight){
    this->maxsize = 14;
    int i = 0;
    while(i<5 && phoenix){
        this->insertFirst(new PhoenixdownIItem());
        i++; phoenix--;
    } 
}
bool DragonBag::insertFirst(BaseItem * item){
    if(this->size >= this->maxsize || item->getName() == Antidote) return false;
    if(head == nullptr){
        head = item;
        this->size++;
        return true;
    }
    item ->next = this->head;
    head = item;
    this->size++;
    return true;
}
/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
BaseKnight *BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    BaseKnight* knight;
    int tmp=maxhp;
    bool a=false;
    bool b=false;
    bool c=false;
    while(tmp){
        if(tmp%10==3){
            a=true;
        }
        if(tmp%10==4){
            b=true;
        }
        if(tmp%10==5){
            c=true;
        }
        tmp=tmp/10;
    }
    int count=0;
    for(int i=1;i<=maxhp;i++){
        if (maxhp%i==0){
            count++;
        }
    }
    if(maxhp==888){
        knight= new LancelotKnight();
        knight->bag= new LancelotBag(knight,antidote,phoenixdownI);
    }
    else if(count==2){
        knight= new PaladinKnight();
        knight->bag= new PaladinBag(knight,antidote,phoenixdownI);
    }
    else if(a && b && c){
        knight= new DragonKnight();
        knight->bag= new DragonBag(knight,phoenixdownI);
    }
    else {
        knight=new NormalKnight();
        knight->bag= new NormalBag(knight,antidote,phoenixdownI);
    }
    knight->setMaxHp(maxhp);
    knight->setHp(maxhp);
    knight->setLevel(level);
    knight->setGil(gil);
    knight->setId(id);
    knight->setAntidote(antidote);
    knight->setPoison(false);
    return knight;
}
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
PaladinKnight::PaladinKnight(){
    this->knightType=PALADIN;
}
int PaladinKnight::baseDame(){
    return  this->getHp() * this->getLevel() * 0.06;
}
bool PaladinKnight::fight(BaseOpponent* opponent){
    int tmp=this->hp;
    opponent->fight(this);
    if(this->hp < tmp){
        this->bag->upHP();
    }
    if(this->getHp()<=0 && this->getGil()>=100){
        this->setHp(this->getMaxHp()/2);
        this->setGil(this->getGil() - 100);
    }
return this->getHp() > 0;
}
LancelotKnight::LancelotKnight(){
    this->knightType=LANCELOT;
}
int LancelotKnight::baseDame(){
    return  this->getHp() * this->getLevel() * 0.05;
}
bool LancelotKnight::fight(BaseOpponent* opponent){
    int tmp=this->hp;
    opponent->fight(this);
    if(this->hp < tmp){
        this->bag->upHP();
    }
    if(this->getHp()<=0 && this->getGil()>=100){
        this->setHp(this->getMaxHp()/2);
        this->setGil(this->getGil() - 100);
    }
return this->getHp() > 0;
}
DragonKnight::DragonKnight(){
    this->knightType=DRAGON;
}
int DragonKnight::baseDame(){
    return  this->getHp() * this->getLevel() * 0.075;
}
bool DragonKnight::fight(BaseOpponent* opponent){
    int tmp=this->hp;
    opponent->fight(this);
    if(this->hp < tmp){
        this->bag->upHP();
    }
    if(this->getHp()<=0 && this->getGil()>=100){
        this->setHp(this->getMaxHp()/2);
        this->setGil(this->getGil() - 100);
    }
return this->getHp() > 0;
}
NormalKnight::NormalKnight(){
    this->knightType=NORMAL;
}
int NormalKnight::baseDame(){
    return 0;
}
bool NormalKnight::fight(BaseOpponent* opponent){
    int tmp=this->hp;
    opponent->fight(this);
    if(this->hp < tmp){
        this->bag->upHP();
    }
    if(this->getHp()<=0 && this->getGil()>=100){
        this->setHp(this->getMaxHp()/2);
        this->setGil(this->getGil()-100);
    }
return this->getHp() > 0;
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class BaseItem * * */

bool AntidoteItem::canUse(BaseKnight* knight){
    return knight->getPoison();
}
void AntidoteItem::use(BaseKnight* knight){
    knight->setPoison(false);
}
//
bool PhoenixdownIItem::canUse(BaseKnight* knight){
    return knight->getHp()<= 0;
}
void  PhoenixdownIItem::use(BaseKnight* knight){
    knight->setHp(knight->getMaxHp());
}
//
bool PhoenixdownIIItem::canUse(BaseKnight* knight){
    return knight->getHp()<(knight->getMaxHp()/4);
}
void PhoenixdownIIItem::use(BaseKnight* knight){
    knight->setHp(knight->getMaxHp());
}   
//
bool PhoenixdownIIIItem::canUse(BaseKnight* knight){
    return knight->getHp()<(knight->getMaxHp()/3);
}
void PhoenixdownIIIItem::use(BaseKnight* knight){
    knight->setHp(knight->getHp()<=0 ? knight->getMaxHp()/3 : (knight->getHp()+ knight->getMaxHp()/4));
}
//
bool PhoenixdownIVItem::canUse(BaseKnight* knight){
    return knight->getHp()<(knight->getMaxHp()/2); 
}
void PhoenixdownIVItem::use(BaseKnight* knight) {
    knight->setHp((knight->getHp()<=0) ? knight->getMaxHp()/2 : (knight->getHp()+ knight->getMaxHp()/5));
}
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights::ArmyKnights(const string & file_armyknights){
    ifstream file(file_armyknights);
    file>>size;
    this->arrArmy= new BaseKnight*[size];
    int maxhp, level, phoenixdownI, gil, antidote;
    for(int i=0;i<size;i++){
       file>>maxhp>>level>>phoenixdownI>>gil>>antidote;
       this->arrArmy[i]=BaseKnight::create(i+1,maxhp,level,gil,antidote,phoenixdownI);
    }
}
ArmyKnights::~ArmyKnights(){
    for (int i = 0; i < this->size; i++)
    {
        delete arrArmy[i];
    }
    delete[] arrArmy;
}
bool ArmyKnights::fight(BaseOpponent* opponent){
        BaseKnight* lastknight= lastKnight();
        if(lastknight->fight(opponent)==true){
            for(int i=size-1;i>=1;i--){
                int residual=arrArmy[i]->getGil()-999;
                if(residual>0) arrArmy[i]->setGil(999);
                if(residual<=0) break;
                arrArmy[i-1]->setGil(residual + arrArmy[i-1]->getGil());
            }
        if(arrArmy[0]->getGil()>999) {arrArmy[0]->setGil(999);}
            delete opponent;
            return this->size;
        }
    size--;
    delete lastknight;
    delete opponent;
    return this->size;
}
bool ArmyKnights::adventure(Events* events){
    for(int i=0;i<events->count();i++){
        int eventId=events->get(i);
        if(eventId>=1 && eventId<=11){
            OpponentType nameMonster = (OpponentType) eventId;
            this->fight(BaseOpponent::create(i,nameMonster));
            if(BaseOpponent::WinHades) this->PaladinShield = true;
        }
        else if(eventId==112){
            for(int i=this->count()-1;i>=0;i--){
            if(arrArmy[i]->getBag()->size<arrArmy[i]->getBag()->maxsize||arrArmy[i]->getType()==PALADIN){
                arrArmy[i]->setBag(new PhoenixdownIIItem());
                break;
            }
        }
        }
        else if(eventId==113){
            for(int i=this->count()-1;i>=0;i--){
            if(arrArmy[i]->getBag()->size<arrArmy[i]->getBag()->maxsize||arrArmy[i]->getType()==PALADIN){
                arrArmy[i]->setBag(new PhoenixdownIIIItem());
                break;
            }
        }
        }
        else if(eventId==114){
            for(int i=this->count()-1;i>=0;i--){
            if(arrArmy[i]->getBag()->size<arrArmy[i]->getBag()->maxsize||arrArmy[i]->getType()==PALADIN){
                arrArmy[i]->setBag(new PhoenixdownIVItem());
                break;
            }
        }
        }
        else if(eventId==95){
            this->PaladinShield=1;
        }
        else if(eventId==96){
            this->LancelotSpear=1;
        }
        else if(eventId==97){
            this->GuinevereHair=1;        
        }
        else if(eventId==98){
            if(this->hasGuinevereHair() && this->hasLancelotSpear() && this->hasPaladinShield()){
               this->ExcaliburSword=1;
            }
        }
        else if(eventId==99){
            if(this->hasExcaliburSword()){
                this->printInfo();
                return true;
            }
            else if( this->hasPaladinShield()* this->hasLancelotSpear()*this->hasGuinevereHair() == 0){
                while(size--){
                delete arrArmy[size];
                }
                size=0;
            }
            else{
                int  HpBoss=5000;
                int  numNormal=0;
                bool check=1;
                BaseKnight* deadknight=nullptr;
                while(this->size){
                    BaseKnight* knight= lastKnight();
                    if(knight->getType()!=NORMAL) HpBoss-=knight->baseDame();
                    else numNormal++;
                    if(knight->getType()==NORMAL && deadknight==nullptr){
                        check=0;
                        deadknight=knight;
                        this->size--;
                    }
                    if(HpBoss<=0){
                        if(deadknight==nullptr){
                            this->printInfo();
                        }
                        else{
                            this->size+=numNormal;
                            arrArmy[size-1]=deadknight;
                            this->printInfo();
                            this->size-=numNormal;
                            delete deadknight;
                        }
                        return true;
                    }
                    if(check==0){check=1;}
                    else {delete knight; this->size--;}
                }
                    if(deadknight!=nullptr) delete deadknight;
            }
        }
        this->printInfo();
        if(this->size==0){return false;}
    }
   return true;
}
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class Events * * */
Events::Events(const string & file_events){
    ifstream file(file_events);
    string line;
    file>>size;
    getline(file,line);
    getline(file,line);
    stringstream ss(line);
    this->arr=new int[size];
    for(int i=0;i<size;i++){
        ss>>arr[i];
    }
}
int Events::count() const{
    return this->size;
}
int Events::get(int i) const{
    return this->arr[i];
}
Events::~Events(){
    delete[] arr;
}
/* * * END implementation of class Events * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure(){
    delete armyKnights;
    delete events;
}
void KnightAdventure::loadArmyKnights(const string &file){
armyKnights= new ArmyKnights(file);
}
void KnightAdventure::loadEvents(const string &file){
events= new Events(file);
}
void KnightAdventure::run(){
BaseOpponent::WinOmegaWeapon=BaseOpponent::WinHades=false;
armyKnights->printResult(armyKnights->adventure(events));
}

/* * * END implementation of class KnightAdventure * * */