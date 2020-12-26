#include<string>
using namespace std;

template <typename V>
class MapNode {
  public:
	string key;
	V value;
	MapNode *next;

	MapNode(string key, V value){
		this->key = key;
		this->value = value;
		next = NULL;
	}

	~MapNode(){
		delete next;
	}
}; 

template <typename V>
class OurMap{
	MapNode<V>** bucket;
	int size;
	int numBuckets;
	
	int getHashIndex(string key){
		int base = 37;

		int hashCode = 0;
		int coeff = 1;
		for(int i = key.length() -1; i >= 0; i--){
			hashCode += key[i]*coeff;
			hashCode = hashCode % numBuckets;
			coeff *= base;
			coeff = coeff % numBuckets;
		}
		return hashCode % numBuckets;
	}

	void rehash(){
		MapNode<V>** temp = bucket;
		MapNode<V>** bucket = new MapNode<V>*[numBuckets*2];
		for(int i=0; i < 2*numBuckets; i++){
			bucket[i] = NULL;
		}
		int prevBucketSize = numBuckets;
		numBuckets = 2*numBuckets;

		for(int i=0; i < prevBucketSize; i++){
			MapNode<V>* head = temp[i];
			while(head != NULL){
				string key = head->key;
				V value = head -> value;
				insert(key, value);
				head = head -> next;
			}
		}

		for(int i=0; i < prevBucketSize; i++){
			MapNode<V>* head = temp[i];
			delete head;
		}
		delete [] temp;
	}

	public:
	OurMap(){
		size = 0;
		numBuckets = 5;
		bucket = new MapNode<V>*[numBuckets];
		for(int i=0; i < numBuckets; i++){
			bucket[i] = NULL;
		} 
	}

	~OurMap(){
		for(int i=0; i < numBuckets; i++){
			delete bucket[i];
		}

		delete [] bucket;
	}

	int getSize(){
		return this->size;
	}

	void insert(string key, V value){
		int hashIndex = getHashIndex(key);
		MapNode<V>* indexHead = bucket[hashIndex];
		while(indexHead != NULL){
			if(indexHead->key == key){
				indexHead -> value = value;
				return;
			}
			indexHead = indexHead -> next;
		}
		indexHead = bucket[hashIndex];
		MapNode<V>* node = new MapNode<V>(key, value);
		node -> next = indexHead;
		indexHead = node;
		bucket[hashIndex] = node;
		size++;
		double loadFactor = size*1.0/numBuckets;
		if(loadFactor > 0.75){
			rehash();
		}
	}

	V getValue(string key){
		int hashIndex = getHashIndex(key);
		MapNode<V>* indexHead = bucket[hashIndex];
		while(indexHead != NULL){
			if(indexHead -> key == key){
				return indexHead -> value;
			}
			indexHead = indexHead -> next;
		}
		return 0;
	}

	V removeKey(string key){
		int hashIndex = getHashIndex(key);
		MapNode<V>* indexHead = bucket[hashIndex];
		MapNode<V>* prev = NULL;
		while(indexHead != NULL){
			if(indexHead -> key == key){
				if(prev == NULL){
					bucket[hashIndex] = indexHead -> next;
				}
				else{
					prev->next = indexHead->next;
				}

				V value = indexHead->value;
				indexHead -> next = NULL;
				delete indexHead;
				size--;
				return value;

			}
			prev = indexHead;
			indexHead = indexHead -> next;
		}
		return 0;
	}
};

