#include <iostream>
struct WrongAgeExceptions {
    int age;
};
int RealAge() {
    std::cin.exceptions(std::istream::failbit);
    int age;
    std::cin>> age;
    if(age<0 || age>=128) {
        throw WrongAgeExceptions(age);
       // return -1;
    }
    return age;
}
int main() {
    try {
        int age= RealAge();
    }catch(const WrongAgeExceptions& ex) {
        std::cerr<< "Age is not correct:"<<ex.age<<"\n";
        return 1;
    }catch(const std::istream::failure& ex) {
        std::cerr<<"Failed to read stream:"<<ex.what()<<"\n";
        return 1;
    }catch(...) {
        std::cout<<"Unknow exceptions\n";
        return 1;
    }
      std::cout<<"real\n";

   /* if(int age = RealAge(); age == -1) {
        std::cout<< "not real\n";
    }else {
        std::cout<<"real\n";
    }
    return 0;*/
}
