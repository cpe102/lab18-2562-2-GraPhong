#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct student{
	//Define struct student with four member (name ,id , gender, gpa);
	string name;
	string id;
	string gender;
	string gpa;
};

struct course{
	string name;
	int id;
	vector<string> lecture_list;
	vector<student *> student_list;
};

student * findstudent(vector<student> &allstudents,string key){ //Correct this line
	for(unsigned int i = 0; i < allstudents.size(); i++){
		if(allstudents[i].id  == key) return &allstudents[i];
	}
}

void printreport(vector<course> allcourses){
	for(unsigned int i = 0;i < allcourses.size(); i++){
		cout << "-----------------------------------------------------------------------------\n";
		cout << "Course:\t\t" << allcourses[i].name << " ("<< allcourses[i].id << ")\n\n";
		cout << "Lecturers:\t";
		for(unsigned int j = 0; j < allcourses[i].lecture_list.size();j++){
			if(j != 0) cout << ", ";
			cout << allcourses[i].lecture_list[j];
		} 
		cout << "\n\nStudents:\t";
		for(unsigned int j = 0; j < allcourses[i].student_list.size();j++){
			if(j != 0) cout << "\t\t";
			cout << setw(20) << left << allcourses[i].student_list[j]->name << "\t";
			cout << allcourses[i].student_list[j]->id << "\t";
			cout << allcourses[i].student_list[j]->gender << "\t";
			cout << allcourses[i].student_list[j]->gpa << "\n";
		} 
		
	}
	cout << "-----------------------------------------------------------------------------\n";
}

vector<string>StrSplit(string t, char A){
vector<string>split;
string text="";
for(int i=0;i<t.size();i++)
{
	if(t[i]==A){
		split.push_back(text);
		text="";
	}
	else{
		text+=t[i];
	}
	
	
}

if(text!=""){
			split.push_back(text);
	}
	return split;
}

int main(){
	ifstream student_file("students.txt");
	ifstream course_file("courses.txt");
	vector<student> allstudents;
	vector<course> allcourses;
	
	string textline;
	
	while(getline(student_file,textline)){
		student s; 
	
		//Assign value to the members of struct s;
		
		vector<string> data = StrSplit(textline, ',');
		s = {data[0], data[1], data[2], data[3]};
		allstudents.push_back(s); 		
	}
	
	int state = 1;
	course c;
	while(getline(course_file,textline)){
		if(state == 1){
			
			int loc = textline.find_first_of('(');
			c.name = textline.substr(0,loc-1);
			c.id = atof(textline.substr(loc+1,5).c_str());
			getline(course_file,textline);
			
			state = 2;			
		}else if(state == 2){
			if(textline == "> Students"){
				state = 3;
				
			}else{
				//Append lecture_list;
				c.lecture_list.push_back(textline);
			}			
		}else{
			if(textline == "---------------------------------------"){
				state = 1;
				allcourses.push_back(c);
				c = {};
			}else{
				student *p = findstudent(allstudents,textline);
				c.student_list.push_back(p);
			}
		}
	}
	printreport(allcourses);
	
}