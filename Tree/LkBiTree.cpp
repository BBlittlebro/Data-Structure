#include <iostream>
#include <queue>

template <typename Tt>
class LkBiTree{
public:
    struct BiNode{
        Tt data;
        BiNode *Lchild{0}, *Rchild{0};
    };
    BiNode *root;

    LkBiTree(){
        root = Preorder_Creat();
    /*
        root = new BiNode();   root->data = 'A';
        root->Lchild = new BiNode();   root->Lchild->data = 'B';
        root->Rchild = new BiNode();   root->Rchild->data = 'C';

        BiNode *P = root->Lchild;
        P->Lchild = new BiNode();   P->Lchild->data = 'D';
        P->Rchild = new BiNode();   P->Rchild->data = 'E';
    */
    }

    void Preorder_Traversal(BiNode *T){     //前序
        if(!T) return;
        std::cout << T->data;
        Preorder_Traversal(T->Lchild);
        Preorder_Traversal(T->Rchild);
    }
    void Inorder_Traversal(BiNode *T){      //中序
        if(!T) return;
        Inorder_Traversal(T->Lchild);
        std::cout << T->data;
        Inorder_Traversal(T->Rchild);
    }
    void Postorder_Traversal(BiNode *T){    //後序
        if(!T) return;
        Postorder_Traversal(T->Lchild);
        Postorder_Traversal(T->Rchild);
        std::cout << T->data;
    }
    void BFS(BiNode *T){
        std::queue<BiNode *> Q;
        Q.push(T);
        while(!Q.empty()){
            BiNode *temp = Q.front(); Q.pop();
            if(temp) std::cout << temp->data;

            if(temp->Lchild) Q.push(temp->Lchild);
            if(temp->Rchild) Q.push(temp->Rchild);
        }
    }
    void Preorder_Traversal(){
        Preorder_Traversal(root);
    }
    void Inorder_Traversal(){
        Inorder_Traversal(root);
    }
    void Postorder_Traversal(){
        Postorder_Traversal(root);
    }
    void BFS(){
        BFS(root);
    }
    int Depth(BiNode *T){
        if(!T) return 0;

        int l = Depth(T->Lchild);
        int r = Depth(T->Rchild);
        return l > r ? l+1 : r+1;
    }
    int Depth(){
        return Depth(root);
    }
    int Count(BiNode *T){
        if(!T) return 0;

        int l = Count(T->Lchild);
        int r = Count(T->Rchild);
        if(!T->Lchild && !T->Rchild)
            return l + r + 1;
        else
            return l + r;
    }
    int Count(){
        return Count(root);
    }
    BiNode * Preorder_Creat(){     //前序
        Tt e;
        std::cin >> e;
        if(e == '#') return 0;
        BiNode *p = new BiNode();
        p->data = e;

        p->Lchild = Preorder_Creat();
        p->Rchild = Preorder_Creat();
        return p;
    }
};


int main(){

    LkBiTree<char> tree;

    std::cout << "Preorder: "; tree.Preorder_Traversal(); std::cout << std::endl;
    std::cout << "Inorder: "; tree.Inorder_Traversal(); std::cout << std::endl;
    std::cout << "Postorder: "; tree.Postorder_Traversal(); std::cout << std::endl;
    
    std::cout << "BFS: "; tree.BFS(); std::cout << std::endl;
    std::cout << "Depth: " << tree.Depth() << std::endl;
    std::cout << "Leaf: " << tree.Count() << std::endl;
    return 0;
}