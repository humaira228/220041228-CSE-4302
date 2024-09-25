#include<iostream>
#include<cmath>

using namespace std;

class TrigCalculator{
    private:
    float currentAngle;
    float prevAngle;



    float toRadian(float degree){
        return degree*M_PI/180;

    }

    void setValue(float x){
        prevAngle=currentAngle;
        currentAngle=x;
        
        
    }

    float getValue(){
        return currentAngle;
    }

    public:
    TrigCalculator():currentAngle(0), prevAngle(0){}
    TrigCalculator(float x):currentAngle(x),prevAngle(x){}
    float calculateSine(){
        return sin(toRadian(currentAngle));
    } 

    float calculateCosine(){
        return cos(toRadian(currentAngle));
    }

     float calculateTangent(){
        return tan(toRadian(currentAngle));
    }

    float calculateArcSine(){
        return asin(toRadian(currentAngle));
    }

    float calculateArcCosine(){
        return acos(toRadian(currentAngle));
    }

    float calculateArcTangent(){
        return atan(toRadian(currentAngle));
    }

    void calculateForAngle(float paramAngle){
        cout<<"For angle "<<paramAngle<<endl;
        cout<<"Sine: "<<sin(toRadian(paramAngle))<<endl;
        cout<<"Cosine: "<<cos(toRadian(paramAngle))<<endl;
        cout<<"Tangent: "<<tan(toRadian(paramAngle))<<endl;

    }

    void clear(){
        setValue(0);
    }

    void display(){
        std::cout<<"Current Angle: "<<getValue()<<endl;
    }


~TrigCalculator(){
    cout<<getValue()<<endl;
    cout<<"Destructor of the Calculator object is called."<<endl;
}
};





int main(){
    TrigCalculator calc(30.0f);
    calc.display();


calc.calculateSine();
calc.calculateCosine();
calc.calculateTangent();

calc.calculateForAngle(90.0f);
calc.display();


}