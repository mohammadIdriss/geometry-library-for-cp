#include <iostream>
#include <cmath>
using namespace std;
typedef long double ld;

//2d point
struct pt{
    ld x,y; //coordinates

    //basic operations
    pt operator+(pt p) {return {x+p.x,y+p.y};} // two points addition
    pt operator-(pt p) {return {x-p.x,y-p.y};} // two points substraction
    pt operator*(ld a) {return {x*a,y*a};}     // point multiplied by num
    pt operator/(ld a) {return {x/a,y/a};}     // point divided by num

};
//logical operations 
bool operator==(pt a,pt b) {return a.x==b.x && a.y==b.y;}
bool operator!=(pt a,pt b) {return !(a==b);}

//distace function using the formula sqrt(x^2+y^2);
ld sq(pt p) {return p.x*p.x + p.y*p.y;} 
ld abs(pt p) {return sqrt(sq(p));}

//stream operator
ostream& operator<<(ostream& os,pt p){
    return os << "("<<p.x<<","<<p.y<<")";
}


//2d transformations
//translation
pt translate(pt p,pt v){return p+v;}

//scaling
pt scale(pt c,ld factor, pt p){
    return c + (p-c)*factor;
}

//rotation around the origin by angle a
pt rotate(pt p,double a){
    return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

//rotation around origin by 90 
pt prep(pt p){
    return {-p.y,p.x};
}

//dot product
ld dot(pt v,pt p){
    return p.x*v.x + p.y*v.y;
}

//check if to vectors ar prependicular
bool isprep(pt v,pt w){
    return dot(v,w)==0;
}

//calculate the angle between two vectors
double angle(pt v,pt w){
    double cosine=dot(v,w)/abs(v)/abs(w);
    return acos(max(-1.0,min(1.0,cosine))); //assure cosine between [-1,1]
}

//cross product
ld cross(pt v,pt w){
    return v.x*w.y - v.y*w.x;
}

//orientation (>0 if C is on the left of AB , <0 if C is on the right of AB , ==0 if A B C is collinear)
ld orient(pt a,pt b,pt c){
	return cross(b-a,c-a);
}

bool iscollinear(pt a,pt b,pt c){
	return cross(b-a,c-a)==0;
}

//determine the angle between three points (the angle between two lines we make from three points)

double orientedAngle(pt a,pt b,pt c){
	if(orient(b-a,c-a)>=0){
		return angle(b-a,c-a);
	}else{
		return 2*M_PI - angle(b-a,c-a);
	}
}


//polar sort should have been here



int main(){
    //test
    pt p={1,2};
    pt q={3,4};
    cout<<p+q<<endl;
    return 0;
}
