#include <iostream>
#include <cstring>
using namespace std;

//factory

class Shape
{
public:
    virtual void Afiseaza(){};
private:
};

template <typename T> class Rectangle : public Shape
{
public:
    Rectangle(T L, T l){this->L=L; this->l=l;};
    void Afiseaza(){cout<<"Dreptunghi:\nAria: "<<L*l<<"\nPerimetrul: "<<L*2+l*2<<"\n\n";}
    friend class Shape;
    ~Rectangle();
private:
    T L,l; // lungime, latime
};

template <typename T> class Square : public Shape
{
public:
    Square(T L){this->L=L;};
    void Afiseaza(){cout<<"Patrat:\nAria: "<<L*L<<"\nPerimetrul: "<<L*4<<"\n\n";}
    friend class Shape;
    ~Square();
private:
    T L;
};

template <typename T> class Circle : public Shape
{
public:
    Circle (T r){this->r=r;};
    void Afiseaza(){cout<<"Cerc:\nAria: "<<(pi*r*r)/2<<"\nPerimetrul: "<<2*pi*r<<"\n\n";}
    friend class Shape;
    ~Circle();
private:
    T r,pi=3.14; //raza
};

class ShapeFactory
{
    public:
    Shape* get_shape(string type)
    {
    if ( type == "circle-i" ){int r; cout<<"raza:"; cin>>r; return new Circle<int>(r);}
    if ( type == "circle-f" ){float r; cout<<"raza:"; cin>>r; return new Circle<float>(r);}
    if ( type == "square-i" ){int L; cout<<"Lungimea laturii:"; cin>>L; return new Square<int>(L);}
    if ( type == "square-f" ){float L; cout<<"Lungimea laturii:"; cin>>L; return new Square<float>(L);}
    if ( type == "rectangle-i" ){int L,l; cout<<"Lungimea:"; cin>>L; cout<<"latimea:"; cin>>l; return new Rectangle<int>(L,l);}
    if ( type == "rectangle-f" ){float L,l; cout<<"Lungimea:"; cin>>L; cout<<"latimea:"; cin>>l; return new Rectangle<float>(L,l);}
    return NULL;
    }
    private:
};

int main()
{

    cout<<"Tipuri:\ncircle-i/circle-f -> cerc-int/cerc-float\nsquare-i/square-f -> patrat-int/patrat-float\nrectangle-i/rectangle-f -> dreptunghi-int/dreptunghi-float\n"<<endl;

    ShapeFactory* s = new ShapeFactory();

    Shape* ob1 = s->get_shape("circle-f");
    ob1->Afiseaza();

    Shape* ob2 = s->get_shape("square-i");
    ob2->Afiseaza();

    Shape* ob3 = s->get_shape("rectangle-f");
    ob3->Afiseaza();

    return 0;
}
