#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename T> T Sqr(T x);
template <typename First, typename Second> pair<First, Second> operator * (const pair<First, Second>& f, const pair<First, Second>& f2);
template <typename Key, typename Value> map<Key, Value>operator * (const map<Key, Value>& m, const map<Key, Value>& m2);
template<typename Element> vector<Element> operator * (const vector<Element>& v, const vector<Element>& v2);

//we need this first calling of typenames to work of all our code


//PAIR
template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& f, const pair<First, Second>& f2) {
    First f1 = f.first*f2.first;
    Second s1 = f.second * f2.second;
    return make_pair(f1, s1);
}

//MAP
template <typename Key, typename Value>
map<Key, Value>operator * (const map<Key, Value>& m,const map<Key, Value>& m2) {
    map<Key, Value> rez;                          //make a result map
    for (const auto& w : m) {
        auto second_value = m2.at(w.first);
        rez[w.first] = w.second * second_value;   //in this exercise in map we need to make a square only by VALUES
    } 
    return rez;
}

//VECTOR
template<typename Element>
vector<Element> operator * (const vector<Element>& v, const vector<Element>& v2) {
    vector <Element> rez;                         //make a result vector
    int pe = v.size();                            //we need int like type to work in 'for'
    for (int i = 0; i < pe; ++i) {
        rez.push_back(v[i] * v2[i]);
    }
    return rez;
}

//SQR function
template<typename T>
T Sqr(T x) {
    return x * x;                          //square is a multiplication of number with this number
}

int main() {
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}