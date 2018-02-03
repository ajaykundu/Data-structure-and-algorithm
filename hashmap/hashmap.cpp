#include <iostream>
#include <string>
using namespace std;

template<typename V>

class Mapnode{
  
    public:
		string key;
		V value;
		Mapnode* next;
		
		Mapnode(string key,V value)
		{
			this->key = key;
			this->value = value;
			next = NULL;
		}
		
		~Mapnode()
		{
			delete next;
		}
		
		
};

template<typename V>
class ourmap
{
	Mapnode<V>** buckets;
	int count;
	int numbuckets;
	
	int gethashindex(string key)
	{
		int hashindex = 0;
		int hashcofficient = 1;
		for(int i=key.length()-1;i>=0;i++)
		{
			hashindex+= hashcofficient*key[i];
			hashindex = hashindex%numbuckets;
			hashcofficient *= 37;
			hashcofficient = hashcofficient % numbuckets;
		}
		return hashindex % numbuckets;
	}
	
public:
	ourmap(){
		count = 0;
		numbuckets = 5;
		Mapnode<V>* buckets = new Mapnode<V>*[numbuckets];
		for(int i=0;i<n;i++)
		{
			buckets[i]=NULL;
		}
	}
	
	~ourmap(){
		for(int i=0;i<numbuckets;i++)
		{
			delete buckets[i];
		}
		delete [] buckets;
	}
	
	int size()
	{
		return count;
	}
	
	
	void insert(string key,V value)
	{
		int hashindex = gethashindex(key);
		
		Mapnode<V>* head = buckets[hashindex];
		
		while(head!= NULL)
		{
			if(head->key == key)
			{
				head->value = value;
				return;
			}
			head = head -> next;
			
		}
		head = buckets[hashindex];
		Mapnode<V> * newnode = new Mapnode<V>(key,value);
		newnode->next = head ;
		buckets[hashindex] = newnode;
		count++;	
	}
	//remove a key from hashmap.
	
	V remove(string key)
	{
		int hashindex = gethashindex(key);
		
		Mapnode<V> * head = buckets[hashindex];
	
		Mapnode<V>* prev = NULL;
		while(head!=NULL)
		{
			if(head->key == key)
			{
				if(prev ==NULL)
				{
					buckets[hashindex] = head ->next;
				}
				else {
					prev ->next = head ->next;
				}
				
				V retval = head -> value;
				head->next = NULL;
				delete V;
				count--;
				return retval;
			}
			prev = head;
			head = head -> next;
		}
		return 0;
	}
	
	V getValue(string key)
	{
		int hashindex = gethashindex(key);
		Mapnode<V>* head = buckets[hashindex];
		
		while(head!=NULL)
		{
			if(head -> key ==key)
			{
				return head -> value;
			}
			head = head -> next;
		}
		return 0;
	}
	
};

