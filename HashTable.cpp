#include<iostream>
#include<vector>

using namespace std;

template <typename T>

class hashNode{
    public:
        T value;
        int key;

        hashNode(T value, int key){
            this->value = value;
            this->key = key;
        }
};

template <typename T>

class hashTable{
    private:
        int cap;
        int size;
        vector<vector<hashNode<T>>> hashVect;
        hashNode<T> *dum;
        int Hash(int key){
            return key % cap;
        }

    public:
        hashTable(){
            cap = 10;
            size = 0;
            hashVect = new hashNode<T>*[cap];
            for(int i = 0; i < cap; i++){
                hashVect[i] = NULL;
            }
            dum = new hashNode<T>(-1,-1);
        }

        int hashSize(){
            return size;
        }

        bool hashEmpty(){
            return size == 0;
        }

        T hashFind(int key){
            int hashInd = Hash(key);
            int runs=0;
            while(hashVect[hashInd] != NULL){
                runs = 0;
                if(runs++>cap){
                    return NULL;
                }
                if(hashVect[hashInd]->key == key){
                    return hashVect[hashInd]-> value;
                }
                hashInd++;
                hashInd %= cap;
            }

        }

        T hashErase(int key){
            int hashInd = Hash(key);
            while(hashVect[hashInd] != NULL){
                if(hashVect[hashInd]->key == key){
                    hashNode<T> *temp = hashVect[hashInd];
                    hashVect[hashInd] = dum;
                    size--;
                    return temp->value;
                }
                hashInd++;
                hashInd %= cap;
            }
            return NULL;
        }

        void hashInsert(int key, T element){
            hashNode<T> *temp = new hashNode<T>(element, key);
            int hashInd = Hash(key);
            while(hashVect[hashInd] != NULL && hashVect[hashInd]->key != key && hashVect[hashInd]->key != -1){
                hashInd++;
                hashInd %= cap;
            }
            if(hashVect[hashInd] == NULL || hashVect[hashInd] == -1){
                size++;
            }
            hashVect[hashInd] = temp;
        }
    hashNode<T>& operator[] (int index){
        return hashVect[index];
    }
};


int main(){
    return 0;
}

