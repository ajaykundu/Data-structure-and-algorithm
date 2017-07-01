#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std; 

class Graph{
   private: 
   	vector<vector<int> > graph;
   	int n;  //number of nodes in graph.
   	std::vector<int> visit;
   	void dfsitrAux(int i);
   	void dfsrecAux(int i);
   	void topoSortAux(int i,stack<int> &topostack);// this function is called by toposort.
   	int detectcycleAux(int v,std::vector<int> & currstack);
   public:
   	Graph(int i)
   	{
   		n=i;
   		graph.resize(i);  
   		visit.resize(i);
   	}

   	void addEdge(int s,int d)
   	{
   		graph[s].push_back(d);
   	}
    
    void bfs(); //iterative breadth first search.
    void dfsitr(); //iterative depth fist search.
    void dfsrec();// depth first search using recursion.
    void topoSort();//this function will help in topological sorting.
    void clearVisit();// it will set all values of visit to false.
    int detectcycle();//this function detect the cycle in loop.
};

void Graph::bfs()
{
	queue<int> q;
	fill(visit.begin(),visit.end(),0);

	for(int i=0;i<n;i++)
	{
		if(visit[i]==false)
		{
			visit[i]=true;
			q.push(i);

			while(!q.empty())
			{
				int v=q.front();
				q.pop();
				cout<<v<<" ";

				for(vector<int>::iterator itr=graph[v].begin();itr!=graph[v].end();itr++)
				{
					if(visit[*itr]==false)
					{
						visit[*itr]=true;
						q.push(*itr);
					}
				}
			}
		}
	}
}

void Graph::dfsitrAux(int i)
{
	stack<int> s;
	s.push(i);
	
	while(!s.empty())
	{
		int v=s.top();
		s.pop();

		if(visit[v]==true)
			continue;
		cout<<v<<" ";
		visit[v]=true;

		for(int tu=0;tu<graph[v].size();tu++)
		{
			if(visit[graph[v][tu]]==false)
			{
				s.push(graph[v][tu]);
			}
		}
	}
}

void Graph::dfsitr()
{
	fill(visit.begin(),visit.end(),0);
	for(int i=0;i<n;i++)
	{
		if(visit[i]==false)
		{
			dfsitrAux(i);
		}
	}
}

void Graph::dfsrec()
{
	fill(visit.begin(),visit.end(),0);
	for(int i=0;i<n;i++)
	{
		if(visit[i]==false)
		{
			dfsrecAux(i);
		}
	}
}

void Graph::dfsrecAux(int i)
{
	visit[i]=true;
	cout<<i<<" ";
	for(int tu=0;tu<graph[i].size();tu++)
	{
		if(visit[graph[i][tu]]==false)
		{
			dfsrecAux(graph[i][tu]);
		}
	}
}

void Graph::clearVisit()
{
	std::fill(visit.begin(),visit.end(),0);
}

void Graph::topoSort()
{
    clearVisit();
	stack<int> topostack;// using stack template for storing topological sorting of stack.
    for(int i=0;i<n;i++)
    {  
    	if(visit[i]==false)
     	topoSortAux(i,topostack);
    }
    while(!topostack.empty())
    {
    	cout<<topostack.top()<<" ";
    	topostack.pop();
    }
}

void Graph::topoSortAux(int i,stack<int> & topostack)
{
	visit[i]=true;
	for(vector<int>::iterator itr=graph[i].begin();itr!=graph[i].end();itr++)
	{
		if(visit[*itr]==false)
		{
			topoSortAux(*itr,topostack);
		}
	}
    topostack.push(i);
}

int Graph::detectcycle()
{
	clearVisit();
	std::vector<int> currstack(n);
	fill(currstack.begin(),currstack.end(),0);
    
	for(int i=0;i<n;i++)
	{
        if(visit[i]==false)
         {
         	if(detectcycleAux(i,currstack))
         	return 1;
         }
	}
	return 0;
}

int Graph::detectcycleAux(int v,std::vector<int> &currstack)
{
      visit[v]=true;
      currstack[v]=true;
      for(std::vector<int>::iterator itr=graph[v].begin();itr!=graph[v].end();itr++)
      {
      	   if(visit[*itr]==true && currstack[*itr]==true)
      	   {
      	   	return 1;
      	   }
      	   else if(visit[*itr]==false)
      	   {
      	   	  if(detectcycleAux(*itr,currstack))
      	   	  	return 1;
      	   	  	
      	   }
      }
      currstack[v]=false;
      return 0;
}

int main(int argc, char const *argv[])
{
	Graph obj(8);
	obj.addEdge(0,1);
	obj.addEdge(0,2);
	obj.addEdge(1,3);
	obj.addEdge(1,4);
	obj.addEdge(2,5);
	obj.addEdge(4,6);
	obj.addEdge(4,7);

	cout<<"iterative bfs :";
	obj.bfs();
    cout<<endl<<"iterative dfs: ";
    obj.dfsitr();
    cout<<endl<<"recursive solution: ";
    obj.dfsrec();
    cout<<endl<<"topological Sort: ";
    obj.topoSort();

    Graph obj2(6);
    obj2.addEdge(3,1);
    obj2.addEdge(4,1);
    obj2.addEdge(4,0);
    obj2.addEdge(2,3);
    obj2.addEdge(5,2);
    obj2.addEdge(5,0);
    obj2.addEdge(1,2);
    cout<<endl<<"Graph 2 topological Sorting: ";
    obj2.topoSort();
    cout<<endl<<"detet cycle in first graph: ";
   cout<<obj.detectcycle();
    cout<<endl<<"detect cycle in second graph: ";
    cout<<obj2.detectcycle();


	return 0;
}