#include <bits/stdc++.h>
using namespace std;
string type="";
class student{
private:
    float GPA;
    string name;
    string id;
public:
    student(string name,string id,float GPA){
          this->GPA=GPA;
          this->name=name;
          this->id=id;
    }
     string getname(){
         return this->name;
     }
     string  getid(){
         return this->id;
     }
     float getgpa(){
         return this->GPA;
     }
     friend  bool operator>(student s1,student s2);
};
bool operator>(student s1, student s2) {
    if(type=="GPA"){
        return s1.GPA>s2.GPA;
    }else{
        return s1.name>s2.name;
    }
}
void Writeinfiles(string type,string algname,vector<student>arr){
    ofstream file;
    if(type=="GPA"){
        file.open("sortedbyGPA.txt",std::ios_base::app);
        file<<"*==*/Algorithm NAME/*==*"<<"\n";
        file<<algname<<"\n";
    }else{
        file.open("sortedbyname.txt",std::ios_base::app);
        file<<"*==*/Algorithm NAME/*==*"<<"\n";
        file<<algname<<"\n";
    }
    for (auto i:arr) {
        file<<"****STUDENT****"<<"\n";
        file<<"Name: "<<i.getname()<<"\n";
        file<<"GPA: "<<i.getgpa()<<"\n";
        file<<"ID: "<<i.getid()<<"\n";
    }
    file.close();
}
template<typename T>
vector<student> sortstudentsByinsertionsort(string tpe,vector<student>arr){
    type=tpe;
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
    return arr;
}
vector<student> selection_sortt(string typ,vector<student>arr){
    type=typ;
    int min;
    for (int i = 0; i <arr.size()-1; ++i) {
        min=i;
        for (int j = i; j < arr.size(); ++j) {
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
    return arr;
}
vector<student> shellSort(string typ, vector<student>array) {
    type=typ;
    int n=array.size();
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            student temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
    return array;
}
vector<student> merge(vector<student> left, vector<student> right) {
    vector<student> output;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if ( left[i] > right[j] ) {
            output.push_back(right[j]);
            j++;
        } else {
            output.push_back(left[i]);
            i++;
        }
    }
    while (i < left.size()) {
        output.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        output.push_back(right[j]);
        j++;
    }
    return output;
}
vector<student> mergeSort(string typ, vector<student> arr) {
    type=typ;
    int length = arr.size();
    if (length == 1) {
        return arr;
    }
    int mid = length / 2;
    vector<student> left(arr.begin(), arr.begin() + mid);
    vector<student> right(arr.begin() + mid, arr.end());
    left = mergeSort(typ,left);
    right = mergeSort(typ,right);
    return merge(left, right);
}
void quick_sort(vector<student>&arr, int left, int right){
    int i=left, j=right;
    student pivot=arr[(i+j)/2];
    while(i<=j){
        while(pivot>arr[i]){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

    }
    if(left<j){
        quick_sort(arr,left, j);
    }
    if(right>i){
        quick_sort(arr,i,right);
    }
}
vector<student>quick_H(string typ,vector<student>arr){
    type=typ;
    quick_sort(arr,0,arr.size()-1);
    return arr;
}

bool flag=true;
vector<student> SortByBubbleSort(string Type , vector<student>v){
    type=Type;
    int n=v.size();
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag=false;
            }
        }
        if(flag){
            break;
        }
    }
    return v;
}

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (s.substr (pos_start));
    return res;
}
void Readstudents(){
     vector<student>students;
     ifstream myfile;
     myfile.open("Students.txt");
     string line;
     getline(myfile,line);
     cout<<line<<endl;
     while (!myfile.eof())
     {
          getline(myfile,line);
          if(!line.empty()){
              auto s= split(line,",");
              student NewStudent(s[0],s[1],stof(s[2]));
              students.push_back(NewStudent);
          }
     }
     Writeinfiles("GPA","INSERTION SORT",sortstudentsByinsertionsort<student>("GPA",students));
     Writeinfiles("Name","INSERTION SORT",sortstudentsByinsertionsort<student>("Name",students));
     Writeinfiles("GPA","MERGE SORT",mergeSort("GPA",students));
     Writeinfiles("Name","MERGE SORT",mergeSort("Name",students));
     Writeinfiles("GPA","QUICK SORT",quick_H("GPA",students));
     Writeinfiles("Name","QUICK SORT",quick_H("Name",students));
     Writeinfiles("GPA","SELECTION SORT",selection_sortt("GPA",students));
     Writeinfiles("Name","SELECTION SORT",selection_sortt("Name",students));
     Writeinfiles("GPA","SHELL SORT",shellSort("GPA",students));
     Writeinfiles("Name","SHELL SORT",shellSort("Name",students));
     Writeinfiles("GPA","BUBBLE SORT",SortByBubbleSort("GPA",students));
     Writeinfiles("Name","BUBBLE SORT",SortByBubbleSort("Name",students));
     myfile.close();
}
int main(){
     Readstudents();
}