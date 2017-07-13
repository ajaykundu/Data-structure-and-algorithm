#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    vector<vector<int> > graph;
    int n;
    vector<int> color;
    int colored;
public: 
	Graph(int size){
      n=size;
      graph.resize(n);
      for(int i=0;i<n;i++)
      {
      	graph[i].resize(n);
      }
      color.resize(n);
	}

	void addBiEdge(int src,int dest)
	{
		graph[src][dest]=1;
		graph[dest][src]=1;
	}

    void printGraph()
    {
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cout<<graph[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    }
    bool colorGraphUtil(int v,int colorToassign,int totalcolor)
    {
    	  for(int i=0;i<n;i++)
    	  {
    	  	  if(graph[v][i]==1 && color[i]==colorToassign)
    	  	  {
    	  	  	return false;
    	  	  }
    	  }

    	  color[v]=colorToassign;
    	  colored--;

    	  if(colored==0)
    	  	return true;

    	  for(int i=0;i<n;i++)
    	  {
    	  	   if(graph[v][i]==1)
    	  	   {
    	  	   	   for(int newc=1;newc<=totalcolor;newc++)
    	  	   	   {
    	  	   	   	   if(color[i]==0 && colorGraphUtil(i,newc,totalcolor))
    	  	   	   	   	return true;
    	  	   	   }
    	  	   }
    	  }
    	  colored++;
    	  color[v]=0;
    	  return false;

    }

    bool colorGraph(int totalcolor)
{
    fill(color.begin(),color.end(),0);

    colored=n;

    if(colorGraphUtil(0,1,totalcolor))
    {
    	for(int i=0;i<n;i++)
    	{
    		cout<<color[i]<<" ";
    	}
    	cout<<endl;
    	return true;
    }
    return false;
}


};



int main(int argc, char const *argv[])
{
Graph g1(4);

g1.addBiEdge(0,1);

g1.addBiEdge(0,2);

g1.addBiEdge(0,3);

g1.addBiEdge(1,2);

g1.addBiEdge(2,3);

if(g1.colorGraph(3) == false)
cout<<"Coloring not possible";
	return 0;
}