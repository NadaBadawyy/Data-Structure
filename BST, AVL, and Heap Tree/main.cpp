#include <iostream>
#include <vector>

using namespace std;
template<typename t>
class node{
public:
    t data;
    node*left;
    node*right;
    node(){
      left= nullptr;
      right= nullptr;
    }
    node(t val){
        data=val;
        left= nullptr;
        right= nullptr;
    }

};
template<typename t>
class BST{
  node<t>*root;
  void addhelper(node<t>*x, t val){
      node<t> *newnode = new node(val);
      if(val<=x->data){
          if(x->left== nullptr)
              x->left=newnode;
          else
              addhelper(x->left, val);
      }
      else if(val>x->data){
          if(x->right== nullptr)
              x->right=newnode;
          else
              addhelper(x->right, val);
      }
  }
  t maxhelper(node<t>*x){
      if(x->right== nullptr)
          return x->data;
      else
          maxhelper(x->right);
  }
    t minhelper(node<t>*x){
        if(x->left== nullptr)
            return x->data;
        else
            minhelper(x->left);
    }
    int height(node<t>*x){
      if(x== nullptr)
          return -1;
      int lt= height(x->left);
      int rt=height(x->right);
      return max(lt+1, rt+1);
  }


  node<t>* removehelper(node<t>*x, t val){
      if(x== nullptr)
          return x;
      else if(val<x->data)
          x->left= removehelper(x->left, val);
      else if(val>x->data)
          x->right=removehelper(x->right, val);
      else{
          //has 1 or 0 child
          if(x->left== nullptr){
              node<t>*temp=x;
              x=x->right;
              delete temp;
          }
          else if(x->right == nullptr){
              node<t>*temp=x;
              x=x->left;
              delete temp;
          }
          else{
              t maxval= maxhelper(x->left);
              x->data=maxval;
              x->left= removehelper(x->left, maxval);
          }

      }
      return x;
  }
  int searchhelper(node<t>*x, t val){
      if(x== nullptr)
          return -1;
      else if(val<x->data)
          searchhelper(x->left, val);
      else if(val>x->data)
          searchhelper(x->right, val);
      else{
          return 1;
      }

  }

    void preorder(node<t>*x){
        if(x== nullptr)
            return;
        cout<<x->data<<" ";
        preorder(x->left);
        preorder(x->right);
    }
public:
    BST(){
        root= nullptr;
    }
    bool isempty(){
        return root == nullptr;
    }
    void insert (t val) {
        node<t> *newnode = new node(val);
        if (isempty()) {
            root = newnode;
            return;
        }
        node<t>*temp=root, *prev= nullptr;
        while(temp!= nullptr){
            prev=temp;
            if(val<=temp->data)
                temp=temp->left;
            else
                temp=temp->right;
        }
        if(val<=prev->data)
            prev->left=newnode;
        else
            prev->right=newnode;
    }
    void add(t val){
      if(root== nullptr){
          node<t>*newnode=new node(val);
          root=newnode;
          return;
      }
      addhelper(root,val);
  }
  t getmax(){
      return maxhelper(root);
  }
    t getmin(){
        return minhelper(root);
    }
  node<t>* remove(t val){
      root= removehelper(root, val);
      return root;
  }
  int getheight(){
      return height(root);
  }
  int search(t val){
      return searchhelper(root, val);
  }
  void display(){
      preorder(root);
      cout<<endl;
  }

};
template<typename t>
class AVL{
node<t>*root;
    int height(node<t>*x){
        if(x== nullptr)
            return -1;
        int lt= height(x->left);
        int rt=height(x->right);
        return max(lt+1, rt+1);
    }
    int getmax(node<t>*x){
        if(x->right== nullptr)
            return x->data;
        else{
            getmax(x->right);
        }
    }
    int getbalancefactor(node<t>*x){
        if(x== nullptr)
            return -1;
        else{
            return height(x->left)- height(x->right);
        }
    }
    node<t>* rightrotation(node<t>*x){
        node<t>*y=x->left;
        node<t>*temp=y->right;
        y->right=x;
        x->left=temp;
        return y;
    }
    node<t>* leftrotation(node<t>*x){
        node<t>*y=x->right;
        node<t>*temp=y->left;
        y->left=x;
        x->right=temp;
        return y;
    }
    node<t>* inserthelper(node<t>*x, t val){
        if(x== nullptr) {
            return (new node(val));
        }
        else if(val<=x->data)
            x->left= inserthelper(x->left, val);
        else if(val>x->data)
            x->right= inserthelper(x->right, val);

        int bf= getbalancefactor(x);

        if(bf>1&&val<x->left->data){
            return rightrotation(x);
        }
        else if(bf<-1&&val>x->right->data){
            return leftrotation(x);
        }
        else if(bf>1&&val>x->left->data){
            x->left= leftrotation(x->left);
            return rightrotation(x);
        }
        else if(bf<-1&&val<x->right->data){
            x->right= rightrotation(x->right);
            return leftrotation(x);
        }
        return x;
    }
    void preorder(node<t>*x){
        if(x== nullptr)
            return;
        cout<<x->data<<" ";
        preorder(x->left);
        preorder(x->right);
    }
    node<t>* removehelper(node<t>*x, t val){
        if(x== nullptr)
            return nullptr;
        else if(val<x->data)
            x->left= removehelper(x->left, val);
        else if(val>x->data)
            x->right= removehelper(x->right, val);
        else{
            if(x->left== nullptr){
                node<t>*r=x;
                x=x->right;
                delete r;
            }
            else if(x->right== nullptr){
                node<t>*r=x;
                x=x->left;
                delete r;
            }
            else{
                int maxval= getmax(x->left);
                x->data=maxval;
                x->left= removehelper(x->left,maxval);
            }
        }
       int bf= getbalancefactor(x);
        if(bf>1&&val<=x->left->data)
            return rightrotation(x);
        else if(bf<-1&&val>x->right->data)
            return leftrotation(x);
        else if(bf>1&&val>x->left->data){
            x->left= leftrotation(x->left);
            return rightrotation(x);
        }
        else if(bf<-1&&val<=x->right->data){
            x->right= rightrotation(x->right);
            return leftrotation(x);
        }
        return x;
    }
public:
    AVL(){
    root= nullptr;
    }
    bool isempty(){

        return root == nullptr;
    }
    void add(t val){
       root= inserthelper(root, val);
    }
    void display(){
        preorder(root);
        cout<<endl;
    }
    void remove(t val){
        root= removehelper(root,val);
    }
};
template<class t>
void maxheapify(vector<t>&v, int n, int rt){
    int l=rt*2+1, r=rt*2+2;
    int maxx=rt;
    if(l<n&&v[l]>v[maxx])
        maxx=l;
    if(r<n&&v[r]>v[maxx])
        maxx=r;
    if(maxx!=rt){
        swap(v[rt], v[maxx]);
        maxheapify(v,n,maxx);
    }
}
template<class t>
void buildmaxheapify(vector<t>&v, int n){
    for(int i=n/2-1; i>=0;i--){
        maxheapify(v,n,i);
    }
}
template<class t>
class heap{
    vector<t>v;
public:
    void add(t val){
        if(v.empty())
            v.push_back(val);
        else{
            v.push_back(val);
            buildmaxheapify(v,v.size());
        }
    }
    void remove(){
        if(!v.empty()){
            swap(v[0], v[v.size()-1]);
            v.pop_back();
            buildmaxheapify(v,v.size());
        }
        else{
            cout<<"it is empty!!\n";
        }
    }
    void display(){
        for (int i = 0; i < v.size(); ++i) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }


};

int main() {
    heap<int> b;
    b.add(30);
    b.add(35);
    b.add(40);
    b.add(20);
    b.add(10);
    b.add(50);
    b.add(15);
    b. remove();
    b. remove();
    b.display();

}
