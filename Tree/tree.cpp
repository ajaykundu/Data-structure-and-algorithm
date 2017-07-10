#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct trees
{
	int data;
	 struct trees* left;
	 struct trees* rigth;
};

typedef struct trees treenode;

treenode* create_new_node(int val,treenode* left=NULL,treenode* rigth=NULL)
{
	treenode* newnode=(treenode*)malloc(sizeof(treenode));
	newnode->data=val;
	newnode->left=left;
	newnode->rigth=rigth;
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
		insertbst(&((*rootref)->rigth),val);
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
	printinorder(root->rigth);
 

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
	while(root->rigth!=NULL)
	{
		root=root->rigth;
	}
	return root;
}

treenode* treesuccessor(treenode* root)
{
	if(root==NULL)
	{
		return root;
	}

	root=root->rigth;
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
		searchbyvalue(root->rigth,search);
}

int findheigth(treenode* root)
{   
	if(root==NULL)
	{
		return 0;
	}
    int leftheigth=1+findheigth(root->left);

    int rigthheigth=1+findheigth(root->rigth);
  return max(rigthheigth,leftheigth);
}

int max(int a,int b)

{
	if(a>=b)
	{
		return a;
	}
	return b;
}

int path[100];
void leafnode(treenode* root,int n=0)
{
	if(root==NULL)
	{    
		return ;
	}
	path[n]=root->data;

if((root->left)==NULL && (root->rigth)==NULL)
		{
		for(int i=0;i<=n;i++)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
	}

	leafnode(root->left,n+1);
	leafnode(root->rigth,n+1);
return;
}

int println(treenode* root)
{
	  
	// cout<<"in the println";
	  if(root==NULL)
	  {
	  	return 0;
	  }
	if((root->left)==NULL && root->rigth==NULL){
         return 1;
       }
  int lm,rm;

     lm=    println(root->left);
	 rm=println(root->rigth);
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
	if((root->left)==NULL && root->rigth==NULL){
         cout<<root->data<<" ";
         return;
       }

       leafnodes(root->left);
       leafnodes(root->rigth);
  
}




// void top_view(treenode* root){
// 	left_top_view(root);
// 	rigth_top_view(root->rigth);
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
          	   if(root->rigth!=NULL)
          	   	q.push(root->rigth);
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
             if(temp->rigth)
             {
              q.push(temp->rigth);
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
             if(temp->rigth)
             {
              p.push(temp->rigth);
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
  	if(root->rigth)
  	q.push(root->rigth);
  }

  cout<<deep->data<<endl;

}

void rootc(treenode* root,int count=0)
{
	if(root==NULL)
		return;
	cout<<count<<endl;
	rootc(root->left,count+1);
	rootc(root->rigth,count+1);
}

int find_Full_Nodes(treenode* root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL && root->rigth==NULL)
	{
		int left=find_Full_Nodes(root->left)+1;
		int rigth=find_Full_Nodes(root->rigth)+1;
		return left+rigth;
	}
	else
	{
       int left=find_Full_Nodes(root->left);
       int rigth=find_Full_Nodes(root->rigth);
       return left+rigth;
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
    	if((root->left!=NULL && root->rigth==NULL) || (root->left==NULL && root->rigth!=NULL) )
    	{
    		count++;
    	}
    	if(root->left!=NULL)
    		q.push(root->left);
    	if(root->rigth!=NULL)
    		q.push(root->rigth);

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
		checkSameStrcuture(root1->rigth,root2->rigth);
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
    top_viewC(root->rigth,m,v+1,level+1);
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
               if(root->rigth!=NULL)
                q.push(root->rigth);
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
    top_viewCd(root->rigth,m,v+1,level+1);
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


void rigth_veiw(treenode* root)
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
            if(root->rigth!=NULL)
                q.push(root->rigth);
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

void rigth_veiwRAux(treenode* root,int level,int &maxlevel)
{
    if(root==NULL)
      return;
    if(level>maxlevel)
    {
      cout<<root->data<<" ";
      maxlevel=level;
    }
    rigth_veiwRAux(root->rigth,level+1,maxlevel);
    rigth_veiwRAux(root->left,level+1,maxlevel);
}

void rigth_veiwR(treenode* root)
{
  int maxlevel=0;
  rigth_veiwRAux(root,1,maxlevel);
}

int max1(int left,int rigth)
{
  return left>rigth?left:rigth;
}

int diameterTree(treenode* root,int * ptr)
{
  if(root!=NULL)
    return 0;
  int left,rig;
   left=diameterTree(root->left,ptr)+1;
   rig=diameterTree(root->rigth,ptr)+1;
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
int rigthHeight=treeHeight(root->rigth)+1;

return max(leftHeight,rigthHeight);

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

  if(head->left==NULL && head->rigth==NULL)
  {
       for(int i=0;i<=level;i++)
       {
        cout<<v[i]<<"->";
       }
       cout<<endl;
  }
  printpathutil(head->left,v,level+1);
  printpathutil(head->rigth,v,level+1);
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

    if(root->left==NULL && root->rigth==NULL)
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
    printpathrecurutil(root->rigth,path,pathlen,givensum);
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
           if(subsum==0 && root->left==NULL && root->rigth==NULL)
            return 1;

          if(root->left!=NULL)
          {
               ans=ans || hasPathSum(root->left,subsum);
          }
          if(root->rigth!=NULL)
            ans=ans || hasPathSum(root->rigth,subsum);
          return ans;
      }
}

int sumTree(treenode* root)
{
  if(root==NULL)
    return 0;
  return root->data + sumTree(root->left) + sumTree(root->rigth);
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
          if(temp->rigth!=NULL)
            q.push(temp->rigth);
    }

   
    return sum;

}

treenode* MirrorBT(treenode* root)
{
  treenode* temp;
  if(root!=NULL)
  {
      MirrorBT(root->left);
      MirrorBT(root->rigth);
      temp=root->rigth;
      root->rigth=root->left;
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
//     ans=leastCommonAnsterUtil(root->rigth,a,b,first,second);
    
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
       ans=ans || findPathofNodeUtil(root->rigth,val,arr,level,length);

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
  treenode* right_lca=findLCA(root->rigth,n1,n2);
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
    root=root->rigth;
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
        deleteNode(&(*rootref)->rigth,val);
    }
    else {
            if((*rootref)->left==NULL && (*rootref)->rigth==NULL)
            {
                  (*rootref)=NULL;   //case 1 : for leaf node.
            }
            else if((*rootref)->left!=NULL && (*rootref)->rigth==NULL)
            {
                  (*rootref)=(*rootref)->left; //case 2: for only left child.

            }
            else if((*rootref)->rigth!=NULL && (*rootref)->left==NULL)
            {
                 (*rootref)=(*rootref)->rigth;   //case 3: for only rigth child.
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
        lcabst(root->rigth,a,b);
     }

     
}

void  veticaltraversalutil(treenode* root,map<int,vector<pair<int,int> > > & m,int level,int verticaldec)
{
      if(root==NULL)
        return;

      m[verticaldec].push_back(make_pair(level,root->data));

      veticaltraversalutil(root->left,m,level+1,verticaldec-1);
      veticaltraversalutil(root->rigth,m,level+1,verticaldec+1);

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
     insertbst(&root,18);
    

      insertbst(&root2,13);
     insertbst(&root2,10);
     insertbst(&root2,11);
     insertbst(&root2,8);
     insertbst(&root2,14);
     insertbst(&root2,16);
     insertbst(&root2,17);

    vector<std::vector<int> > v;
    v=veticaltraversal(root);
     

   
	return 0;
}

