#include "Construct.h"

Construct::Construct():age(0),name(NULL) {

}

Construct::Construct(const Construct &construct) {
    if(construct.name){
        name = new string(*construct.name);
        age  = construct.age;
    }
}
Construct::Construct(int n, const string &str):age(n),name(new string(str)) {
    cout << "init construct " << endl;
}

Construct::~Construct() {
    if(name){
        cout << "~Construct" << "name:" << *name << "age:" << age << endl;
    }
    delete name;
}



