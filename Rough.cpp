#include<bits/stdc++.h>

using namespace std;
  
  
  class Person{
            public:
                float age;
                int num;
                string name;
            bool operator < (const Person& rhs) const { return age < rhs.age ;}
            bool operator > (const Person& rhs) const { return age > rhs.age ;}

            // bool comparator(Person a, Person b){
            //     if(a.age < b.age) return true;
            //     if(a.age > b.age) return false;
            //     if(a.num > b.num) return true;
            //     if(a.num < b.num) return false;    
            // }
        };

// bool comparator(Person a, Person b){
//     if(a.age < b.age) return true;
//     if(a.age > b.age) return false;
//     if(a.num > b.num) return true;
//     if(a.num < b.num) return false;    
// }

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}


class A {
    public:
    int x;
    A(int x=0): x{x} {cout<<"Construct" <<endl;};
    A(const A& rhs) { x= rhs.x; cout<<"Copy" <<endl; }

};

bool operator < (const A& lhs, const A& rhs){
    return lhs.x < rhs.x;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<A> Set;
    A a(10);
    Set.insert(a);
  //  Set.emplace(2);
    return 0;

    // multiset<Person,comparator> Mset = {{30,40,"Piyush"}, {30,41,"Amit"}, {24,50,"Himanshu"}};

    // for(const auto& e: Mset){
    //     cout<<e.age<<" "<<e.num<<" "<<e.name<<endl;
    // }

   
}