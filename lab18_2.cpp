//Modify function overlap() form lab18_1.cpp by using pointers as input arguments.
#include<iostream>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
	Rect R1,R2;
	cout << "Please input Rect 1 (x y w h): ";
	cin >> R1.x>>R1.y>>R1.w>>R1.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin >> R2.x>>R2.y>>R2.w>>R2.h;
	
	cout << "Overlap area = "<< overlap(&R1,&R2) ;	
	return 0;
}
double overlap(Rect *R1,Rect *R2){
	double n;
	double m;
	double x1,x2,y1,y2;

	x1=R1->x+R1->w;
	x2=R2->x+R2->w;
	y1=R1->y-R1->h;
	y2=R2->y-R2->h;

	n=-max(R1->x,R2->x)+min(x1,x2);
	m=min(R1->y,R2->y)-max(y1,y2);
	
	int k =n*m;
	if(n<0 && m<0){
		k = 0;
	}
	return k;
	
	
}