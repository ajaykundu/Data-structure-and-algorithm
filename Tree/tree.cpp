#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#define Max_height 1000
#define tn treenode
using namespace std;

struct trees
{
	int data;
	 struct trees* left;
	 struct trees* right;
};

typedef struct trees treenode;

treenode* create_new_node(int val,treenode* left=NULL,treenode* right=NULL)
{
	treenode* newnode=(treenode*)malloc(sizeof(treenode));
	newnode->data=val;
	newnode->left=left;
	newnode->right=right;
    return newnode;
}

void insertbst(treenode** rootref,int val)
{
	if((*rootref)==NULL)
	{
		treenode* newnode=create_new_node(val);
		*rootref=newnode;
		return;
	}
	if((*rootref)->data>val)
	{
		insertbst(&((*rootref)->left),val);
	}
	else if((*rootref)->data<val)
		insertbst(&((*rootref)->right),val);
  else if((*rootref)->data==val)
    return;
}

void printinorder(treenode* root)
{
	if(root==NULL)
	{
		return;
	}

	printinorder(root->left);
	cout<<root->data<<" ";
	printinorder(root->right);
 

}

treenode* treeminimum(treenode* root)
{
	if(root==NULL)
	{
		return root;
	}
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

treenode* treemaximum(treenode* root)
{
	if(root==NULL)
	{
		return root;
	}
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}

treenode* treesuccessor(treenode* root)
{
	if(root==NULL)
	{
		return root;
	}

	root=root->right;
	while(root->left!=NULL)
	{
		root=root->left;
	}

	return root;
}

void searchbyvalue(treenode* root,int search)
{
	if(root==NULL)
	{
		cout<<"the element is not present in the tree"<<endl;
		return;
	}
	if(root->data==search)
	{
		cout<<"yes this element is present in the tree"<<endl;
		return;
	}

	if(root->data>=search)
	{
		searchbyvalue(root->left,search);
	}
	else
		searchbyvalue(root->right,search);
}

int max(int a,int b)

{
    return a>b?a:b;
}

int findheigth(treenode* root)
{   
	if(root==NULL)
	{
		return 0;
	}
    int leftheigth=1+findheigth(root->left);
    int rightheigth=1+findheigth(root->right);
  // cout<<leftheigth<<" "<<rightheigth<<endl;
  return max(rightheigth,leftheigth);
}



int path[100];
void leafnode(treenode* root,int n=0)
{
	if(root==NULL)
	{    
		return ;
	}
	path[n]=root->data;

if((root->left)==NULL && (root->right)==NULL)
		{
		for(int i=0;i<=n;i++)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
	}

	leafnode(root->left,n+1);
	leafnode(root->right,n+1);
return;
}

int println(treenode* root)
{
	  
	// cout<<"in the println";
	  if(root==NULL)
	  {
	  	return 0;
	  }
	if((root->left)==NULL && root->right==NULL){
         return 1;
       }
  int lm,rm;

     lm=    println(root->left);
	 rm=println(root->right);
    	if(rm || lm )
    	{
    		cout<<root->data<<" ";
    		
    	}
  return 0;  
}


void leafnodes(treenode* root)
{
	if(root==NULL)
		return;
	if((root->left)==NULL && root->right==NULL){
         cout<<root->data<<" ";
         return;
       }

       leafnodes(root->left);
       leafnodes(root->right);
  
}




// void top_view(treenode* root){
// 	left_top_view(root);
// 	right_top_view(root->right);
// }

void level_order_newline(treenode* root)
{   //cout<<"hello "<<endl;
	if(root==NULL)
		return ;
    queue<treenode*> q;
  stack<treenode*> s;
    q.push(root);
    q.push(NULL);


    while(!q.empty())
    {
          root=q.front();
          
          q.pop();

          if(root!=NULL)
          {
         // s.push(root);	
          	   cout<<root->data<<" ";
          	   if(root->right!=NULL)
          	   	q.push(root->right);
          	   if(root->left!=NULL)
          	   	q.push(root->left);
          }
          else
          {
          //	cout<<"hello"<<endl;
   cout<<endl;
          	
             if(!q.empty())
             {
             	q.push(NULL);
             }
          }
    }
cout<<endl;
  // while(!s.empty())
  // {
  // 	cout<<(s.top())->data<<" ";
  //   s.pop();
  // }

  //  cout<<"hello "<<endl;

}


void levelorder_newline1(treenode* root)
{
  if(root==NULL)
    return;
  queue<treenode*> p,q;

  p.push(root);
   int level=1;
    int anslevel=0;
    int maxsum=root->data;

  while(!q.empty() || !p.empty())
  {   
    cout<<"Level: "<<level<<endl;
         int tempsum=0;
        while(!p.empty())
        {
             treenode* temp=p.front();
             p.pop();
             cout<<temp->data<<" ";
              tempsum=tempsum+temp->data;
             if(temp->left!=NULL)
             {
                 q.push(temp->left);
             }
             if(temp->right)
             {
              q.push(temp->right);
             }
        }

        if(tempsum>maxsum)
        {
          anslevel=level;
          maxsum=tempsum;
        }
        tempsum=0;
        level++;
        cout<<endl;
        cout<<"Level: "<<level<<endl;
         while(!q.empty())
        {
             treenode* temp=q.front();
             q.pop();
             cout<<temp->data<<" ";
           tempsum=tempsum+temp->data;

             if(temp->left!=NULL)
             {
                 p.push(temp->left);
             }
             if(temp->right)
             {
              p.push(temp->right);
             }
        }
   if(tempsum>maxsum)
   {
    anslevel=level;
    maxsum=tempsum;
   }
        level++;
        cout<<endl;

  }

  cout<<"max sum level:"<<anslevel<<endl;
  cout<<"max sum:"<<maxsum<<endl;
}

void deepestNode1(treenode* root)
{   //cout<<"hello "<<endl;
	
  queue<treenode*> q;
  treenode* deep;
  q.push(root);

  while(!q.empty() && root!=NULL)
  {
  	root=q.front();
    deep=root;
  	q.pop();
  	if(root->left!=NULL)
  		q.push(root->left);
  	if(root->right)
  	q.push(root->right);
  }

  cout<<deep->data<<endl;

}

void rootc(treenode* root,int count=0)
{
	if(root==NULL)
		return;
	cout<<count<<endl;
	rootc(root->left,count+1);
	rootc(root->right,count+1);
}

int find_Full_Nodes(treenode* root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL && root->right==NULL)
	{
		int left=find_Full_Nodes(root->left)+1;
		int right=find_Full_Nodes(root->right)+1;
		return left+right;
	}
	else
	{
       int left=find_Full_Nodes(root->left);
       int right=find_Full_Nodes(root->right);
       return left+right;
	}
}

int num_half_node(treenode* root)
{
	int count=0;
   queue<treenode*> q;
    if(root==NULL)
    	return count;
    q.push(root);

    while(!q.empty())
    {
    	root=q.front();
    	q.pop();
    	if((root->left!=NULL && root->right==NULL) || (root->left==NULL && root->right!=NULL) )
    	{
    		count++;
    	}
    	if(root->left!=NULL)
    		q.push(root->left);
    	if(root->right!=NULL)
    		q.push(root->right);

    }
return count;
}

int checkSameStrcuture(treenode* root1,treenode* root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
		return 0;
	if(root1->data==root2->data)
	{
		checkSameStrcuture(root1->left,root2->left);
		checkSameStrcuture(root1->right,root2->right);
	}
	else
	{
		return 0;
	}
}

void top_viewC(treenode* root,map<int,pair<int,int> > & m,int v,int level)
    {
    
    if(root==NULL)
        return ;
    if(m.find(v)!=m.end() && level< m[v].second)
        {
        m[v].first=root->data;
        m[v].second=level;
    }else if(m.find(v)==m.end())
    {
    	m[v].first=root->data;
    	m[v].second=level;
    }

    top_viewC(root->left,m,v-1,level+1);
    top_viewC(root->right,m,v+1,level+1);
}

void top_view(treenode * root)
{
 map<int,pair<int,int> > m;
    top_viewC(root,m,0,0);
  
    map<int,pair<int,int> >::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++)
        {
        cout<<(itr->second).first<<" ";
    }
}


void left_veiw(treenode* root)
{   //cout<<"hello "<<endl;
  if(root==NULL)
    return ;
    queue<treenode*> q;
 
    q.push(root);
    q.push(NULL);
    cout<<root->data<<" ";

    while(!q.empty())
    {
          root=q.front();
          
          q.pop();

          if(root!=NULL)
          {
         
              // cout<<root->data<<" ";
               if(root->left!=NULL)
                q.push(root->left);
               if(root->right!=NULL)
                q.push(root->right);
          }
          else
          {
          //  cout<<"hello"<<endl;
   //cout<<endl;
            
             if(!q.empty())
             {  

               cout<<(q.front())->data<<" ";
              q.push(NULL);
             }
          }
    }
   cout<<endl;
}


void top_viewCd(treenode* root,map<int,pair<int,int> > & m,int v,int level)
    {
    
    if(root==NULL)
        return ;
    if(m.find(v)!=m.end() && level> m[v].second)
        {
        m[v].first=root->data;
        m[v].second=level;
    }else if(m.find(v)==m.end())
    {
      m[v].first=root->data;
      m[v].second=level;
    }

    top_viewCd(root->left,m,v-1,level+1);
    top_viewCd(root->right,m,v+1,level+1);
}

void bo_view(treenode * root)
{
 map<int,pair<int,int> > m;
    top_viewCd(root,m,0,0);
  
    map<int,pair<int,int> >::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++)
        {
        cout<<(itr->second).first<<" ";
    }
}


void right_veiw(treenode* root)
{   //cout<<"hello "<<endl;
  if(root==NULL)
    return ;
    queue<treenode*> q;
 
    q.push(root);
    q.push(NULL);
    cout<<root->data<<" ";

    while(!q.empty())
    {
          root=q.front();
          
          q.pop();

          if(root!=NULL)
          {
         
              // cout<<root->data<<" ";
            if(root->right!=NULL)
                q.push(root->right);
               if(root->left!=NULL)
                q.push(root->left);
               
          }
          else
          {
          //  cout<<"hello"<<endl;
   //cout<<endl;
            
             if(!q.empty())
             {  

               cout<<(q.front())->data<<" ";
              q.push(NULL);
             }
          }
    }
   cout<<endl;
}

void right_veiwRAux(treenode* root,int level,int &maxlevel)
{
    if(root==NULL)
      return;
    if(level>maxlevel)
    {
      cout<<root->data<<" ";
      maxlevel=level;
    }
    right_veiwRAux(root->right,level+1,maxlevel);
    right_veiwRAux(root->left,level+1,maxlevel);
}

void right_veiwR(treenode* root)
{
  int maxlevel=0;
  right_veiwRAux(root,1,maxlevel);
}

int max1(int left,int right)
{
  return left>right?left:right;
}

int diameterTree(treenode* root,int * ptr)
{
  if(root!=NULL)
    return 0;
  int left,rig;
   left=diameterTree(root->left,ptr)+1;
   rig=diameterTree(root->right,ptr)+1;
   if(left+ rig >  *ptr)
    *ptr=left+rig;

  return max(left+rig,*ptr) +1;
}

int treeHeight(treenode *root)
{
  if(root==NULL)
  {
    return 0;
  }

int leftHeight=treeHeight(root->left)+1;
int rightHeight=treeHeight(root->right)+1;

return max(leftHeight,rightHeight);

}



int treeDiameterAux(treenode* root, int* height)

{
   
}

int treeDiameter(treenode* root)
{
  if(root==NULL)
    return 0;
  return treeDiameterAux(root,0);
}

void printpathutil(treenode* head,int v[],int level)
{
  if(head==NULL)
    return;
  v[level]=head->data;

  if(head->left==NULL && head->right==NULL)
  {
       for(int i=0;i<=level;i++)
       {
        cout<<v[i]<<"->";
       }
       cout<<endl;
  }
  printpathutil(head->left,v,level+1);
  printpathutil(head->right,v,level+1);
}


void printpath(treenode* head)
{
//  cout<<"hello"<<endl;
     int arr[5];

     printpathutil(head,arr,0);
}

void printpathrecurutil(treenode* root,int path[],int pathlen,int givensum)
{
    if(root==NULL)
      return;
    path[pathlen]=root->data;
    pathlen++;

    if(root->left==NULL && root->right==NULL)
    {
      int sum=0;
      for(int i=0;i<pathlen;i++)
      {
        cout<<path[i]<<"-";
        sum=sum+path[i];
      }

      cout<<endl;
      if(sum==givensum)
      {
        cout<<"yes"<<endl;
        return ;
      }
    }
    

    printpathrecurutil(root->left,path,pathlen,givensum);
    printpathrecurutil(root->right,path,pathlen,givensum);
}

void printpathrecur(treenode* root,int givensum)
{
     int arr[5];
     printpathrecurutil(root,arr,0,givensum);
}

bool hasPathSum(treenode* root,int sum)
{
      if(root==NULL)
        return sum==0;
      else
      {     int ans=0;
           int subsum=sum-root->data;
           cout<<root->data<<" ";
           if(subsum==0 && root->left==NULL && root->right==NULL)
            return 1;

          if(root->left!=NULL)
          {
               ans=ans || hasPathSum(root->left,subsum);
          }
          if(root->right!=NULL)
            ans=ans || hasPathSum(root->right,subsum);
          return ans;
      }
}

int sumTree(treenode* root)
{
  if(root==NULL)
    return 0;
  return root->data + sumTree(root->left) + sumTree(root->right);
}

int sumTreeL(treenode* root)
{
     if(root==NULL)
      return 0;

    queue<treenode*> q;
    q.push(root);
    int sum=0;
    while(!q.empty())
    {
          treenode* temp=q.front();
          q.pop();
          sum=sum+temp->data;
          if(temp->left!=NULL)
            q.push(temp->left);
          if(temp->right!=NULL)
            q.push(temp->right);
    }

   
    return sum;

}

treenode* MirrorBT(treenode* root)
{
  treenode* temp;
  if(root!=NULL)
  {
      MirrorBT(root->left);
      MirrorBT(root->right);
      temp=root->right;
      root->right=root->left;
      root->left=temp;

  }
  return root;

}

int checkingMirror(treenode* root1,treenode* root2)
{
      
}

// int leastCommonAnsterUtil(treenode* root,int a,int b,int &first,int &second)
// {
//      if(root==NULL)
//       return 0;
//     if(first==1 && second==1)
//       return root->data;
//     int ans=0;
//     ans=leastCommonAnsterUtil(root->left,a,b,first,second);
//     ans=leastCommonAnsterUtil(root->right,a,b,first,second);
    
//     if(root->data==a)
//       first=1;
//     if(root->data==b)
//       second=1;

//     return ans;
//  }

// int leastCommonAnster(treenode* root,int a,int b)
// {    
//     int ans=0;
//     int first=0;
//     int second=0;
//      ans= leastCommonAnsterUtil(root,a,b,first,second);
//      return ans;
// }

int findPathofNodeUtil(treenode* root,int val,int arr[],int level,int& length)
{
       if(root==NULL)
       {
          return 0;
       }

       arr[level]=root->data;
       if(root->data==val)
       {
         length=level;
        return 1;
       }
       int ans=0;
       level++;
       ans=ans || findPathofNodeUtil(root->left,val,arr,level,length);
       ans=ans || findPathofNodeUtil(root->right,val,arr,level,length);

       return ans;
}

void findPathofNode(treenode* root,int val)
{
     int height=treeHeight(root);

     int arr[height];
     int i=0;
      int length=0;
     findPathofNodeUtil(root,val,arr,i,length);
     cout<<i<<endl;
      for(int j=0;j<=length;j++)
      {
        cout<<arr[j]<<"-";
      }
      cout<<endl;
     //return arr;

}

// int heightUtil(treenode* root,int v,int level )
// {
//      if(root==NULL)
//       return 0;
//      if(root->data == v)
//       return level;
//     he

// }


// int height(treenode* root,int v)
// {
//     return heightUtil(root,v,1);
// }


treenode* findLCA(treenode* root,int n1,int n2)
{
     //this is for the base case.
  if(root==NULL) return NULL;

  if(root->data==n1) return root;
  if(root->data==n2) return root;

  treenode* left_lca=findLCA(root->left,n1,n2);
  treenode* right_lca=findLCA(root->right,n1,n2);
  if(left_lca!=NULL && right_lca!=NULL)
  {
    return root;
  }
  else
        if(left_lca!=NULL)
          return left_lca;
        else if(right_lca!=NULL)
        {
          return right_lca;
        }



}

treenode* predecessor(treenode* root)
{
   root=root->left;
   while(root->left!=NULL)
   {
    root=root->right;
   }
   return root;
}

void deleteNode(treenode** rootref,int val)
{
     if(*rootref==NULL)
      return;

    if((*rootref)->data > val)
    {
        deleteNode(&(*rootref)->left,val);
    }
    else if((*rootref)->data < val)
    {
        deleteNode(&(*rootref)->right,val);
    }
    else {
            if((*rootref)->left==NULL && (*rootref)->right==NULL)
            {
                  (*rootref)=NULL;   //case 1 : for leaf node.
            }
            else if((*rootref)->left!=NULL && (*rootref)->right==NULL)
            {
                  (*rootref)=(*rootref)->left; //case 2: for only left child.

            }
            else if((*rootref)->right!=NULL && (*rootref)->left==NULL)
            {
                 (*rootref)=(*rootref)->right;   //case 3: for only right child.
            }
            else 
            {                    // case 4 : have both the child.
                  treenode* newnode=predecessor(*rootref);
                  int newval=newnode->data;

                  (*rootref)->data=newnode->data;
                   deleteNode(&(*rootref)->left,newval);
                  
            }
    }
}

treenode* lcabst(treenode* root,int a,int b)
{    

       if(true){

       }
     if(root->data > a && root->data >b)
     {
         lcabst(root->left,a,b);
     }

     if(root->data<a && root->data <b)
     {
        lcabst(root->right,a,b);
     }

     
}

void  veticaltraversalutil(treenode* root,map<int,vector<pair<int,int> > > & m,int level,int verticaldec)
{
      if(root==NULL)
        return;

      m[verticaldec].push_back(make_pair(level,root->data));

      veticaltraversalutil(root->left,m,level+1,verticaldec-1);
      veticaltraversalutil(root->right,m,level+1,verticaldec+1);

}

vector<vector<int> > veticaltraversal(treenode* root)
{
     map<int,vector<pair<int,int> > > m;
     
      veticaltraversalutil(root,m,0,0);
      
      map<int,vector<pair<int,int> > >::iterator mitr;
      vector<vector<int> > v;

      for(mitr=m.begin();mitr!=m.end();mitr++)
      {
           vector<pair<int,int> >::iterator vitr;
          sort((mitr->second).begin(),(mitr->second).end());
           std::vector<int> temp;
           for(vitr=(mitr->second).begin();vitr!=(mitr->second).end();vitr++)
           {
                  temp.push_back(vitr->second);
                //  cout<<vitr->second<<" ";
           }
           //cout<<endl;
           v.push_back(temp);
      }

    return v;
}

int identicalTrees(treenode* root1,treenode* root2)
{
    if(root1==NULL && root2==NULL)
    {
      return 1;
    }else if(root1!=NULL && root2==NULL)
    {
      return 0;
    }else if(root1==NULL && root2!=NULL)
    {
      return 0;
    }
    if(root1->data==root2->data)
    {
      return (identicalTrees(root1->left,root2->left) && identicalTrees(root1->right,root2->right));
    }
    return 0;
}

void NodeOftreeFun(treenode* root,vector<treenode*> &NodeOftree)
{
    if(root==NULL)
      return;
    NodeOftree.push_back(root);
    NodeOftreeFun(root->left,NodeOftree);
    NodeOftreeFun(root->right,NodeOftree);
}

vector<treenode*> NumberOfduplicateSubtrees(treenode* root)
{
     std::vector<treenode*> NodeOftree;
  
     NodeOftreeFun(root,NodeOftree);
   vector<treenode*> Ansvector;

   for(int i=0;i<NodeOftree.size();i++)
   {
       for(int j=i+1;j<NodeOftree.size();j++)
       {
           if(identicalTrees(NodeOftree[i],NodeOftree[j]))
           {
               Ansvector.push_back(NodeOftree[i]);
           }
       }
   }

return NodeOftree;
}

void SerializationUtil(treenode* root,vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(root->data);
    SerializationUtil(root->left,v);
    SerializationUtil(root->right,v);
}

vector<int> Serialization(treenode* root)
{
  std::vector<int> v;
  SerializationUtil(root,v);

  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
  return v;
}

void KthfromRoot(treenode* root,int k)
{
      if(root==NULL)
        return;
      if(k==0)
      {
        cout<<root->data<<" ";
      }
     KthfromRoot(root->left,k-1);
      KthfromRoot(root->right,k-1);

}

int kthformNode(treenode* root,int target,int k)
{
  if(root==NULL)
    return -1;
  if(root->data==target)
  {
      KthfromRoot(root,k);
      return 0;
  }

  int dl=kthformNode(root->left,target,k);
  if(dl!=-1)
  {   //Ancestor itself at a given distance.
      if(1+dl==k)
        cout<<root->data<<" ";
      //if the node is present in right portion of tree from that anscestor.
      else
      {
        KthfromRoot(root->right,k-dl-2);
      }
      //increase value of dl by 1 because we are going more upward.
      return 1+dl;
  }

  int dr=kthformNode(root->right,target,k);
  //same as for left.
  if(dr!=-1)
  {
    if(1+dl==k){
      cout<<root->data<<" ";
    }
    else {
      KthfromRoot(root->left,k-dr-2);
    }
    return 1+dr;
  }
  return -1;
}

int min(int a,int b)
{
  return a>b?b:a;
}

void kDistanceFromLeafUtil(treenode* root,int path[],bool visited[],int pathlen,int k)
{
     if(root==NULL)
      return ;

    path[pathlen]=root->data;
    visited[pathlen]=false;
    pathlen++;
   
   if(root->left==NULL && root->right==NULL && pathlen-k-1>=0 && visited[pathlen-k-1]==false)
   {
       cout<<path[pathlen-k-1]<<" ";
       visited[pathlen-k-1]=true;
       return; 
   }

   kDistanceFromLeafUtil(root->left,path,visited,pathlen,k);
   kDistanceFromLeafUtil(root->right,path,visited,pathlen,k);
}

void kDistanceFromLeaf(treenode* root,int k)
{
   int path[Max_height];
   bool visited[Max_height]={false};
   kDistanceFromLeafUtil(root,path,visited,0,k);
}



int main(int argc, char const *argv[])
{
	/* code */

	treenode* root=NULL;
  treenode* root2=NULL;
     insertbst(&root,13);
     insertbst(&root,10);
     insertbst(&root,11);
     insertbst(&root,8);
     insertbst(&root,14);
     insertbst(&root,16);
     insertbst(&root,17);
     //insertbst(&root,15);
     insertbst(&root,12);
    
     kDistanceFromLeaf(root,2);
      insertbst(&root2,13);
     insertbst(&root2,10);
     insertbst(&root2,11);
     insertbst(&root2,8);
     insertbst(&root2,14);
     insertbst(&root2,16);
     insertbst(&root2,17);

	return 0;
}


