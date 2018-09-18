void inOrder();
void inOrder(BinaryNode *t);

void inOrder(BinaryNode *t){
  if(t != nullptr){
    inOrder(t -> left, out);
    out << t-> element << ", ";;
    inOrder(t -> right, out);
  }

 void preOrder(BinaryNode *t){
   if(t != nullptr){
     out << t-> element << ", "
   }
 }
}
