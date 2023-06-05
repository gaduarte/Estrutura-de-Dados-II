#include <queue>
#include <iostream>

using namespace std;


template<class T>
class ArvoreNo {
	public:
		T el;
		ArvoreNo<T> *left,*right;
        bool sucessor;
		ArvoreNo(){
			left=right=0;
		}
		ArvoreNo(T e,ArvoreNo<T> *l=0,ArvoreNo<T> *r=0){
			el=e;
			left=l;
			right=r;
			sucessor = false;
		}
};

template<class T>
class Arvore {
	protected:
		ArvoreNo<T> *root;
	public:
		Arvore(){
			root = 0;
		}
		~Arvore(){
			clear();
		}
		void clear(){
			clear(root);
			root=0;
		}

		ArvoreNo<T>* getRoot(){
			return root;
		}
		bool isEmpty() const {
		   return root=0;
		   }

		void visit(ArvoreNo<T> *p){
			cout<<p->el<<" ";
		}

		T search(T el) {
			ArvoreNo<T> *p=root;
			while (p!=0){

				if (el==p->el)
					return p->el;
				else{
					if (el < p->el)
				       p=p->left;
				   else p=p->right;
			 	}
		    }
			return 0;

		}
		 //obs: pg 209 figura 6.23
		void insert(T el){
			ArvoreNo<T> *p=root,*prev=0;
			while (p!=0){
				prev=p;
				if (el<p->el)
					p=p->left;
				else p=p->right;
			}
			if (root==0) //a arvore esta vazia
			   root=new ArvoreNo<T>(el);
			else if (el < prev->el)
				prev->left=new ArvoreNo<T>(el);
			else prev->right=new ArvoreNo<T>(el);

			}

		void percusoExtensao(){
			queue<ArvoreNo<T>*> f;
			ArvoreNo<T> *p=root;
			if (p!=NULL){
				f.push(p);
				while (!f.empty()){
					p=f.front();
					visit(p);
					f.pop();
					if (p->left!=0)
						f.push(p->left);
					if (p->right!=0)
						f.push(p->right);
				}	}
		}


		void preorder(ArvoreNo<T> *p){
			if (p!=0) {
				visit(p);
				preorder(p->left);
				preorder(p->right);
			}

		}


     void rotateLeft() {
           ArvoreNo<T> temp = root;
           ArvoreNo<T> par = temp->left;
           ArvoreNo<T> prox = par->right;
           ArvoreNo<T> subD;
            par = temp->left;

            temp->left = prox;
            subD = prox->left;
            par->right = subD;
            prox->left = par;
        }


      void rotateRight() {
            ArvoreNo<T> temp = root;
            ArvoreNo<T> par = temp->right;
            ArvoreNo<T> prox = par->left;
            ArvoreNo<T> subD;
            par = temp->right;

            temp->right = prox;
            subD = prox->right;
            par->left = subD;
            prox->right = par;
        }

		   void backbone(ArvoreNo<T> *p) {
          ArvoreNo<T> *curr = p;
          ArvoreNo<T> *prev = nullptr;
          ArvoreNo<T> *tmp = nullptr;

          while (curr != nullptr) {
              if (curr->left != nullptr) {
                  tmp = curr->left;
                  curr->left = tmp->right;
                  tmp->right = curr;
                  curr = tmp;

              } else {
                  curr = curr->right;
              }

              if (prev != nullptr) {
                  prev->right = curr;
              } else {
                  p = curr;
              }

              prev = curr;
          }
}



};


int main(){

	Arvore<int> *a=new Arvore<int>();

	a->insert(7);
	a->insert(22);
	a->insert(14);
	a->insert(40);
	a->insert(30);
	a->insert(63);
	a->insert(80);


	a->preorder(a->getRoot());




	cout<<"---Apos as rotacoes -----"<<endl;
	a->preorder(a->getRoot());



}

/*
Árvore Resultante:
    7
     \
      22
     /   \
    14   40
         /  \
        30  63
             \
              80
 Altura: 4.
 A árvore não está balanceada.
 Árvore após o alinhamento:
   7
   \
    14
     \
      22
       \
        30
         \
          40
           \
            63
             \
              80

*/
