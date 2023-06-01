// rewritten from example https://www.youtube.com/watch?v=UNvCuYQCXAI

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Function that adds string to vector
vector<string> TestFunction(int len){
    vector<string> v;
    v.reserve(1000);
    for(int i = 0; i < 1000; i++){
        string str(len,'x');
        v.push_back(str);
    }
    return v;
}

// make a vector with 1000 elements, each element a string of length 20
int main(){
    int len = 20;
    vector<string> v = TestFunction(len);
    cout << "First element in vector = " << v[0] << "Last element in vector = " << v[999] << endl;

    return 0;
}