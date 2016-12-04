// this program has many issues but not errors.
// for details: http://codereview.stackexchange.com/questions/14498/implementation-of-hash-map

#include <list>
#include <iostream>
using namespace std;

const int SIZE = 10;

class Node{
public:
    Node(){}
    Node(int k, int v):key(k), value(v){}
    int key, value;
};

class HashMap {
private:
    list<Node*> data[SIZE];

public:
    ~HashMap();
    Node* get(int key);
    void put(int key, int value);

    int hashFn(int val){ return val % 13; }
};

Node* HashMap::get(int key){
    int hashValue = hashFn(key);
    int bucket = hashValue % SIZE;
    list<Node*>::iterator it = data[bucket].begin();

    while(it != data[bucket].end()){

        Node ** d = &(*it); 
        if((*d)->key == key){
            return *d;
        }

        it++;
    }
    return NULL;
}

void HashMap::put(int key, int value){
    int hashValue = hashFn(key);
    int bucket = hashValue % SIZE;
    Node* node = this->get(key);
    if(node == NULL){
        data[bucket].push_front(new Node(key, value));
    }
    else{
        node->value = value;
    }
}

HashMap::~HashMap(){
    for(int i = 0; i < SIZE; ++i){
        list<Node*>& val = data[i];
        for(list<Node*>::iterator it = val.begin(); it != val.end(); it++){
            Node* n = *it;
            delete n;
        }
    }
}

int main(){
    HashMap map;
    cout << "Finding 5: " << map.get(5) << endl;  // -1
    map.put(5, 10);
    map.put(5, 11);
    cout << "Finding 5: " << map.get(5)->value;  // 11
    return 1;
}