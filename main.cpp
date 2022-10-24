#include <iostream>
#include <assert.h>
using namespace std;

/*
* Calculate BMI
* @param weight in kg
* @param height in m
*/
float bmi(float weight, float height) {
    // weight and height are positive
    // weight smaller than heaviest person
    // height smaller than tallest person
    if (weight <=0 || height <= 0 || weight > 700 || height > 3) {
        return -1;
    }
    return weight / (height * height);
}

//Category of BMI
string bmi_category(float bmi) {
    if (bmi < 0) {
        return "Invalid";
    }
    if (bmi < 18.5) { 
        return "Underweight";
    } else if (bmi < 25.0) {
        return "Normal";
    } else if (bmi < 30.0) {
        return "Overweight";
    } else{
        return "Obese";
    }
}

int main(){
    //Test cases
    //Kiem thu gia tri bien
    assert(bmi_category(bmi(0, 1.5)) == "Invalid");
    assert(bmi_category(bmi(0.1, 1.5)) == "Underweight");
    assert(bmi_category(bmi(300, 1.5)) == "Obese");
    assert(bmi_category(bmi(699.5, 1.5)) == "Obese");
    assert(bmi_category(bmi(700, 1.5)) == "Obese");
    assert(bmi_category(bmi(700.1, 1.5)) == "Invalid");

    assert(bmi_category(bmi(300, 0)) == "Invalid");
    assert(bmi_category(bmi(300, 0.1)) == "Obese");
    assert(bmi_category(bmi(300, 2.9)) == "Obese");
    assert(bmi_category(bmi(300, 3)) == "Obese");
    assert(bmi_category(bmi(300, 3.1)) == "Invalid");

    //Kiem thu phan hoach tuong duong
    assert(bmi_category(bmi(300, 1.5)) == "Obese");
    assert(bmi_category(5) == "Underweight");
    assert(bmi_category(20) == "Normal");
    assert(bmi_category(27) == "Overweight");
    assert(bmi_category(50) == "Obese");

    //Kiem thu hop trang, control flow phu cap 2
    assert(bmi_category(bmi(-1, 2)) == "Invalid");
    assert(bmi_category(bmi(45, 1.8)) == "Underweight");
    assert(bmi_category(bmi(60, 1.7)) == "Normal");
    assert(bmi_category(bmi(70, 1.6)) == "Overweight");
    assert(bmi_category(bmi(100, 1.6)) == "Obese");

    //Kiem thu hop trang, data flow all-c-some-p
    assert(bmi_category(bmi(45, 1.8)) == "Underweight");
    assert(bmi_category(bmi(-1, 2)) == "Invalid");

    //Program
    float weight, height;
    cout << "Enter weight (kg): ";
    cin >> weight;
    cout << "Enter height (m): ";
    cin >> height;

    float bmi_value = bmi(weight, height);
    string category = bmi_category(bmi_value);
    
    cout << "BMI: " << bmi_value << endl;
    cout<< "Category: " << category << endl;

    return 0;
}