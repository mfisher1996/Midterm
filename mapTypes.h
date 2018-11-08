//
//  Header.h
//  MidtermProgram
//
//  Created by Mason Fisher on 10/18/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//

#ifndef mapTypes_h
#define mapTypes_h

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;




class Validation{
public:
    /**
     Author: MASON FISHER
     
     Validation constructor
     
     Perameters: none
     
     */
    Validation();
    /**
     Author: MASON FISHER
     
     Validation destructor
     
     Perameters: none
     
     
     */
    ~Validation();
    /**
     Author: MASON FISHER
     
     Validation yOn()
     
     Yes or no input validation.
     Returns true if user types Y or Yes and false if user inputs N or no
     
     Perameters: none
     
     Returns: true if 'Y' is input and false if 'N' is input
     
     */
    bool yOn();
    
    /**
     Author: MASON FISHER
     
     Validation numb(int)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
     -int num
     
     Returns: an integer from input
     
     */
    int numb(int);
    /**
     Author: MASON FISHER
     
     Validation numb(int, int, int)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
     -int num
     -int high
     -int low
     
     Returns: an integer below high and above low
     
     */
    int numb(int, int, int);
    /**
     Author: MASON FISHER
     
     Validation numb(double)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
     -double num
     
     Returns: a double
     
     */
    double numb(double);
    /**
     Author: MASON FISHER
     
     Validation numb(double, double, double)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
     -double num     // Number to be validated. Also passed to disabiguate function call.
     -double high    // Number that should not be exceded by num
     -double low     // Number that should not exced num
     
     Returns: a double below high and above low
     
     */
    double numb(double, int, int);
    /**
     Author: MASON FISHER
     
     Validation numb(float)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
     -float num
     
     Returns: a float
     
     */
    float numb(float);
    /**
     Author: MASON FISHER
     
     Validation numb(float, float, float)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
     -float num      // Number to be validated. Also passed to disabiguate function call.
     -float high     // Number that should not be exceded by num
     -float low      // Number that should not exced num
     
     Returns: a float below high and above low
     
     */
    float numb(float, int, int);
    /**
     Author: MASON FISHER
     
     Validation word()
     
     Discribtion:
     gets a line from input and asks the user if that is what they meant to type.
     
     Perameters: none
     
     Returns: a string that the user confirms
     */
    std::string word();
    /**
     Author: MASON FISHER
     
     Validation clear()
     
     Description:
     clears the input buffer. Used in input functions invloving numbers or anything not including strings.
     
     Perameters: none
     
     
     */
    void clear(){std::cin.clear(); std::cin.ignore(40,'\n');};
    void file(std::fstream *, std::string);
    void out(string output="");
    std::string get_s(std::fstream *);
    
};

/**
 Validation constructor
 -parameters: none
 */
Validation :: Validation()
{
}

/**
 Validation destructor
 -perameters: none
 */
Validation :: ~Validation()
{
    
}

/**
 MASON FISHER
 Validation yOn()
 Yes or no input validation.
 Returns true if user types Y or Yes and false if user inputs N or no
 -perameters: none
 */
bool Validation :: yOn()
{
    
    std::string str ="";
    out();
    do
    {
        std::cout << "Enter 'Y' for yes or 'N' for No: ";
        std::cin >> str;
        clear();
        if(toupper(str[0]) == 'Y')
            return true;
        else if(toupper(str[0]) == 'N')
            return false;
        else
        {
            out();
            std::cout << "Invalid input, Please ";
        }
        
    }
    while((toupper(str[0]) != 'N'&&(toupper(str[0]) != 'Y')));
    return false;
}

/**
 Validation numb(int)
 integer validation.
 Returns true if user types an integer and returns false if the user does not
 -perameters: int
 */
int Validation :: numb(int num)
{
    clear();
    std::cin >> num;
    
    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(int,int,int)
 ranged integer validation.
 Returns true if user types an integer equal to or between the low high variables
 returns false if int value is below the low value or above the high value
 -perameters: int, min int, max int
 */
int Validation :: numb(int num, int low, int high)
{
    std::cin >> num;
    
    while(!num||!(num<=high&&num>=low))
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(double)
 double validation.
 Returns true if user types a double value and returns false if the user does not
 -perameters: double
 */
double Validation :: numb(double num)
{
    clear();
    std::cin >> num;
    
    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(double,int,int)
 ranged double validation.
 Returns true if user types an double that is equal to or between the low and high values
 returns false if double is below low value or above high value
 -perameters: double,min int,max int
 */
double Validation :: numb(double num, int low, int high)
{
    std::cin >> num;
    
    while(!num||!(num<=high||num>=low))
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(float)
 float validation.
 Returns true if user types a float value and returns false if the user does not
 -perameters: float
 */
float Validation :: numb(float num)
{
    std::cin >> num;
    
    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(float,int,int)
 ranged float validation.
 Returns true if user types a float that is equal to or between the low and high values
 returns false if float is below low value or above high value
 -perameters: float,min int,max int
 */
float Validation :: numb(float num, int low, int high)
{
    std::cin >> num;
    
    while(!num||!(num<=high||num>=low))
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation word()
 string validation.
 takes in string value
 -perameters: ~none~
 */
std::string Validation :: word()
{
    std::string strW = "";
    do{
        out();
        getline(std::cin, strW,'\n');
        out();
        std::cout << "You typed " << strW << ". Is this what you meant?\n";
        if(yOn())
            return strW;
        else
            strW = "";
        out();
        std::cout << "Please re-type your input: ";
    }while(strW == "");
    return strW;
}

/**
 Validation out()
 indents
 -perameters: ~none~
 */
void Validation :: out(string output)
{
    int bound = 55;
    cout << "\t\t";
    if(output.size()>0 && output.size()<=bound) // string passed is within the bounds
    cout << output << endl;
    else if(output.size()==0) // string passed is empty
    return;
    else{ // string passed is larger than bounds
        int i = bound;
        while(output[i]!=' ')
            i--;
        cout << output.substr(0,i) << endl;
        out(output.substr(i+1));
    }
}

void Validation :: file(std::fstream * file, std::string name){
    
    file->open(name);
    while(!file->is_open()){
        out();
        std::cout << "The file could not be found with the name: " << name << " \n";
        out();
        std::cout << "Please input a new name to check or type -99 to cancel: ";
        name = word();
        
        if(name == "-99")
            return;
        
        file->open(name.c_str());
    }
    if(name != "-99"){
        out();
        std::cout << "The file " << name << " was succesfully opened.\n";
    }
    
}


std::string Validation :: get_s(std::fstream * in){
    
    string output= "";
        getline(*in, output);
    return output;
}


class DoubleLinked{
private:
    struct node{
        int mile;
        string high;
        string highA;
        string name;
        node * right;
        node * left;
        bool isIn;
    };
    
    
    
    Validation check;   // Validation object used for input and output conformity
    int len;            // length of list
    node * cur;         // transiet node pointer used generally in methods
    node * first;       // first node in list that will have a mile == 0
    node * last;        // last node loaded
    // find(string)
    // returns the node who's name equals the string passed.
    node * find(string i){if(first == NULL)return nullptr;else{cur = first;for(int j = 0; j < len; j++){if(cur->name==i)return cur;else cur=cur->right;}return nullptr;}};
public:
    // VideoList constructor
    // Initializes first and last to be pointing at nulls and custCount and len to 0
    DoubleLinked(){first = nullptr;last= nullptr; len=0;};
    
    // DoubleLinked destructor
    // Deletes each member of the linked list.
    ~DoubleLinked();
    
    // insert(int)
    // inserts a string into the linked list.
    void insert(string insertItem);
    
    // insertIn(string)
    // modified version of the insert function that uses an intersection instead of a regular node.
    void insertIn(string insertItem);
    
    // remove (int)
    // deletes the first element of the linked list that is the same as insertItem
    void remove(string deleteItem);
    
    // print()
    // Outputs the element names that are in the list.
    void print();
    
    // size()
    // an accessor for the len private member. returns the number of elements in the list.
    int size(){return len;};
    
    // search(string)
    // returns true if the string passed is in the list.
    bool search(string searchItem);
    
    // load()
    // takes the data from mapFile.txt and stores it in the nodes. if mapfile.txt is not found in ./ then asks the user for filename.
    void load();
    
    // getHigh(string)
    // Accessor for high. returns high stored in the node where name == string
    string getHigh(string searchItem){return find(searchItem)->high;};
    
    // getDistance(string)
    // Accessor for mile. returns mile held in node where name == string
    int getDistance(string searchItem){return find(searchItem)->mile;};
    
    // getHigh2(string)
    // accessor for highA. Will return the second highway of the node if it is an intersection.
    string getHigh2(string searchItem){if(find(searchItem)->isIn)return find(searchItem)->highA;else return "";};
    
    // DoubleLinked(string,DoubleLinked)
    // Sets string passed as new starting node and copies nodes from DoubleLinked passed so that they hold information relating to new starting node.
    DoubleLinked(string name, DoubleLinked & baseList);
    
    // unused
    // node * nextCity(node * current);
    
    // sharedHigh(string, string)
    // returns the highway shared by two city names passed.
    string sharedHigh(string name, string name1);
    
    // getInt(string)
    // returns the node pointer that shares one highway with the first node in list and node with name of string passed.
    node * getInt(string name);
    
    // getInter(string, int)
    // returns the node pointer that shares one highway with first node in list and the next node that connects to the node with name of string passed.
    // neccisary when there is more than one turn in directions.
    node * getInter(string name, int num);

    // setMile(string, int)
    // a modifier for the mile member of struct that holds string. sets mile to int passed
    void setMile(string modItem, int set){find(modItem)->mile = set;};
};

DoubleLinked::node * DoubleLinked::getInter(string name, int num){
    if(sharedHigh(first->name, name)!=""){
        return getInt(name);
    }else{
        string str;
        cur = first;
        while(cur!=NULL){
            node * current = first;
            if((sharedHigh(name, cur->name)!=""&& name != cur->name)){ // name and cur share a highway.
                str = cur -> name;
                while(current!=NULL){
                    if(sharedHigh(first->name, current->name)!="" && sharedHigh(current->name, cur->name)!=""){ // first and current share a highway and current and cur share a highway.
                        if(num==1)
                            return current;
                        else if(num==2)
                            return cur;
                    }else
                        current = current->right;
                }
            }else
                cur= cur->right;
        }// end for
    }// end else
    return nullptr;
}// end getInter()

DoubleLinked::node * DoubleLinked::getInt(string name){
    cur = first;
    while(cur!=NULL){
        if((sharedHigh(name, cur->name) != "") && (sharedHigh(cur->name, first->name) != "") && cur->mile < find(name)->mile)
            return cur;
        else
            cur = cur -> right;
    }
    return nullptr;
}

string DoubleLinked::sharedHigh(string name, string name1){
    cur = find(name1);
        if ( cur -> high == find(name) -> high ) // highway 1 is the same in cur and name
            return cur -> high;
        else if( cur->isIn && ( cur-> highA == find(name) -> high)) // highway 2 of cur is the same as highway 1 of name
            return cur -> highA;
        else if( find(name)-> isIn && (cur-> high == find(name)->highA)) // highway 2 of name is the same as highway 1 of cur
            return find(name)->highA;
        else if( (cur->isIn && find(name)->isIn) && (cur->highA == find(name)->highA)) // highway 2 is the same in cur and name
            return cur -> highA;
        else{
            return "";
        }
        
    return "";
}
    
/**
 DoubleLinked::node * DoubleLinked::nextCity(node * current){
    node * temp = first;
    
    if(temp->right != NULL){ // general case
        if(current->high == temp->high || current->highA==temp->highA||current->high == temp->highA || current->highA == temp->high){ // current and temp share any highway
            if(temp->mile < nextCity(temp->right)->mile)
                temp = temp;
            else if(nextCity(temp->right)==NULL)
                temp = temp;
            else
                temp = nextCity(temp->right);
        }else
            temp = nextCity(temp->right);
    }else// general case
        temp = temp;
    return temp;
}
*/

DoubleLinked::DoubleLinked(string inser, DoubleLinked & baseList){
    while(!baseList.search(inser)){
        check.out("Please re-type your destination.");
        inser = check.word();
    }
    node * ref= baseList.find(inser);
    first = nullptr;
    last = nullptr;
    len = 0;
    int start = ref->mile;
    if(ref->isIn)
        insertIn(inser);
    else
        insert(inser);
    cur = first;
    cur -> mile = 0;
    cur -> high = ref -> high;
    cur -> highA = ref -> highA;
    while(ref->left != NULL)
        ref = ref->left;
    while(ref->right != NULL){
        if(!(ref->name == first->name)){
            if(ref->isIn)
                insertIn(ref->name);
            else
                insert(ref->name);
            find(ref->name)->high=ref->high;
            find(ref->name)->highA=ref->highA;
            if(sharedHigh(ref->name,first->name) != "") // first and current share a highway
                if(ref->mile > start) // current distance from original first is greater than first's original distance
                    setMile(ref->name, ref->mile-start);
                else // distance of current node is less than distance starting node's distance
                    setMile(ref->name, start-ref->mile);
            else{
                node * inter = baseList.getInt(ref->name);
                if(inter == NULL){
                    inter = baseList.getInter(ref->name, 1);
                    node * inter2;
                    inter2 = baseList.getInter( ref->name, 2);
                    if(inter->mile < inter2 -> mile)
                        setMile(ref->name, (inter2->mile-inter->mile)+(start-inter->mile)+(ref->mile-inter2->mile));
                    else
                        setMile(ref->name, (inter->mile-inter2->mile)+(start-inter->mile)+(ref->mile-inter2->mile));
                } // end if
                
            } // end else
        } // end if
        ref = ref -> right;
    } // end while
    if(!(ref->name == first->name)){
        if(ref->isIn)
            insertIn(ref->name);
        else
            insert(ref->name);
        find(ref->name)->high=ref->high;
        find(ref->name)->highA=ref->highA;
        if(sharedHigh(ref->name,first->name) != "") // first and current share a highway
            if(ref->mile > start) // current distance from original first is greater than first's original distance
                setMile(ref->name, ref->mile-start);
            else // distance of current node is less than distance starting node's distance
                setMile(ref->name, start-ref->mile);
            else{
                node * inter = baseList.getInt(ref->name);
                if(inter == NULL){
                    inter = baseList.getInter(ref->name, 1);
                    node * inter2;
                    inter2 = baseList.getInter( ref->name, 2);
                    if(inter->mile < inter2 -> mile)
                        setMile(ref->name, (inter2->mile-inter->mile)+(start-inter->mile)+(ref->mile-inter2->mile));
                    else
                        setMile(ref->name, (inter->mile-inter2->mile)+(start-inter->mile)+(ref->mile-inter2->mile));
                } // end if
                
            } // end else
    }
}

void DoubleLinked::load(){
    
    fstream * ptr = new fstream;
    check.file(ptr, "file.txt");
    string line;
    while(getline(*ptr,line)){
        istringstream ss(line);
        string name;
        getline(ss,name,',');
        if(name == "in"){            // this data is for an intersection.
            getline(ss,name,',');
            insertIn(name);
        }else{
            
            insert(name);
        }
        string str;
        getline(ss,str,',');
        find(name)->mile = stoi(str);  // stoi converts string which should hold int to int.
        getline(ss,str,',');
        find(name)-> high = str;
        if(find(name)->isIn){
            getline(ss,str,',');
            find(name)->highA = str;
        }
    }
    delete ptr;
}

void DoubleLinked::insert(string insertItem){
    node * nNode;
    nNode= new node;
    nNode->name = insertItem;
    nNode->right = nullptr;
    nNode->left = nullptr;
    nNode->mile = 0;
    nNode->isIn = 0;
    nNode->high = "";
    nNode->highA= "";
    if(find(insertItem)!=NULL)
        delete nNode;
    else{
        if(first==NULL){ // if list is empty
            first = nNode;
            last = nNode;
            len++;
        }
        else{ // any other insert
            last->right= nNode;
            nNode->left = last;
            last = nNode;
            len++;
        }
    }
}

void DoubleLinked::insertIn(string insertItem){
    node * nNode;
    nNode= new node;
    nNode->name = insertItem;
    nNode->right = nullptr;
    nNode->left = nullptr;
    nNode->mile = 0;
    nNode->isIn = 1;
    nNode->high = "";
    nNode->highA= "";
    if(search(insertItem)) // insert item is in list already.
        delete nNode;
    else{
        if(first==NULL){ // if list is empty
            first = nNode;
            last = nNode;
            len++;
        }
        else{ // any other insert
            last->right= nNode;
            nNode->left = last;
            last = nNode;
            len++;
        }
    }
}


bool DoubleLinked::search(string searchItem){
    cur = first;
    for(int i = 0; i < len; i++){
        if(cur-> name == searchItem)
            return true;
        cur=cur->right;
    }
    return false;
}

void DoubleLinked::remove(string deleteItem){
    node * trail;
    bool found;

    if (first == NULL)
        cout << "Cannot remove from an empty list.\n";
    else if (first->name == deleteItem){
        cur=first;
        first = first->right;
        if(first!=NULL)
            first->left = nullptr;
        else
            last= nullptr;
        len--;
        delete cur;
        
    }else if(last->name == deleteItem){
        cur = last;
        last = cur -> left;
        if(last!=NULL)
            last->right = nullptr;
        else
            first = nullptr;
        len--;
        delete cur;
    }else{
        found = false;
        cur = first;
        while (cur!=NULL && !found){
            if (cur->name==deleteItem)
                found = true;
            else
                cur = cur->right;
        }
        if(cur==NULL&&!found)
            cout << deleteItem <<" is not in the list.\n";
        else if (found){
            trail = cur->left;
            trail->right = cur->right;
            if(cur->right != NULL)
                cur->right->left = trail;
            if(cur==last)
                last = trail;
            len--;
            delete cur;
        }else
            cout << deleteItem << " is not in the list.\n";
        
    }
}// end remove




void DoubleLinked::print(){
    cur = first;
    int i=1;
    check.out("The cities in this list are:");
    while(cur->right != NULL){
        check.out();
        check.out(to_string(i)+": "+cur->name);
        cur=cur->right;
        i++;
    }// end while
    check.out();
    check.out(to_string(i)+": "+cur->name);
}// end print
/*
 void VideoList::sort(){
 node * sort;
 cur=first;
 while(cur!=last){
 if(cur->info <= cur->right->info)
 cur=cur->right;
 else if(cur->info > cur->right->info){
 if(cur->right!=last){
 sort=cur->right;
 cur = cur-> left;
 while(cur->info > sort->info)
 cur = cur->left;
 sort->left = cur;
 sort->right = cur->right;
 cur -> right = sort;
 sort->right->left= sort;
 cur= cur->right;
 last->right=nullptr;
 }else{
 last=cur;
 sort=cur->right;
 cur = cur-> left;
 while(cur->info > sort->info)
 cur = cur->left;
 sort->left = cur;
 sort->right = cur->right;
 cur -> right = sort;
 sort->right->left= sort;
 cur= cur->right;
 last->right=nullptr;
 }
 }else{
 cout << 4<<endl;
 cur=cur->right;
 }
 
 }
 }
 */
DoubleLinked::~DoubleLinked(){
    while(first!= NULL && len > 0)
        remove(first->name);
    
}
    
#endif /* Header_h */
